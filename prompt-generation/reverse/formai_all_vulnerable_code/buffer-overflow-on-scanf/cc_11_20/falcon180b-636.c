//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense;

int main() {
    int num_expenses;
    expense expenses[MAX_EXPENSES];

    printf("Welcome to Personal Finance Planner!\n\n");
    printf("How many expenses would you like to track? ");
    scanf("%d", &num_expenses);

    // Get user input for each expense
    for (int i = 0; i < num_expenses; i++) {
        printf("\nExpense %d:\n", i+1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: ");
        scanf("%s", expenses[i].amount);
    }

    // Calculate total expenses
    double total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += atof(expenses[i].amount);
    }

    // Print summary
    printf("\nSummary:\n");
    printf("Total Expenses: $%.2f\n", total_expenses);

    // Allow user to add or remove expenses
    char choice;
    while (1) {
        printf("\nWould you like to add or remove an expense? (a/r) ");
        scanf(" %c", &choice);
        if (choice == 'a' || choice == 'A') {
            // Add expense
            printf("\nEnter expense name: ");
            scanf("%s", expenses[num_expenses].name);
            printf("Enter expense amount: ");
            scanf("%s", expenses[num_expenses].amount);
            num_expenses++;
        } else if (choice == 'r' || choice == 'R') {
            // Remove expense
            printf("\nEnter expense number to remove: ");
            int expense_num;
            scanf("%d", &expense_num);
            if (expense_num >= 1 && expense_num <= num_expenses) {
                for (int i = expense_num-1; i < num_expenses-1; i++) {
                    strcpy(expenses[i].name, expenses[i+1].name);
                    strcpy(expenses[i].amount, expenses[i+1].amount);
                }
                num_expenses--;
            } else {
                printf("Invalid expense number.\n");
            }
        } else {
            // Invalid choice
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}