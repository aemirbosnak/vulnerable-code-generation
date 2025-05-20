//FormAI DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of expenses that can be added
#define MAX_EXPENSES 100

// Define structure to hold expense information
struct Expense { 
    char name[50];
    float cost;
};

// Define function to add a new expense
void addExpense(struct Expense expenses[], int* count) {
    // Check if maximum number of expenses has been reached
    if (*count >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    // Get input from user
    printf("Enter expense name: ");
    scanf("%s", &(expenses[*count].name));
    printf("Enter cost: ");
    scanf("%f", &(expenses[*count].cost));
    // Increment expense count
    *count += 1;
    printf("Expense added.\n");
}

// Define function to display all expenses
void displayExpenses(struct Expense expenses[], int count) {
    // Check if any expenses have been added
    if (count == 0) {
        printf("No expenses added.\n");
        return;
    }
    // Display table header
    printf("%-20s %-10s\n", "Expense", "Cost");
    // Loop through expenses and display each one
    for (int i = 0; i < count; i++) {
        printf("%-20s $%-9.2f\n", expenses[i].name, expenses[i].cost);
    }
}

// Define function to calculate total expenses
float calculateTotalExpenses(struct Expense expenses[], int count) {
    // Initialize total to zero
    float total = 0;
    // Loop through expenses and add their costs to total
    for (int i = 0; i < count; i++) {
        total += expenses[i].cost;
    }
    return total;
}

// Define main function
int main() {
    // Create array to hold expenses
    struct Expense expenses[MAX_EXPENSES];
    // Initialize expense count to zero
    int count = 0;
    // Display menu and loop until user chooses to exit
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        // Get input from user and handle it
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculateTotalExpenses(expenses, count));
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}