//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

struct expense {
    char category[MAX_CATEGORIES];
    float amount;
};

struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    char category[MAX_CATEGORIES];
    float amount;

    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: $");
    scanf("%f", &amount);

    strncpy(expenses[num_expenses].category, category, MAX_CATEGORIES);
    expenses[num_expenses].amount = amount;

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    printf("Category\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t$%.2f\n", expenses[i].category, expenses[i].amount);
    }
}

void display_total_expenses() {
    float total_expenses = 0;

    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    printf("\nTotal expenses: $%.2f\n", total_expenses);
}

void display_expenses_by_category() {
    char category[MAX_CATEGORIES];
    float total_expenses = 0;

    printf("\nExpenses by category:\n");
    printf("Category\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        strncpy(category, expenses[i].category, MAX_CATEGORIES);
        total_expenses += expenses[i].amount;

        printf("%s\t$%.2f\n", category, expenses[i].amount);
    }

    printf("\nTotal expenses: $%.2f\n", total_expenses);
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Display total expenses\n");
        printf("4. Display expenses by category\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;

        case 2:
            display_expenses();
            break;

        case 3:
            display_total_expenses();
            break;

        case 4:
            display_expenses_by_category();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}