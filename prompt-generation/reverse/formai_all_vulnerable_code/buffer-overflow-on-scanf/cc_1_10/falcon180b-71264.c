//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

typedef struct {
    char name[51];
    float amount;
    char category[51];
    char date[11];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%50s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%50s", expenses[num_expenses].category);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%10s", expenses[num_expenses].date);

    num_expenses++;
    printf("Expense added successfully.\n");
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Expense Name\tAmount\tCategory\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-50s\t%.2f\t%-50s\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void search_expense() {
    char search_name[51];
    printf("Enter expense name to search: ");
    scanf("%50s", search_name);

    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("Expense found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Category: %s\n", expenses[i].category);
            printf("Date: %s\n", expenses[i].date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n1. Add expense\n2. View expenses\n3. Search expense\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}