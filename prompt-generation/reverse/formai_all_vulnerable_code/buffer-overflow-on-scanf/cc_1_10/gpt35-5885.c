//FormAI DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // maximum number of expenses

struct Expense {
    char description[50];
    double amount;
};

int main() {
    struct Expense expenses[MAX_EXPENSES]; // array to hold expenses
    int numExpenses = 0; // keep track of number of expenses
    char choice; // menu choice variable

    printf("Welcome to the Expense Tracker\n");

    while (1) {
        // print menu options
        printf("\nPlease choose an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");

        // read user choice
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                // add expense
                struct Expense e;

                printf("\nEnter expense description: ");
                scanf("%s", e.description);

                printf("Enter expense amount: $");
                scanf("%lf", &e.amount);

                expenses[numExpenses++] = e; // add expense to array

                printf("Expense added succesfully.\n");
                break;
            }
            case '2': {
                // view expenses
                if (numExpenses == 0) {
                    printf("\nNo expenses to show.\n");
                } else {
                    printf("\nExpenses:\n");
                    printf("%-20s $%-20s\n", "Description", "Amount");

                    // loop through expenses and print them out
                    for (int i = 0; i < numExpenses; i++) {
                        printf("%-20s $%-20.2f\n", expenses[i].description, expenses[i].amount);
                    }
                }
                break;
            }
            case '3': {
                // exit
                printf("\nExiting...\n");
                exit(0);
                break;
            }
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}