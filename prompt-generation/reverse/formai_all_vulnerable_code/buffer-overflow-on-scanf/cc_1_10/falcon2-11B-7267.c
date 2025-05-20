//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>

int main() {
    int income, expense, net_income;
    int months = 0;
    int year = 0;

    // Prompt the user to enter their income
    printf("Enter your income for the month: ");
    scanf("%d", &income);

    // Prompt the user to enter their expenses
    printf("Enter your expenses for the month: ");
    scanf("%d", &expense);

    // Calculate the net income for the month
    net_income = income - expense;

    // Display the net income for the month
    printf("Your net income for the month is $%.2f\n", net_income);

    // Prompt the user to enter the number of months they want to track
    printf("How many months would you like to track? ");
    scanf("%d", &months);

    // Prompt the user to enter the number of years they want to track
    printf("How many years would you like to track? ");
    scanf("%d", &year);

    // Loop through each month and calculate the net income for the year
    for (int i = 0; i < months; i++) {
        printf("Enter your income for month %d: ", i + 1);
        scanf("%d", &income);

        printf("Enter your expenses for month %d: ", i + 1);
        scanf("%d", &expense);

        net_income = income - expense;

        printf("Your net income for month %d is $%.2f\n", i + 1, net_income);
    }

    // Calculate the net income for the entire year
    net_income = income - expense;

    // Display the net income for the entire year
    printf("Your net income for the year is $%.2f\n", net_income);

    return 0;
}