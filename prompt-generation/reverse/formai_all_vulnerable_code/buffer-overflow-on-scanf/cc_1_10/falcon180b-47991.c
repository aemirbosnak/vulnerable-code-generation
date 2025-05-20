//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} Expense;

void addExpense(Expense* expenses, int numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[numExpenses].category);

    printf("Enter expense amount: ");
    scanf("%s", expenses[numExpenses].amount);

    numExpenses++;
}

void displayExpenses(Expense* expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %s - %s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    Expense expenses[MAX_ITEMS];
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (numExpenses < MAX_ITEMS) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addExpense(expenses, numExpenses);
            break;
        case 2:
            displayExpenses(expenses, numExpenses);
            break;
        case 3:
            printf("Thank you for using the Expense Tracker!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}