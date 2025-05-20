//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
// Personal Finance Planner example program
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

// Structure for expense data
struct Expense {
    char name[100];
    double amount;
};

// Function to add a new expense
void addExpense(struct Expense expenses[], int *numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*numExpenses].amount);

    (*numExpenses)++;
}

// Function to print all expenses
void printExpenses(struct Expense expenses[], int numExpenses) {
    printf("Expenses:\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].name, expenses[i].amount);
    }
}

// Function to calculate total expenses
double calculateTotalExpenses(struct Expense expenses[], int numExpenses) {
    double total = 0;

    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

// Main function
int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    double totalExpenses;

    while (1) {
        printf("\n1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Quit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                totalExpenses = calculateTotalExpenses(expenses, numExpenses);
                printf("Total expenses: $%.2lf\n", totalExpenses);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}