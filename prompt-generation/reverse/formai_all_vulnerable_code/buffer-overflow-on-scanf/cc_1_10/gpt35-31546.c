//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_EXPENSES 100

struct Expense {
    char name[MAX_NAME_LENGTH];
    float cost;
};

struct PersonalFinance {
    float income;
    int num_expenses;
    struct Expense expenses[MAX_EXPENSES];
};

void addExpense(struct PersonalFinance* finance) {
    if (finance->num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    struct Expense* expense = &finance->expenses[finance->num_expenses++];

    printf("Enter expense name: ");
    scanf("%s", expense->name);

    printf("Enter expense cost: ");
    scanf("%f", &expense->cost);
}

void printExpenses(struct PersonalFinance* finance) {
    printf("Expenses:\n");

    for (int i = 0; i < finance->num_expenses; i++) {
        struct Expense* expense = &finance->expenses[i];
        printf("- %s: $%.2f\n", expense->name, expense->cost);
    }
}

float getTotalExpense(struct PersonalFinance* finance) {
    float total = 0;

    for (int i = 0; i < finance->num_expenses; i++) {
        total += finance->expenses[i].cost;
    }

    return total;
}

void printFinance(struct PersonalFinance* finance) {
    printf("\n\n---------Personal Finance Report--------\n");
    printf("Income: $%.2f\n", finance->income);
    printf("Expenses: $%.2f\n", getTotalExpense(finance));
    printf("Net Income: $%.2f\n", finance->income - getTotalExpense(finance));
    printf("----------------------------------------\n\n");
}

int main() {
    struct PersonalFinance finance;
    finance.income = 0;
    finance.num_expenses = 0;

    int choice = -1;

    while (choice != 0) {
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Expenses\n");
        printf("4. View Finance Status\n");
        printf("0. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income: ");
                scanf("%f", &finance.income);
                break;

            case 2:
                addExpense(&finance);
                break;

            case 3:
                printExpenses(&finance);
                break;

            case 4:
                printFinance(&finance);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}