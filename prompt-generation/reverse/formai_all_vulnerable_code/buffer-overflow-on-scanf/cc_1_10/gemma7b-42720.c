//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the structure of an expense
typedef struct Expense {
    char name[20];
    float amount;
    char category[20];
} Expense;

// Create an array of expenses
Expense expenses[MAX_EXPENSES];

// Function to add an expense
void addExpense() {
    // Get the expense name, amount, and category
    printf("Enter the expense name: ");
    scanf("%s", expenses[MAX_EXPENSES - 1].name);

    printf("Enter the expense amount: ");
    scanf("%f", &expenses[MAX_EXPENSES - 1].amount);

    printf("Enter the expense category: ");
    scanf("%s", expenses[MAX_EXPENSES - 1].category);
}

// Function to display all expenses
void displayExpenses() {
    // Print the list of expenses
    for (int i = 0; i < MAX_EXPENSES; i++) {
        if (expenses[i].name[0] != '\0') {
            printf("Name: %s, Amount: %.2f, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
        }
    }
}

// Function to calculate the total expense
float calculateTotalExpense() {
    // Calculate the total expense
    float totalExpense = 0.0;
    for (int i = 0; i < MAX_EXPENSES; i++) {
        if (expenses[i].name[0] != '\0') {
            totalExpense += expenses[i].amount;
        }
    }

    return totalExpense;
}

// Function to display the total expense
void displayTotalExpense() {
    // Display the total expense
    printf("Total expense: %.2f\n", calculateTotalExpense());
}

int main() {
    // Add some expenses
    addExpense();
    addExpense();
    addExpense();

    // Display the expenses
    displayExpenses();

    // Display the total expense
    displayTotalExpense();

    return 0;
}