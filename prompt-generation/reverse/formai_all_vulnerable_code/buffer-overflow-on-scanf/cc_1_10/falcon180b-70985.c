//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[20];
} expense;

void add_expense(expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    num_expenses++;
}

void display_expenses(expense* expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("Expense #%d:\n", i+1);
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n\n", expenses[i].category);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        printf("Current number of expenses: %d\n", num_expenses);
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}