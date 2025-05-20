//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count < MAX_EXPENSES) {
        printf("\nEnter the name of the expense: ");
        scanf("%s", expenses[*count].name);
        printf("Enter the amount of the expense: ");
        scanf("%f", &expenses[*count].amount);
        (*count)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached! Cannot add more expenses.\n");
    }
}

void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses recorded yet!\n");
        return;
    }

    printf("\n--- Your Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

float calculateTotal(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("\n*** Welcome to Your Expense Tracker! ***\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expense\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                displayExpenses(expenses, expenseCount);
                break;
            case 3:
                {
                    float total = calculateTotal(expenses, expenseCount);
                    printf("\nTotal Expenses: $%.2f\n", total);
                }
                break;
            case 4:
                printf("Thank you for using the Expense Tracker! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose a valid option (1-4).\n");
        }
    }

    return 0;
}