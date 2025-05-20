//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 20
#define DESC_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESC_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void addExpense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Maximum expense limit reached.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter category of expense: ");
    scanf("%s", new_expense.category);
    printf("Enter description of expense: ");
    scanf(" %[^\n]", new_expense.description);
    printf("Enter amount of expense: ");
    scanf("%f", &new_expense.amount);
    
    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}

void displayExpenses() {
    if (expense_count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    
    printf("\nList of Expenses:\n");
    printf("%-15s %-50s %-10s\n", "Category", "Description", "Amount");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < expense_count; i++) {
        printf("%-15s %-50s $%-9.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    printf("---------------------------------------------------------------\n");
}

void displaySummary() {
    if (expense_count == 0) {
        printf("No expenses to summarize.\n");
        return;
    }
    
    float total = 0;
    printf("\nExpense Summary:\n");
    
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    
    printf("Total Expenses: $%.2f\n", total);
}

void menu() {
    int choice;
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                displaySummary();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}