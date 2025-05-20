//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void addExpense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    
    Expense new_expense;
    
    printf("Enter expense name: ");
    scanf("%s", new_expense.name);
    
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    
    expenses[expense_count] = new_expense;
    expense_count++;
    
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expense_count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    
    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s: %.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
    printf("-----------------------\n");
}

void calculateTotal() {
    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void deleteExpense() {
    if (expense_count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    
    viewExpenses();
    
    int index;
    printf("Enter the number of the expense to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > expense_count) {
        printf("Invalid selection! Please try again.\n");
        return;
    }
    
    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    
    printf("Expense deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                deleteExpense();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}