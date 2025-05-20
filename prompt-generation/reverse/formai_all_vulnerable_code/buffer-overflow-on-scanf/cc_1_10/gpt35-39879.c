//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
};

void addExpense(struct Expense expenses[], int* count) {
    char name[50];
    float amount;

    printf("\nEnter expense name: ");
    scanf("%s", &name);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    struct Expense expense = { .name = name, .amount = amount };
    expenses[*count] = expense;

    (*count)++;

    printf("\nExpense added successfully!\n\n");
}

void displayExpenses(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses to display!\n\n");
        return;
    }

    printf("\nExpenses:\n");

    for (int i = 0; i < count; i++) {
        struct Expense expense = expenses[i];
        printf("Name: %s\t Amount: %.2f\n", expense.name, expense.amount);
    }

    printf("\n");
}

void displayMenu() {
    printf("Expenses Tracker\n");
    printf("1. Add expense\n");
    printf("2. Display expenses\n");
    printf("3. Quit\n");
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;

    while (1) {
        displayMenu();
        
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    }
}