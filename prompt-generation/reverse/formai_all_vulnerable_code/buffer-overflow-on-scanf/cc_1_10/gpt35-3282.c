//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure to hold the details of each expense
typedef struct Expense {
    char name[50];
    float amount;
    char date[20];
} Expense;

// Define the function that will add a new expense to the expenses array
void addExpense(Expense expenses[], int *count) {
    // Prompt the user to enter the name of the expense
    printf("Enter the name of the expense: ");
    scanf("%s", expenses[*count].name);

    // Prompt the user to enter the amount of the expense
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[*count].amount);

    // Prompt the user to enter the date of the expense
    printf("Enter the date of the expense (DD/MM/YYYY): ");
    scanf("%s", expenses[*count].date);

    // Increment the count of expenses
    (*count)++;
}

// Define the function that will print the details of all expenses in the expenses array
void viewExpenses(Expense expenses[], int count) {
    // Check if there are any expenses to view
    if (count == 0) {
        printf("No expenses to view.\n");
        return;
    }

    // Print the header for the expenses table
    printf("\n%-20s %-10s %-20s\n", "Expense Name", "Amount", "Date");

    // Loop through each expense and print its details
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-20s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    // Define the array to hold the expenses and the count of expenses
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    // Define a variable to hold the user's choice from the main menu
    int choice;

    // Loop through the main menu until the user chooses to exit
    do {
        // Print the main menu
        printf("\nExpense Tracker\n");
        printf("1. Add an Expense\n");
        printf("2. View all Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}