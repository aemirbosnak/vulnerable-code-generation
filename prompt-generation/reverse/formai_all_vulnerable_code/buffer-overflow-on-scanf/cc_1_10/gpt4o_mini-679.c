//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESCRIPTION_LENGTH 50

typedef struct {
    float amount;
    char category[CATEGORY_LENGTH];
    char description[DESCRIPTION_LENGTH];
} Expense;

void addExpense(Expense *expenses, int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached! Unable to add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter amount spent: ");
    scanf("%f", &newExpense.amount);
    printf("Enter expense category: ");
    scanf("%s", newExpense.category);
    printf("Enter description: ");
    scanf("%s", newExpense.description);
    
    expenses[*count] = newExpense;
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    
    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("Expense %d:\n", i + 1);
        printf("  Amount: $%.2f\n", expenses[i].amount);
        printf("  Category: %s\n", expenses[i].category);
        printf("  Description: %s\n", expenses[i].description);
        printf("-------------------------\n");
    }
}

void viewCategorySummary(Expense *expenses, int count) {
    char category[CATEGORY_LENGTH];
    printf("Enter a category to view its summary: ");
    scanf("%s", category);
    
    float total = 0.0;
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
            found = 1;
        }
    }
    
    if (found) {
        printf("Total spent in category '%s': $%.2f\n", category, total);
    } else {
        printf("No expenses found in category '%s'.\n", category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;
    
    do {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Category Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                viewCategorySummary(expenses, count);
                break;
            case 4:
                printf("Exiting Expense Tracker. Bye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);
    
    return 0;
}