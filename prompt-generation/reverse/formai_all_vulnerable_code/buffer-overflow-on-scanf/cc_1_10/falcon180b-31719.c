//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_AMOUNT_LENGTH 10

typedef struct expense {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
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
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    printf("Expense Name\tDescription\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t\t%s\t\t%s\n", expenses[i].name, expenses[i].description, expenses[i].amount);
    }
}

void search_expense() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter expense name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("Expense found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: %s\n", expenses[i].amount);
            return;
        }
    }

    printf("Expense not found.\n");
}

int main() {
    int choice;

    do {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}