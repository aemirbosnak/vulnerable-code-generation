//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Expense tracker is full.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;

    printf("Expense added successfully.\n");
}

void list_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\nExpense Tracker Report\n");
    printf("----------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - %s: $%.2f\n", i+1, expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void search_expense() {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];

    printf("Enter expense name to search: ");
    scanf("%s", name);

    printf("Enter expense category to search: ");
    scanf("%s", category);

    int found = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0 && strcmp(expenses[i].category, category) == 0) {
            printf("Expense found:\n");
            printf("%s - %s: $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}