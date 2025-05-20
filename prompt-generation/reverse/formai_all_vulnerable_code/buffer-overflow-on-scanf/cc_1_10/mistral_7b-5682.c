//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 30

typedef struct Expense {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Max number of expenses reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    printf("%-20s %-20s %s\n", "Name", "Category", "Amount");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s %-20s %.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void search_expenses() {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);
    printf("Enter category to search: ");
    scanf("%s", category);

    int found = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0 && strcmp(expenses[i].category, category) == 0) {
            printf("Expense found:\n");
            printf("%-20s %-20s %.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
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
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Search Expenses\n");
        printf("4. Exit\n");
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
                search_expenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}