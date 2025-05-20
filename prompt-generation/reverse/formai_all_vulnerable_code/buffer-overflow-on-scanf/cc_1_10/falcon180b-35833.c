//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} expense;

void add_expense(expense expenses[], int num_expenses, char name[], char amount[]) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses. Maximum limit reached.\n");
        return;
    }
    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].amount, amount);
    num_expenses++;
}

void show_expenses(expense expenses[], int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: %s\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char name[MAX_NAME_LENGTH], amount[MAX_AMOUNT_LENGTH];

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n2. Show expenses\n3. Exit\n");
        scanf("%d", &num_expenses);

        switch (num_expenses) {
            case 1:
                printf("Enter the name of the expense: ");
                scanf("%s", name);
                printf("Enter the amount of the expense: ");
                scanf("%s", amount);
                add_expense(expenses, num_expenses, name, amount);
                break;
            case 2:
                show_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}