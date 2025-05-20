//FormAI DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of expenses
#define MAX_EXPENSES 100

// Define structure for an Expense
typedef struct {
    char category[50];
    float amount;
    char date[15];
} Expense;

// Define function to display menu
void displayMenu() {
    printf("\n\nExpense Tracker Menu\n");
    printf("---------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

// Define function to get user input
void getUserInput(char * prompt, char * value) {
    printf("%s: ", prompt);
    scanf("%s", value);
}

// Define function to add expense
int addExpense(Expense * expenses, int count) {
    // Check if maximum number of expenses reached
    if (count >= MAX_EXPENSES) {
        printf("\nMaximum number of expenses reached. Cannot add more.\n");
        return count;
    }

    // Get expense details from user
    char category[50], amountStr[15], date[15];
    float amount;
    getUserInput("Category", category);
    getUserInput("Amount", amountStr);
    getUserInput("Date (DD/MM/YYYY)", date);

    // Convert amount from string to float
    amount = atof(amountStr); 

    // Add expense to array
    Expense newExpense;
    strcpy(newExpense.category, category);
    newExpense.amount = amount;
    strcpy(newExpense.date, date);
    expenses[count] = newExpense;

    // Increment count and return
    return count + 1;
}

// Define function to view expenses
void viewExpenses(Expense * expenses, int count) {
    // Check if no expenses added yet
    if (count == 0) {
        printf("\nNo expenses added yet.\n");
        return;
    }

    // Display table header
    printf("\nExpenses Table\n");
    printf("---------------------\n");
    printf("%-20s %-10s %-15s\n", "Category", "Amount", "Date");

    // Loop through expenses array and display each expense
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-15s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

// Main function
int main() {
    // Declare expenses array and count variable
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    // Display menu and get user choice
    int choice = 0;
    while (choice != 3) {
        displayMenu();
        scanf("%d", &choice);

        // Call appropriate function based on user choice
        switch (choice) {
            case 1:
                count = addExpense(expenses, count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}