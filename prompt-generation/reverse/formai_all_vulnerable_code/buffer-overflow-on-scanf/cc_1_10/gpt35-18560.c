//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

int expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense(int amount) {
    if (numExpenses == MAX_EXPENSES) {
        printf("Error: Max expenses reached\n");
        return;
    }
    expenses[numExpenses++] = amount;
    printf("Added $%d to expenses\n", amount);
}

void printExpenses() {
    printf("Expenses:\n");
    int total = 0;
    for (int i = 0; i < numExpenses; i++) {
        printf("$%d\n", expenses[i]);
        total += expenses[i];
    }
    printf("Total expenses: $%d\n", total);
}

int main() {
    int choice, amount;
    while (1) {
        printf("\nExpense Tracker:\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter amount: ");
                scanf("%d", &amount);
                addExpense(amount);
                break;
            case 2:
                printExpenses();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}