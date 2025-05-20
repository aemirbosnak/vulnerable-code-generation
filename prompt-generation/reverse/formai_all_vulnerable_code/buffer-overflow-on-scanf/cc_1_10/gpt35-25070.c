//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char description[50];
    float amount;
} Expense;

void printMenu() {
    printf("EXPENSE TRACKER\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void addExpense(Expense *expenses, int *count) {
    if (*count == MAX_EXPENSES) {
        printf("Max number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[*count].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
}

void viewExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    float total = 0;

    printf("%-20s%s\n", "Description", "Amount");
    printf("--------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s$%.2f\n", expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }

    printf("--------------------\n");
    printf("%-20s$%.2f\n", "Total", total);
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}