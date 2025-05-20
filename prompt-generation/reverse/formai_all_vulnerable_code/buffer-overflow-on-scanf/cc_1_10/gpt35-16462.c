//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

// Struct to store each individual expense
typedef struct {
    char description[100];
    float cost;
} Expense;

// Function to add a new expense to the expense tracker
void addExpense(Expense expenses[], int *nExpenses) {
    // Get description for the new expense
    char description[100];
    printf("Enter a description for the expense: ");
    fgets(description, 100, stdin);
    strtok(description, "\n");

    // Get cost for the new expense
    float cost;
    printf("Enter the cost of the expense: ");
    scanf("%f", &cost);

    // Add the new expense to the expense tracker
    Expense newExpense;
    strcpy(newExpense.description, description);
    newExpense.cost = cost;
    expenses[*nExpenses] = newExpense;
    (*nExpenses)++;
}

// Function to display a list of all expenses in the expense tracker
void displayExpenses(Expense expenses[], int nExpenses) {
    printf("Expense Tracker\n");
    printf("-----------------\n");
    printf("No.\tDescription\tCost\n");
    printf("-----------------\n");

    for (int i = 0; i < nExpenses; i++) {
        printf("%d.\t%s\t%.2f\n", i+1, expenses[i].description, expenses[i].cost);
    }
}

// Function to calculate the total cost of all expenses in the expense tracker
float calculateTotalCost(Expense expenses[], int nExpenses) {
    float totalCost = 0;

    for (int i = 0; i < nExpenses; i++) {
        totalCost += expenses[i].cost;
    }

    return totalCost;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int nExpenses = 0;
    char choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("---------------\n");
        printf("1. Add expense\n");
        printf("2. Display all expenses\n");
        printf("3. Calculate total cost\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar();  // Consume extra newline character

        switch(choice) {
            case '1': {
                addExpense(expenses, &nExpenses);
                break;
            }
            case '2': {
                displayExpenses(expenses, nExpenses);
                break;
            }
            case '3': {
                float totalCost = calculateTotalCost(expenses, nExpenses);
                printf("Total cost of all expenses: $%.2f\n", totalCost);
                break;
            }
            case '4': {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}