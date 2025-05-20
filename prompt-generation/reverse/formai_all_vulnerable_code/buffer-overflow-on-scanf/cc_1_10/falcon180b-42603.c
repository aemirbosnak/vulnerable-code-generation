//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    double balance = 1000.00;
    double income = 0.00;
    double expense = 0.00;
    double saving = 0.00;
    double budget = 0.00;
    double percentage = 0.00;
    double total_budget = 0.00;
    double total_expense = 0.00;
    double total_saving = 0.00;

    // Menu
    printf("\n\nPersonal Finance Planner\n\n");
    printf("1. Income\n");
    printf("2. Expense\n");
    printf("3. Saving\n");
    printf("4. Budget\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    // Income
    if (choice == 1) {
        printf("\nEnter your income: ");
        scanf("%lf", &income);
        balance += income;
        printf("\nYour current balance is: $%.2f\n", balance);
    }

    // Expense
    else if (choice == 2) {
        printf("\nEnter your expense: ");
        scanf("%lf", &expense);
        balance -= expense;
        printf("\nYour current balance is: $%.2f\n", balance);
    }

    // Saving
    else if (choice == 3) {
        printf("\nEnter your saving: ");
        scanf("%lf", &saving);
        balance += saving;
        printf("\nYour current balance is: $%.2f\n", balance);
    }

    // Budget
    else if (choice == 4) {
        printf("\nEnter your budget: ");
        scanf("%lf", &budget);
        total_budget += budget;
        total_expense += expense;
        total_saving += saving;
        percentage = ((total_expense + total_saving) / total_budget) * 100;
        printf("\nYour budget percentage is: %.2f%%\n", percentage);
    }

    // Exit
    else if (choice == 5) {
        exit(0);
    }

    // Invalid choice
    else {
        printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}