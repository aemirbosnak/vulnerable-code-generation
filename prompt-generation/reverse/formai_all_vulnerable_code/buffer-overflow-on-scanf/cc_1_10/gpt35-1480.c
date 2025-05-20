//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LEN 50
#define MAX_EXPENSES 100

typedef struct {
    char description[MAX_DESCRIPTION_LEN+1];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;
    do {
        printf("\nExpense Tracker\n");
        printf("----------------\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                if (numExpenses == MAX_EXPENSES) {
                    printf("\nMaximum number of expenses reached!\n");
                    break;
                }
                Expense expense;
                printf("\nEnter description (up to %d characters): ", MAX_DESCRIPTION_LEN);
                scanf(" %[^\n]s", expense.description);
                printf("Enter amount: ");
                scanf("%f", &expense.amount);
                expenses[numExpenses++] = expense;
                printf("\nExpense added successfully!\n");
                break;
            case '2':
                if (numExpenses == 0) {
                    printf("\nNo expenses to show!\n");
                    break;
                }
                printf("\nExpenses:\n");
                printf("Description\tAmount\n");
                printf("-----------\t------\n");
                for (int i = 0; i < numExpenses; i++) {
                    Expense expense = expenses[i];
                    printf("%s\t%.2f\n", expense.description, expense.amount);
                }
                break;
            case '3':
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != '3');
    return 0;
}