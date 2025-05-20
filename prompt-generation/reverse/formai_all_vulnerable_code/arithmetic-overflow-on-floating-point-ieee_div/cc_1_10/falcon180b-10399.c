//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum length for strings
#define MAX_LENGTH 100

// Define structure for personal finance data
typedef struct {
    char name[MAX_LENGTH];
    float income;
    float expenses;
    float savings;
} FinanceData;

// Function to read input from user
void readInput(FinanceData *data) {
    printf("Enter your name: ");
    scanf("%s", data->name);

    printf("Enter your monthly income: ");
    scanf("%f", &data->income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &data->expenses);

    printf("Enter your monthly savings: ");
    scanf("%f", &data->savings);
}

// Function to calculate and display personal finance summary
void displaySummary(FinanceData data) {
    printf("\nPersonal Finance Summary\n");
    printf("-------------------------\n");
    printf("Name: %s\n", data.name);
    printf("Monthly Income: $%.2f\n", data.income);
    printf("Monthly Expenses: $%.2f\n", data.expenses);
    printf("Monthly Savings: $%.2f\n", data.savings);

    float netIncome = data.income - data.expenses;
    if (netIncome > 0) {
        printf("Net Income: $%.2f\n", netIncome);
    } else {
        printf("Net Income: -$%.2f\n", abs(netIncome));
    }

    float savingsPercentage = (data.savings / data.income) * 100;
    printf("Savings Percentage: %.2f%%\n", savingsPercentage);

    if (savingsPercentage >= 20) {
        printf("You are saving enough for your future!\n");
    } else {
        printf("You need to save more for your future.\n");
    }
}

// Main function
int main() {
    FinanceData data;
    readInput(&data);
    displaySummary(data);

    return 0;
}