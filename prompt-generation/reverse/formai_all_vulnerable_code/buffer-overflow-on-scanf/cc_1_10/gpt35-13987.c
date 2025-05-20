//FormAI DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_DESC_LENGTH 100

/* Structure to hold expense data */
typedef struct expense {
    char description[MAX_DESC_LENGTH];
    double amount;
} Expense;

/* Function prototypes */
int addExpense(Expense[], int);
double calculateTotal(Expense[], int);
void printExpenses(Expense[], int);

int main() {
    /* Declare variables */
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;

    /* Main program loop */
    do {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add expense\n");
        printf("2. Calculate total\n");
        printf("3. Print expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        /* Get user input */
        scanf(" %c", &choice);

        /* Process user input */
        switch (choice) {
            case '1':
                numExpenses = addExpense(expenses, numExpenses);
                break;
            case '2':
                printf("\nTotal expenses: $%.2f\n", calculateTotal(expenses, numExpenses));
                break;
            case '3':
                printExpenses(expenses, numExpenses);
                break;
            case '4':
                printf("\nQuitting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}

/**
 * Adds a new expense to the given array of expenses.
 *
 * @param expenses the array of expenses to add to
 * @param numExpenses the number of expenses currently in the array
 *
 * @return the new number of expenses in the array
 */
int addExpense(Expense expenses[], int numExpenses) {
    /* Check if we've reached the maximum number of expenses */
    if (numExpenses == MAX_EXPENSES) {
        printf("\nMaximum number of expenses reached.\n");
        return numExpenses;
    }

    /* Get user input */
    printf("\nEnter expense description: ");
    scanf(" %[^\n]", expenses[numExpenses].description);
    printf("Enter expense amount: ");
    scanf(" %lf", &expenses[numExpenses].amount);

    /* Increment number of expenses */
    printf("\nExpense added successfully!\n");
    return numExpenses + 1;
}

/**
 * Calculates the total of the given array of expenses.
 *
 * @param expenses the array of expenses to calculate the total of
 * @param numExpenses the number of expenses in the array
 *
 * @return the total of all expenses in the array
 */
double calculateTotal(Expense expenses[], int numExpenses) {
    double total = 0.0;

    /* Loop through all expenses and add up amounts */
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

/**
 * Prints out the given array of expenses.
 *
 * @param expenses the array of expenses to print
 * @param numExpenses the number of expenses in the array
 */
void printExpenses(Expense expenses[], int numExpenses) {
    /* Print expense header */
    printf("\n%-30s | %-10s\n", "Description", "Amount");
    printf("-------------------------------------------\n");

    /* Loop through all expenses and print them */
    for (int i = 0; i < numExpenses; i++) {
        printf("%-30s | $%-10.2f\n", expenses[i].description, expenses[i].amount);
    }
}