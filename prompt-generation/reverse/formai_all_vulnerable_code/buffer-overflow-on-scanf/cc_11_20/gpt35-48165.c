//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while(1) {
        char option;

        printf("\nWelcome to the Expense Tracker!\n");
        printf("1 - Add an expense\n");
        printf("2 - View all expenses\n");
        printf("3 - Total expenses\n");
        printf("4 - Exit\n");
        printf("Enter an option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1': {
                if(numExpenses == MAX_EXPENSES) {
                    printf("Max number of expenses reached!\n");
                    break;
                }

                Expense newExpense;
                printf("\nEnter a description for the expense: ");
                scanf(" %[^\n]", newExpense.description);

                printf("Enter the amount for the expense: ");
                scanf(" %f", &newExpense.amount);

                expenses[numExpenses] = newExpense;
                numExpenses++;

                printf("\nExpense added successfully!\n");
                break;
            }
            case '2': {
                if(numExpenses == 0) {
                    printf("\nThere are no expenses to display!\n");
                    break;
                }

                printf("\n======= ALL EXPENSES =======\n");

                for(int i = 0; i < numExpenses; i++) {
                    Expense expense = expenses[i];
                    printf("%d - %s ($%.2f)\n", i+1, expense.description, expense.amount);
                }
                break;
            }
            case '3': {
                if(numExpenses == 0) {
                    printf("\nThere are no expenses to total!\n");
                    break;
                }

                float total = 0;

                for(int i = 0; i < numExpenses; i++) {
                    Expense expense = expenses[i];
                    total += expense.amount;
                }

                printf("\n======= TOTAL EXPENSES =======\n");
                printf("Total expenses: $%.2f\n", total);
                break;
            }
            case '4': {
                printf("\nExiting Expense Tracker. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid option. Please try again.\n");
            }
        }
    }

    return 0;
}