//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char description[50];
    double amount;
    char category[20];
};

void add_expense(struct expense expenses[], int num_expenses) {
    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    num_expenses++;
}

void display_expenses(struct expense expenses[], int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2lf - %s\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

void calculate_total_expenses(struct expense expenses[], int num_expenses, double total) {
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal Expenses: %.2lf\n", total);
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Personal Finance Planner\n");
    printf("-------------------------\n");

    while (num_expenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense or 0 to finish:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_expense(expenses, num_expenses);
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    display_expenses(expenses, num_expenses);
    calculate_total_expenses(expenses, num_expenses, 0.0);

    return 0;
}