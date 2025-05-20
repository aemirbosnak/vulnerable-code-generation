//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_EXPENSES 1000

typedef struct {
    char category[50];
    char description[100];
    float amount;
    time_t date;
} expense;

int num_expenses = 0;
expense expenses[MAX_EXPENSES];

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter the expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter the expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter the expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    time_t now = time(NULL);
    expenses[num_expenses].date = now;

    num_expenses++;

    printf("Expense added successfully.\n");
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expense Category | Description | Amount | Date\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s | %-40s | %.2f | %s\n", expenses[i].category, expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add expense\n2. View expenses\n");

    int choice;
    while (true) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}