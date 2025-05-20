//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];

    while (1) {
        printf("\nEnter 1 to add an expense, 2 to view expenses, 3 to search expenses, 0 to quit:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            if (numExpenses >= MAX_EXPENSES) {
                printf("Maximum number of expenses reached.\n");
            } else {
                printf("Enter expense name: ");
                scanf("%s", expenses[numExpenses].name);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[numExpenses].amount);
                printf("Enter expense category: ");
                scanf("%s", expenses[numExpenses].category);
                numExpenses++;
            }
            break;
        }
        case 2: {
            if (numExpenses == 0) {
                printf("No expenses added yet.\n");
            } else {
                printf("\nExpense Name\tExpense Amount\tExpense Category\n");
                for (int i = 0; i < numExpenses; i++) {
                    printf("%s\t\t%.2f\t\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                }
            }
            break;
        }
        case 3: {
            printf("Enter expense name to search: ");
            char searchName[50];
            scanf("%s", searchName);

            int found = 0;
            for (int i = 0; i < numExpenses; i++) {
                if (strcmp(expenses[i].name, searchName) == 0) {
                    printf("\nExpense Name: %s\nExpense Amount: %.2f\nExpense Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Expense not found.\n");
            }

            break;
        }
        case 0: {
            printf("Exiting program...\n");
            exit(0);
        }
        default: {
            printf("Invalid choice. Please try again.\n");
        }
        }
    }

    return 0;
}