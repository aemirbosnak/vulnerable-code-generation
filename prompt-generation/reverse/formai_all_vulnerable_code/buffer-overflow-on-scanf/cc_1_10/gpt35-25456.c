//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct Expense {
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
    char date[11];
} Expense;

int main(void) {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;

    do {
        printf("\nExpense Tracker\n\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n\n");
        printf("Enter choice (1-3): ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_expenses < MAX_EXPENSES) {
                    printf("\nEnter expense date (mm/dd/yyyy): ");
                    scanf("%s", expenses[num_expenses].date);
                    printf("Enter expense amount: ");
                    scanf("%f", &expenses[num_expenses].amount);
                    printf("Enter expense description: ");
                    scanf(" %[^\n]s", expenses[num_expenses].description);
                    num_expenses++;
                } else {
                    printf("\nMaximum number of expenses reached!\n");
                }
                break;

            case '2':
                if (num_expenses > 0) {
                    float total = 0;
                    printf("\nExpenses:\n\n");
                    printf("| %-12s | %-10s | %-30s |\n",
                        "Date", "Amount", "Description");
                    printf("+--------------+------------+------------------------------+\n");
                    for (int i = 0; i < num_expenses; i++) {
                        printf("| %-12s | $%-9.2f | %-30s |\n",
                            expenses[i].date, expenses[i].amount, expenses[i].description);
                        total += expenses[i].amount;
                    }
                    printf("+--------------+------------+------------------------------+\n");
                    printf("| %-23s | $%-9.2f |\n", "Total", total);
                    printf("+---------------------------+------------+\n");
                } else {
                    printf("\nNo expenses added yet!\n");
                }
                break;

            case '3':
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }

        // clear input buffer
        while ((choice = getchar()) != '\n' && choice != EOF);

    } while (choice != '3');

    return 0;
}