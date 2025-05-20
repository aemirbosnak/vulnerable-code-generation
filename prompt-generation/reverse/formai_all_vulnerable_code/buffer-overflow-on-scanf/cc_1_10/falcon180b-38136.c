//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_NAME_LENGTH 50
#define MAX_CATEGORY_NAME_LENGTH 50

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    float amount;
    char category[MAX_CATEGORY_NAME_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void calculate_total_expenses() {
    float total_expenses = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    printf("\nTotal expenses: $%.2f\n", total_expenses);
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                calculate_total_expenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}