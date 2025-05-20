//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char* name, const char* category, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }
    strncpy(expenses[num_expenses].name, name, MAX_NAME_LENGTH);
    strncpy(expenses[num_expenses].category, category, MAX_CATEGORY_LENGTH);
    expenses[num_expenses++].amount = amount;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s %s: $%.2f\n", i+1, expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void search_expenses(const char* keyword) {
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].name, keyword) || strstr(expenses[i].category, keyword)) {
            printf("%s %s: $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
        }
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;

    while (1) {
        printf("\nExpense Tracker\n1. Add Expense\n2. Display Expenses\n3. Search Expenses\n4. Quit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(name, category, amount);
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Enter keyword: ");
                scanf("%s", name);
                search_expenses(name);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}