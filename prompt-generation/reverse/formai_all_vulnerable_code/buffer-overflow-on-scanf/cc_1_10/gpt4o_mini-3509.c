//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter description of the expense: ");
    scanf(" %[^\n]", expenses[*count].description); 

    printf("Enter amount of the expense: ");
    scanf("%f", &expenses[*count].amount);
    
    (*count)++;
    printf("Expense added successfully!\n");
}

void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n--- Your Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

float calculateTotalExpenses(Expense expenses[], int count) {
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                {
                    float total = calculateTotalExpenses(expenses, count);
                    printf("Total Expenses: $%.2f\n", total);
                }
                break;
            case 4:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}