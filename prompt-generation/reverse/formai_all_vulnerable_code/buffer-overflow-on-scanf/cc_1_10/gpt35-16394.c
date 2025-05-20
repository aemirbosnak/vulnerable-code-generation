//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char description[50];
    float amount;
};

void addExpense(struct expense* expenses, int* numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    struct expense newExpense;

    printf("Enter expense description: ");
    fgets(newExpense.description, sizeof(newExpense.description), stdin);

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    getchar(); // Clear the input buffer

    expenses[*numExpenses] = newExpense;
    *numExpenses += 1;

    printf("Expense added successfully.\n");
}

void listExpenses(struct expense* expenses, int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Expenses:\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void getTotalExpense(struct expense* expenses, int numExpenses) {
    float total = 0;

    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    printf("Total expense: $%.2f\n", total);
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while (1) {
        printf("Expense Tracker Main Menu:\n");
        printf("1. Add expense\n");
        printf("2. List expenses\n");
        printf("3. Get total expense\n");
        printf("4. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the input buffer

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                listExpenses(expenses, numExpenses);
                break;
            case 3:
                getTotalExpense(expenses, numExpenses);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n"); // Add a newline after each menu
    }

    return 0;
}