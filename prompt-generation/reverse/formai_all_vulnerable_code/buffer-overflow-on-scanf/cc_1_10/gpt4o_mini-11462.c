//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Whoa! You're saving too many expenses! Can't add more.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter the description of the expense: ");
    getchar(); // to consume the newline character from the previous input
    fgets(newExpense.description, MAX_DESC_LEN, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline
    
    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);
    
    expenses[expenseCount++] = newExpense;
    printf("Expense added: %s for $%.2f\n", newExpense.description, newExpense.amount);
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses logged yet! Start adding expenses, you savvy spender!\n");
        return;
    }
    
    printf("\n--- Your Expenses ---\n");
    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense %d: %s for $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("---------------------\n");
    printf("Total expenses: $%.2f\n", total);
}

void deleteExpense() {
    int index;
    printf("Enter the expense number to delete (1 to %d): ", expenseCount);
    scanf("%d", &index);
    
    if (index < 1 || index > expenseCount) {
        printf("Oops! Invalid expense number.\n");
        return;
    }
    
    // Shift remaining expenses left
    for (int i = index - 1; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    printf("Expense number %d successfully deleted!\n", index);
}

void showMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Expense Tracker!\n");
    
    do {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                printf("Thanks for using Expense Tracker. Keep saving!\n");
                break;
            default:
                printf("Invalid choice, my friend. Try again!\n");
        }
    } while (choice != 4);
    
    return 0;
}