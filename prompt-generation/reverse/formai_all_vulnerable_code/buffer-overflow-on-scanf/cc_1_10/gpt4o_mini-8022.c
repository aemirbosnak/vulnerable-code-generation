//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

void displayMenu() {
    printf("\n====================\n");
    printf("     Expense Tracker\n");
    printf("====================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("====================\n");
    printf("Enter your choice: ");
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Cannot add more expenses, limit reached!\n");
        return;
    }
    
    printf("Enter description of expense: ");
    scanf(" %[^\n]", expenses[*count].description);
    printf("Enter amount of expense: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
    printf("Expense added successfully! Thank you for keeping track.\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to display. Let's start tracking them!\n");
        return;
    }
    
    printf("\nList of Expenses:\n");
    float total = 0;
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete. Isn't saving great?\n");
        return;
    }
    
    viewExpenses(expenses, *count);
    printf("Enter the number of expense to delete: ");
    int index;
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid choice! Kindly check again.\n");
    } else {
        for (int i = index - 1; i < *count - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        (*count)--;
        printf("Expense deleted successfully! Great job managing your budget.\n");
    }
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
                deleteExpense(expenses, &count);
                break;
            case 4:
                printf("Thank you for using Expense Tracker. Happy budgeting!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}