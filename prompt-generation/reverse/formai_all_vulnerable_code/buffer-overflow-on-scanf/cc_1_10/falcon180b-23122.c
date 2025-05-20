//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char category[MAX_DESCRIPTION_LENGTH];
    float amount;
} expense_t;

void add_expense(expense_t *expenses[], int *num_expenses) {
    int i;
    for (i = 0; i < *num_expenses; i++) {
        if (strcmp(expenses[i]->category, "") == 0) {
            strcpy(expenses[i]->category, "Miscellaneous");
            break;
        }
    }
    if (i == *num_expenses) {
        printf("Error: Too many expenses!\n");
        exit(1);
    }
    printf("Enter expense category: ");
    scanf("%s", expenses[i]->category);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[i]->amount);
    (*num_expenses)++;
}

void display_expenses(expense_t *expenses, int num_expenses) {
    int i;
    float total_expenses = 0.0;
    for (i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
        total_expenses += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total_expenses);
}

int main() {
    int num_expenses = 0;
    expense_t expenses[MAX_ITEMS];
    expense_t *current_expense = expenses;
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_expense(expenses, &num_expenses);
            break;
        case 2:
            display_expenses(expenses, num_expenses);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}