//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    char description[100];
    float amount;
} expense;

int num_expenses = 0;
expense expenses[MAX_EXPENSES];

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpense Report\n");
    printf("=============\n");

    printf("Category\tDescription\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void search_expense() {
    char search_category[50];
    printf("Enter expense category to search: ");
    scanf("%s", search_category);

    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, search_category) == 0) {
            printf("\nExpense Found:\n");
            printf("Category: %s\n", expenses[i].category);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: %.2f\n", expenses[i].amount);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No expenses found with that category.\n");
    }
}

int main() {
    printf("Welcome to the Sherlock Holmes Expense Tracker!\n");
    printf("=============================================\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Search expense\n");
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
                search_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}