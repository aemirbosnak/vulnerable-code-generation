//FormAI DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing expense information
typedef struct {
    char category[20];
    double amount;
} Expense;

// Function for adding a new expense to list
void addExpense(Expense *expenses, int *numExpenses) {
    printf("\nEnter expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*numExpenses].amount);
    
    (*numExpenses)++;
}

// Function for displaying all expenses in list
void displayExpenses(Expense *expenses, int numExpenses) {
    printf("\nExpense Tracker:\n-----------------\n\n");
    for(int i=0; i<numExpenses; i++) {
        printf("%s\t\t$%.2lf\n", expenses[i].category, expenses[i].amount);
    }
}

// Function for calculating total expenses
double calculateTotalExpenses(Expense *expenses, int numExpenses) {
    double total = 0;
    for(int i=0; i<numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Function for displaying menu options and getting user input
int displayMenu() {
    int choice;
    printf("\nMenu:\n------\n\n");
    printf("1. Add new expense\n");
    printf("2. Display all expenses\n");
    printf("3. Calculate total expenses\n");
    printf("4. Quit\n\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    Expense *expenses = malloc(100 * sizeof(Expense));
    int numExpenses = 0;
    int choice;
    
    printf("Welcome to your Expense Tracker!\n");
    
    do {
        choice = displayMenu();
        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("\nTotal expenses: $%.2lf\n", calculateTotalExpenses(expenses, numExpenses));
                break;
            case 4:
                printf("\nThank you for using your Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1-4.\n");
        }
    } while (choice != 4);
    
    free(expenses);
    return 0;
}