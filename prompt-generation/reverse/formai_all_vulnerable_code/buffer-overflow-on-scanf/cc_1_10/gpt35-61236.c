//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char description[50];
    double amount;
};

void printMenu() {
    printf("Expense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
}

void addExpense(struct Expense *expenses, int *numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("You have reached the maximum number of expenses!\n");
        return;
    }

    struct Expense newExpense;
    printf("Enter expense description:\n");
    fgets(newExpense.description, 50, stdin);
    printf("Enter expense amount:\n");
    scanf("%lf", &newExpense.amount);

    expenses[*numExpenses] = newExpense;
    *numExpenses += 1;

    printf("Expense added successfully!\n");
}

void viewExpenses(struct Expense *expenses, int numExpenses) {
    if (numExpenses == 0) {
        printf("You have no expenses to view!\n");
        return;
    }

    printf("All Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. Description: %sAmount: $%.2lf\n", i+1, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Thank you for using the Expense Tracker!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (1);

    return 0;
}