//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure declaration for Expense
typedef struct {
    char item[20];
    int cost;
} Expense;

// Function declaration
void addExpense(Expense expenses[], int numExpenses);
void printExpenses(Expense expenses[], int numExpenses);
void totalSpent(Expense expenses[], int numExpenses);
void highestExpense(Expense expenses[], int numExpenses);

// Main function
int main() {
    int option, numExpenses = 0;
    Expense expenses[50];

    do {
        // Print menu options
        printf("\nExpense Tracker\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View total spent\n");
        printf("4. View highest expense\n");
        printf("5. Exit\n\n");
        printf("Enter your option: ");

        // Get user input and switch on option
        scanf("%d", &option);
        switch (option) {
            case 1:
                addExpense(expenses, numExpenses);
                numExpenses++;
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                totalSpent(expenses, numExpenses);
                break;
            case 4:
                highestExpense(expenses, numExpenses);
                break;
            case 5:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}

// Function to add an expense
void addExpense(Expense expenses[], int numExpenses) {
    // Get user input for new expense
    printf("\nEnter the name of the item: ");
    scanf("%s", expenses[numExpenses].item);
    printf("Enter the cost of the item: ");
    scanf("%d", &expenses[numExpenses].cost);
}

// Function to print all expenses
void printExpenses(Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("\nNo expenses have been added.\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %d\n", expenses[i].item, expenses[i].cost);
    }
}

// Function to calculate total spent
void totalSpent(Expense expenses[], int numExpenses) {
    int total = 0;

    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].cost;
    }

    printf("\nTotal spent: %d\n", total);
}

// Function to find highest expense
void highestExpense(Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("\nNo expenses have been added.\n");
        return;
    }

    int highestIndex = 0;

    for (int i = 1; i < numExpenses; i++) {
        if (expenses[i].cost > expenses[highestIndex].cost) {
            highestIndex = i;
        }
    }

    printf("\nThe highest expense is %s - %d\n", expenses[highestIndex].item, expenses[highestIndex].cost);
}