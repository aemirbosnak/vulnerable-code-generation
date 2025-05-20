//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char description[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char* description, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add expense. Array is full.\n");
        return;
    }

    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void view_expenses() {
    printf("\nCurrent Expenses:\n");
    printf("------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %.2f\n", expenses[i].description, expenses[i].amount);
    }
}

void delete_expense(int index) {
    if (index < 0 || index >= num_expenses) {
        printf("Error: Invalid index.\n");
        return;
    }

    memmove(&expenses[index], &expenses[index + 1], sizeof(Expense) * (num_expenses - index - 1));
    num_expenses--;
}

int main() {
    int choice;
    char description[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(description, amount);
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("Enter index of expense to delete: ");
                scanf("%d", &choice);
                delete_expense(choice);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}