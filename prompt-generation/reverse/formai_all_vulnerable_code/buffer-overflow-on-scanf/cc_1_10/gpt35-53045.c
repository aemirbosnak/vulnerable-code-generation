//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum budget
#define MAX_BUDGET 1000000

// Define the maximum length of expense description
#define MAX_DESC_LEN 50

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure to hold an expense record
struct Expense {
    char description[MAX_DESC_LEN];
    double amount;
    char category[MAX_DESC_LEN];
};

// Define the function to take input from user for an expense and save it to an Expense struct
void addExpense(struct Expense *expenses, int *numExpenses) {
    char input[MAX_DESC_LEN];
    double amount;

    printf("Enter expense description (up to %d characters): ", MAX_DESC_LEN);
    fgets(input, MAX_DESC_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    strncpy(expenses[*numExpenses].description, input, MAX_DESC_LEN);

    printf("Enter amount (in USD): ");
    scanf("%lf", &amount);
    expenses[*numExpenses].amount = amount;

    printf("Enter category (up to %d characters): ", MAX_DESC_LEN);
    getchar(); // consume the newline character left by scanf
    fgets(input, MAX_DESC_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    strncpy(expenses[*numExpenses].category, input, MAX_DESC_LEN);

    *numExpenses = *numExpenses + 1;
}

// Define the function to display the expenses added so far
void displayExpenses(struct Expense *expenses, int numExpenses) {
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    double totalExpenseAmount = 0;

    while (1) {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                totalExpenseAmount = totalExpenseAmount + expenses[numExpenses-1].amount;
                if (totalExpenseAmount > MAX_BUDGET) {
                    printf("\n**** WARNING: Total expense amount exceeds maximum budget ($%d)! ****\n", MAX_BUDGET);
                }
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                printf("Total expenses: $%.2f\n", totalExpenseAmount);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}