//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    char category[50];
    char date[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2lf - %s - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void search_expense() {
    char search_name[50];

    printf("\nEnter expense name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("\n%s - %.2lf - %s - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
            found = 1;
        }
    }

    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n1. Add expense\n2. Display expenses\n3. Search expense\n4. Exit\n");
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
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}