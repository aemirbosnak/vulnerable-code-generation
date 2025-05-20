//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to validate input
int isValidInput(char* input) {
    int length = strlen(input);
    for(int i=0; i<length; i++) {
        if(!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

//Function to calculate monthly savings
double calculateMonthlySavings(double income, double expenses) {
    double savings = income - expenses;
    return savings;
}

//Function to calculate total savings
double calculateTotalSavings(double monthlySavings, int months) {
    double totalSavings = monthlySavings * months;
    return totalSavings;
}

//Function to calculate interest earned
double calculateInterestEarned(double totalSavings, double interestRate, int months) {
    double interestEarned = (totalSavings * interestRate) / 1200;
    return interestEarned;
}

//Main function
int main() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    double income, expenses;
    printf("Enter your monthly income: ");
    scanf("%lf", &income);

    printf("Enter your monthly expenses: ");
    scanf("%lf", &expenses);

    int months;
    printf("Enter number of months to save: ");
    scanf("%d", &months);

    double monthlySavings = calculateMonthlySavings(income, expenses);
    double totalSavings = calculateTotalSavings(monthlySavings, months);
    double interestRate = 0.05;
    double interestEarned = calculateInterestEarned(totalSavings, interestRate, months);

    printf("\nMonthly Savings: $%.2f\n", monthlySavings);
    printf("Total Savings: $%.2f\n", totalSavings);
    printf("Interest Earned: $%.2f\n", interestEarned);

    return 0;
}