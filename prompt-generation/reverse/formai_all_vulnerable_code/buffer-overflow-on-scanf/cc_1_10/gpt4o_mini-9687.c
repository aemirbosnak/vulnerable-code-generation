//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESC_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESC_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }
    printf("Enter category: ");
    scanf("%s", expenses[*count].category);
    printf("Enter description: ");
    scanf(" %[^\n]s", expenses[*count].description);
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nList of Expenses:\n");
    printf("%-20s %-30s %-10s\n", "Category", "Description", "Amount");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-30s $%.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void totalExpenses(Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\nExpense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                totalExpenses(expenses, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}