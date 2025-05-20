//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // maximum number of expenses
#define MAX_DESC_LENGTH 50 // maximum length of the description string

// expense structure
struct Expense {
    char description[MAX_DESC_LENGTH];
    double amount;
};

// function to add a new expense
void addExpense(struct Expense *expenses, int *count) {
    printf("Enter description: ");
    fgets(expenses[*count].description, MAX_DESC_LENGTH, stdin);

    // remove newline character at the end of the string from fgets
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0;

    printf("Enter amount: ");
    scanf("%lf", &expenses[*count].amount);

    // clear input buffer to avoid inputting a newline character with fgets later
    while (getchar() != '\n');

    printf("Expense added successfully!\n");

    *count = *count + 1; // increment the count
}

// function to display all expenses
void displayExpenses(struct Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Expenses:\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2lf\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        // clear input buffer to avoid inputting a newline character with fgets later
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}