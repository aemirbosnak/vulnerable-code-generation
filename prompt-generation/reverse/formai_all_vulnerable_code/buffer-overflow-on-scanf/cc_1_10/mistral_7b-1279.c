//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char name[50];
    char description[100];
    float amount;
    int index;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    expenses[num_expenses].index = num_expenses;
    num_expenses++;
}

void remove_expense(int index) {
    if (index < 0 || index >= num_expenses) {
        printf("Error: Invalid expense index.\n");
        return;
    }

    for (int i = index; i < num_expenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    num_expenses--;
}

void list_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("\nExpenses List:\n");
    printf("------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("Expense %d:\n", i + 1);
        printf("Name: %s\n", expenses[i].name);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("\n");
    }
}

void total_expenses() {
    float total = 0;

    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: %.2f\n", total);
}

int main() {
    int choice;

    while (1) {
        printf("\nFuturistic Expense Tracker 3000\n");
        printf("----------------------------------\n");
        printf("1. Add Expense\n");
        printf("2. Remove Expense\n");
        printf("3. List Expenses\n");
        printf("4. Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2: {
                int index;
                printf("Enter expense index to remove: ");
                scanf("%d", &index);
                remove_expense(index);
                break;
            }
            case 3:
                list_expenses();
                break;
            case 4:
                total_expenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}