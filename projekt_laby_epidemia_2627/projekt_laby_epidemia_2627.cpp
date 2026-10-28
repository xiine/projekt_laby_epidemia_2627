#include <iostream>
#include <cmath>

using namespace std;

// Współczynniki
double infectionRate = 0.20;
double recoveryRate = 0.10;

// Zmienne
int day = 0;
int susceptible = 80;
int infected = 10;
int recovered = 10;


// Funkcje
void showPopulation(int _day, int _susceptible, int _infected, int _recovered);
void simulateDay();
bool checkPopulation(int _susceptible, int _infected, int _recovered);
void updateParameters();

int main()
{
    
    int menuOption;

    bool isRunning = true;

    while (isRunning) {
        showPopulation(day, susceptible, infected, recovered);
        cout << "=== Epidemic Simulator ===\n"
            << "1.Simulate next day\n"
            << "2.Change model parameters\n"
            << "3.Exit\n"
            << "Your choice: ";

        cin >> menuOption;

        switch (menuOption) {
            case 1:
                simulateDay();
                break;
            case 2:
                updateParameters();
                break;
            case 3:
                cout << "Exiting program...";
                isRunning = false;
                break;
            default:
                cout << "Invalid menu option!" << endl;
                break;
        }
    }
    
}

void showPopulation(int _day, int _susceptible, int _infected, int _recovered) {
    cout << "Day: " << _day << "\n"  
        << "Susceptible: " << _susceptible << "\n"
        << "Infected: " << _infected << "\n"
        << "Recovered: " << _recovered << "\n"
        << "Total: " << _susceptible + _infected + _recovered << endl;
}

void simulateDay() {
    int infectedAtStart = infected;

    int newInfections = floor(infectionRate * infectedAtStart);
    int newRecoveries = floor(infectedAtStart * recoveryRate);

    if (newInfections > susceptible) { newInfections = susceptible; }

    if (newRecoveries > infectedAtStart) { newRecoveries = infectedAtStart; }

    susceptible -= newInfections;
    infected += newInfections - newRecoveries;
    recovered += newRecoveries;
    day++;
}

bool checkPopulation(int _susceptible, int _infected, int _recovered) {
    if (_susceptible < 0 || _infected < 0 || _recovered < 0) return false;
    if ((_susceptible + _infected + _recovered) != 100) return false;
    return true;
}

void updateParameters() {
    double tmpInfectionRate, tmpRecoveryRate;
    cout << "Enter infection rate (0-1): ";
    cin >> tmpInfectionRate;
    cout << "Enter recovery rate (0-1): ";
    cin >> tmpRecoveryRate;

    if (tmpInfectionRate > 1.0 || tmpInfectionRate < 0.0) { cout << "Infection rate needs to be >= 0 and <= 1" << endl; }
    else if (tmpRecoveryRate > 1.0 || tmpRecoveryRate < 0.0) { cout << "Recovery rate needs to be >= 0 and <= 1" << endl; }
    else {
        infectionRate = tmpInfectionRate;
        recoveryRate = tmpRecoveryRate;
        cout << "Parameters updated." << endl; 
    }
    
    
}