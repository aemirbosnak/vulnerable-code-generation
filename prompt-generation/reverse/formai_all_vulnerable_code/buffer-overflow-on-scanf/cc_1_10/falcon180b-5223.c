//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    char date[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void addExpense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: $");
    scanf("%lf", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;
}

void viewExpenses() {
    int i;

    printf("Expense Name | Expense Amount | Expense Date\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%-30s $%.2lf | %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void searchExpense() {
    char search_name[50];

    printf("Enter expense name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("Expense found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Amount: $%.2lf\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addExpense();
            break;
        case 2:
            viewExpenses();
            break;
        case 3:
            searchExpense();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}