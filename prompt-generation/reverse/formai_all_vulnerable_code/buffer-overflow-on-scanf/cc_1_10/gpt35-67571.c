//FormAI DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct expense {
    char name[30];
    float amount;
} Expense;

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];

    printf("Welcome to the puzzling expense tracker. What would you like to do?\n");

    while(1) {
        printf("\n1. Add an expense\n2. View all expenses\n3. Calculate total expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch(choice) {
            case 1: {
                printf("\nEnter expense name: ");
                char name[30];
                fgets(name, 30, stdin);
                // remove trailing newline character
                name[strcspn(name, "\n")] = 0;

                printf("Enter expense amount: ");
                float amount;
                scanf("%f", &amount);
                getchar(); // consume newline character

                Expense newExpense;
                strcpy(newExpense.name, name);
                newExpense.amount = amount;
                expenses[numExpenses++] = newExpense;

                printf("\nExpense added successfully!\n");
                break;
            }
            case 2: {
                printf("\nAll expenses:\n");
                for(int i=0; i<numExpenses; i++) {
                    printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
                }
                break;
            }
            case 3: {
                float total = 0;
                for(int i=0; i<numExpenses; i++) {
                    total += expenses[i].amount;
                }
                printf("\nTotal expenses: $%.2f\n", total);
                break;
            }
            case 4: {
                printf("\nGoodbye!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Try again.\n");
            }
        }
    }

    return 0;
}