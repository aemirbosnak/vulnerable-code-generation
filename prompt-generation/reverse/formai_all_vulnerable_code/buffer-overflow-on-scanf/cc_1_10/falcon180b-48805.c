//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    char date[10];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum expenses limit reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    printf("ID\tDescription\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d\t%s\t%.2f\t%s\n", i+1, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void search_expense() {
    char search_desc[50];

    printf("\nEnter expense description to search: ");
    scanf("%s", search_desc);

    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].description, search_desc) == 0) {
            printf("\nExpense found:\n");
            printf("ID\tDescription\tAmount\tDate\n");
            printf("%d\t%s\t%.2f\t%s\n", i+1, expenses[i].description, expenses[i].amount, expenses[i].date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nExpense not found.\n");
    }
}

void main() {
    printf("\nWelcome to the Expense Tracker!\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Search expense\n");
    printf("4. Exit\n");

    int choice;
    while (1) {
        printf("\nEnter your choice: ");
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
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}