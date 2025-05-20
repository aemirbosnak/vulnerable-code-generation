//FormAI DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold each expense item's data
typedef struct expense {
    char category[20];
    float amount;
    char date[11];
} Expense;

int main() {
    int numExpenses = 0;
    Expense* expenses = NULL;

    while (1) {
        printf("1. Add expense\n2. View expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                numExpenses++;
                expenses = (Expense*) realloc(expenses, numExpenses * sizeof(Expense));

                printf("Enter category: ");
                scanf("%s", expenses[numExpenses-1].category);

                printf("Enter amount: ");
                scanf("%f", &expenses[numExpenses-1].amount);

                printf("Enter date (yyyy-mm-dd): ");
                scanf("%s", expenses[numExpenses-1].date);

                break;
            }

            case 2: {
                if (numExpenses == 0) {
                    printf("No expenses added yet.\n");
                    break;
                }

                printf("Category\tAmount\tDate\n");
                for (int i = 0; i < numExpenses; i++) {
                    printf("%s\t\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                }

                break;
            }

            case 3: {
                printf("Exiting program.\n");
                free(expenses);
                return 0;
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}