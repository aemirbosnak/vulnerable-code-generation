//FormAI DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

// struct to hold expense details
typedef struct Expense {
    char name[50];
    float amount;
    int category;
} Expense;

// Function to display menu and get user input
int menu() {
    int choice;
    printf("\n==== EXPENSE TRACKER ====\n");
    printf("1. Add an expense\n");
    printf("2. Display all expenses\n");
    printf("3. Display expenses by category\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add an expense
void addExpense(Expense expenses[], int *numExpenses) {
    Expense expense;
    printf("\nEnter new expense details:\n");
    printf("Name: ");
    scanf("%s", expense.name);
    printf("Amount: ");
    scanf("%f", &expense.amount);
    printf("Category: ");
    scanf("%d", &expense.category);
    expenses[*numExpenses] = expense;
    (*numExpenses)++;
    printf("Expense added successfully!\n");
}

// Function to display all expenses
void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nAll expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: %.2f (Category %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

// Function to display expenses by category
void displayExpensesByCategory(Expense expenses[], int numExpenses) {
    int category;
    printf("\nEnter category to display expenses: ");
    scanf("%d", &category);
    printf("\nExpenses for category %d:\n", category);
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i].category == category) {
            printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
        }
    }
}

// Main function
int main() {
    int choice, numExpenses = 0;
    Expense expenses[MAX_EXPENSES];

    do {
        choice = menu();
        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                displayExpensesByCategory(expenses, numExpenses);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}