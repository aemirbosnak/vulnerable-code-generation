//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(char *desc, float amt) {
    if (num_expenses < MAX_EXPENSES) {
        strcpy(expenses[num_expenses].description, desc);
        expenses[num_expenses].amount = amt;
        num_expenses++;
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}

void print_expenses() {
    if (num_expenses > 0) {
        printf("\nExpenses:\n");
        for (int i = 0; i < num_expenses; i++) {
            printf("%s: %.2f\n", expenses[i].description, expenses[i].amount);
        }
    } else {
        printf("No expenses recorded yet.\n");
    }
}

int main() {
    char desc[50];
    float amt;
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf("%s", desc);
                printf("Enter expense amount: ");
                scanf("%f", &amt);
                add_expense(desc, amt);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}