//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of expenses
#define MAX_EXPENSES 100

// define a structure to hold details of an expense
typedef struct {
    char category[50];
    float amount;
    char description[100];
} Expense;

// declare an array to hold expenses
Expense expenses[MAX_EXPENSES];

// declare a variable to keep track of number of expenses added so far
int numExpenses = 0;

// function to add a new expense
void addExpense() {
    Expense expense;

    printf("\nEnter category: ");
    scanf("%s", expense.category);

    printf("Enter amount: ");
    scanf("%f", &expense.amount);

    printf("Enter description: ");
    scanf("%s", expense.description);

    expenses[numExpenses++] = expense;
    printf("\nExpense added successfully!\n");
}

// function to display all expenses
void displayExpenses() {
    if (numExpenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    printf("\n%-15s%-15s%-30s\n", "Category", "Amount", "Description");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-15s%-15.2f%-30s\n", expenses[i].category, expenses[i].amount, expenses[i].description);
    }
}

// function to calculate total expenses
float calculateTotalExpenses() {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// function to display expenses by category
void displayExpensesByCategory() {
    if (numExpenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    char category[50];
    printf("\nEnter category: ");
    scanf("%s", category);

    float total = 0;
    printf("\n%-15s%-15s%-30s\n", "Category", "Amount", "Description");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%-15s%-15.2f%-30s\n", expenses[i].category, expenses[i].amount, expenses[i].description);
            total += expenses[i].amount;
        }
    }

    printf("\nTotal expenses in %s category: %.2f\n", category, total);
}

// main function
int main() {
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("---------------\n");
        printf("1. Add new expense\n");
        printf("2. Display all expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Display expenses by category\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                displayExpenses();
                break;

            case 3:
                printf("\nTotal expenses: %.2f\n", calculateTotalExpenses());
                break;

            case 4:
                displayExpensesByCategory();
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}