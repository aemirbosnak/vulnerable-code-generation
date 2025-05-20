//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("You've reached the maximum number of expenses that can be tracked!\n");
        return;
    }

    printf("Enter the description of the expense: ");
    scanf(" %[^\n]", expenses[*count].description);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
    printf("Expense added successfully! 🎉\n");
}

void viewExpenses(Expense expenses[], int count) {
    printf("\n--- Your Expenses ---\n");
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void generateReport(Expense expenses[], int count) {
    printf("\n--- Expense Report ---\n");
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses for the Month: $%.2f\n", total);
    printf("Number of Transactions: %d\n", count);
}

void displayMenu() {
    printf("\nWelcome to the Ultimate Expense Tracker! 🚀\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Generate Report\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                generateReport(expenses, count);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker! Goodbye! 👋\n");
                exit(0);
            default:
                printf("Invalid option! Please try again. 😅\n");
        }
    }

    return 0;
}