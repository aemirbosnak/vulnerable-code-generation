//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define the structure for storing expenses
typedef struct {
    char name[50];
    float amount;
} Expense;

// Function to add a new expense to the list
int addExpense(Expense expenses[], int numExpenses) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return numExpenses;
    }
    
    char name[50];
    float amount;
    
    printf("Name of expense: ");
    scanf("%s", name);
    printf("Amount of expense: $");
    scanf("%f", &amount);
    
    // Add the expense to the expenses array
    Expense newExpense;
    strcpy(newExpense.name, name);
    newExpense.amount = amount;
    
    expenses[numExpenses] = newExpense;
    
    printf("Expense added successfully.\n");
    
    return numExpenses + 1;
}

// Function to remove an expense from the list
int removeExpense(Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses to remove.\n");
        return numExpenses;
    }
    
    char name[50];
    
    printf("Name of expense to remove: ");
    scanf("%s", name);
    
    // Find the expense to remove and shift the remaining expenses to fill the empty space
    int indexOfExpenseToRemove = -1;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            indexOfExpenseToRemove = i;
            break;
        }
    }
    
    if (indexOfExpenseToRemove == -1) {
        printf("Expense not found.\n");
        return numExpenses;
    }
    
    for (int i = indexOfExpenseToRemove; i < numExpenses - 1; i++) {
        expenses[i] = expenses[i+1];
    }
    
    printf("Expense removed successfully.\n");
    
    return numExpenses - 1;
}

// Function to print the list of expenses
void printExpenses(Expense expenses[], int numExpenses) {
    float totalSpent = 0;
    
    printf("\n --- EXPENSES ---\n\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
        totalSpent += expenses[i].amount;
    }
    
    printf("\nTotal spent: $%.2f\n\n", totalSpent);
}

// Main program to manage expenses
int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    
    while (1) {
        printf("\n ---- MENU ----\n");
        printf("1. Add expense\n");
        printf("2. Remove expense\n");
        printf("3. View expenses\n");
        printf("4. Exit\n");
        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                numExpenses = addExpense(expenses, numExpenses);
                break;
            case 2:
                numExpenses = removeExpense(expenses, numExpenses);
                break;
            case 3:
                printExpenses(expenses, numExpenses);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    
    return 0;
}