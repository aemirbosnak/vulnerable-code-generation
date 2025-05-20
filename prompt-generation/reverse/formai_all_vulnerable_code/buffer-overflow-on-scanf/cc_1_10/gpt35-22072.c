//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
};

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to Expense Tracker!\n\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdding Expense\n");

                if (numExpenses > MAX_EXPENSES) {
                    printf("Cannot add more than %d expenses.\n\n", MAX_EXPENSES);
                    break;
                }

                struct Expense newExpense;

                printf("Enter expense name: ");
                fgets(newExpense.name, sizeof(newExpense.name), stdin);

                printf("Enter amount: ");
                scanf("%f", &newExpense.amount);

                expenses[numExpenses] = newExpense;
                numExpenses++;

                printf("Expense added successfully.\n\n");
                break;

            case 2:
                printf("\nViewing Expenses\n");

                if (numExpenses == 0) {
                    printf("There are no expenses to view.\n\n");
                    break;
                }

                printf("Expenses:\n\n");

                for (int i = 0; i < numExpenses; i++) {
                    printf("%d. %s - $%.2f\n", i+1, expenses[i].name, expenses[i].amount);
                }

                printf("\n");
                break;

            case 3:
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}