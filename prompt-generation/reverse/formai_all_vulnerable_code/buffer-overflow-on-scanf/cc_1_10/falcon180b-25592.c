//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char description[MAX_DESCRIPTION_LEN];
    float amount;
    char date[11];
} Expense;

int num_expenses = 0;
Expense expenses[MAX_EXPENSES];

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - $%.2f - %s\n", i+1, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void display_total_expenses() {
    float total_expenses = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    printf("\nTotal expenses: $%.2f\n", total_expenses);
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Display total expenses\n");
        printf("4. Exit\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_expense();
                break;
            case '2':
                display_expenses();
                break;
            case '3':
                display_total_expenses();
                break;
            case '4':
                printf("Thank you for using the Expense Tracker!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}