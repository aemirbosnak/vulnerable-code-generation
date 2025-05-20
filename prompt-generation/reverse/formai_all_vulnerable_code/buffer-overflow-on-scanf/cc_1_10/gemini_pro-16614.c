//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
// Celestial Savings: A Personal Finance Planner Odyssey

#include <stdio.h>
#include <stdlib.h>

// Galactic Income and Expenses
typedef struct {
    float income;
    float expenses;
} StellarSurplus;

// Budgetary Constellation
typedef struct {
    StellarSurplus saturn;
    StellarSurplus venus;
    StellarSurplus mercury;
} CosmicCashFlow;

// Initialize the Celestial Savings Universe
CosmicCashFlow universe;

// Galactic Income and Expenses Data
void celestialData() {
    printf("Enter Saturnian Income: $");
    scanf("%f", &universe.saturn.income);

    printf("Enter Saturnian Expenses: $");
    scanf("%f", &universe.saturn.expenses);

    printf("Enter Venusian Income: $");
    scanf("%f", &universe.venus.income);

    printf("Enter Venusian Expenses: $");
    scanf("%f", &universe.venus.expenses);

    printf("Enter Mercurial Income: $");
    scanf("%f", &universe.mercury.income);

    printf("Enter Mercurial Expenses: $");
    scanf("%f", &universe.mercury.expenses);
}

// Calculate Galactic Surplus
void surplusStargazing() {
    universe.saturn.income -= universe.saturn.expenses;
    universe.venus.income -= universe.venus.expenses;
    universe.mercury.income -= universe.mercury.expenses;
}

// Display Interplanetary Financial Forecast
void cosmicConsole() {
    printf("Saturnian Surplus: $%.2f\n", universe.saturn.income);
    printf("Venusian Surplus: $%.2f\n", universe.venus.income);
    printf("Mercurial Surplus: $%.2f\n", universe.mercury.income);
}

// Celestial Financial Navigator
int main() {
    printf("Welcome to Celestial Savings!\n");
    celestialData();
    surplusStargazing();
    cosmicConsole();

    return 0;
}