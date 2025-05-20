//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_LOCATION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter expense description: ");
    fgets(newExpense.description, MAX_DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Strip newline character

    printf("Enter category: ");
    fgets(newExpense.category, MAX_CATEGORY_LENGTH, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0;

    printf("Enter location: ");
    fgets(newExpense.location, MAX_LOCATION_LENGTH, stdin);
    newExpense.location[strcspn(newExpense.location, "\n")] = 0;

    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    getchar(); // Clear newline character after scanf

    printf("Enter date (YYYY-MM-DD): ");
    fgets(newExpense.date, 11, stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = 0;

    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}

void displayExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Description: %s\n", expenses[i].description);
        printf("Category: %s\n", expenses[i].category);
        printf("Location: %s\n", expenses[i].location);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n", expenses[i].date);
        printf("-----------------------\n");
    }
}

void calculateTotal() {
    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void filterExpensesByCategory() {
    char category[MAX_CATEGORY_LENGTH];
    printf("Enter category to filter by: ");
    fgets(category, MAX_CATEGORY_LENGTH, stdin);
    category[strcspn(category, "\n")] = 0; // Strip newline character

    printf("\n--- Filtered Expenses in Category: %s ---\n", category);
    int found = 0;
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("Description: %s\n", expenses[i].description);
            printf("Location: %s\n", expenses[i].location);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
            printf("-----------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found in this category.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Filter Expenses by Category\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after scanf

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                filterExpensesByCategory();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}