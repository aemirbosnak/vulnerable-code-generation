//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    char description[100];
    double amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense category: ");
    scanf("%s", expenses[numExpenses].category);

    printf("Enter expense description: ");
    scanf("%s", expenses[numExpenses].description);

    printf("Enter expense amount: $");
    scanf("%lf", &expenses[numExpenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[numExpenses].date);

    numExpenses++;
}

void viewExpenses() {
    if (numExpenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    printf("Expenses:\n");
    printf("Category\tDescription\tAmount\tDate\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t$%.2f\t%d\n", expenses[i].category, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void searchExpenses() {
    char searchCategory[50];
    printf("Enter category to search: ");
    scanf("%s", searchCategory);

    int found = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, searchCategory) == 0) {
            printf("Found %d expenses:\n", found + 1);
            viewExpenses();
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No expenses found.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expenses\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addExpense();
            break;
        case 2:
            viewExpenses();
            break;
        case 3:
            searchExpenses();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}