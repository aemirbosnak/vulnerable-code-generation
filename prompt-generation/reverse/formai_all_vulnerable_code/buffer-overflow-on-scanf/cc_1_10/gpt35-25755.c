//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define MAX_EXPENSES 1000

typedef struct {
    char date[MAX_LEN];
    char item[MAX_LEN];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("\n\tEXPENSE TRACKER\n");
        printf("\n1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the date (DD/MM/YYYY): ");
                scanf("%s", expenses[num_expenses].date);

                printf("Enter the item: ");
                scanf("%s", expenses[num_expenses].item);

                printf("Enter the amount: ");
                scanf("%f", &expenses[num_expenses].amount);

                num_expenses++;

                printf("\nExpense added successfully!\n");

                break;

            case 2:
                if (num_expenses == 0) {
                    printf("\nNo expenses added yet.\n");
                    break;
                }

                printf("\n\tEXPENSES\n");

                printf("%-15s %-15s %-15s\n", "Date", "Item", "Amount");

                for (int i = 0; i < num_expenses; i++) {
                    printf("%-15s %-15s %-15.2f\n", expenses[i].date, expenses[i].item, expenses[i].amount);
                }

                break;

            case 3:
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}