//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float amount;
    char date[15];
};

int main() {
    int choice, numExpenses = 0;
    float totalExpenses = 0.0;
    struct expense expenses[100];

    while (1) {
        // displaying the menu
        printf("\nEXPENSE TRACKER\n");
        printf("1. Add an expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // adding an expense
                printf("\nEnter the expense category: ");
                scanf("%s", expenses[numExpenses].category);

                printf("Enter the amount spent: ");
                scanf("%f", &expenses[numExpenses].amount);

                printf("Enter the date (DD/MM/YYYY): ");
                scanf("%s", expenses[numExpenses].date);

                totalExpenses += expenses[numExpenses].amount; // updating total expenses
                numExpenses++; // incrementing number of expenses
                printf("\nExpense added successfully!\n");
                break;
            }

            case 2: { // viewing expenses
                if (numExpenses == 0) {
                    printf("\nNo expenses added yet!\n");
                }
                else {
                    printf("\nEXPENSES\n");
                    printf("--------------------------------------------------\n");
                    printf("| %-20s | %-10s | %-15s |\n", "CATEGORY", "AMOUNT", "DATE");
                    printf("--------------------------------------------------\n");
                    for (int i = 0; i < numExpenses; i++) {
                        printf("| %-20s | %-10.2f | %-15s |\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                    }
                    printf("--------------------------------------------------\n");
                    printf("Total expenses: %.2f\n", totalExpenses);
                }
                break;
            }

            case 3: { // exiting the program
                printf("\nThank you for using the Expense Tracker!\n");
                exit(0);
            }

            default: {
                printf("\nInvalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}