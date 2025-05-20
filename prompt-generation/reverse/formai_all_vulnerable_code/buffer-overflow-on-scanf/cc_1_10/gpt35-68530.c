//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the struct for an expense
typedef struct {
    char date[11];
    char category[50];
    char description[100];
    float amount;
} Expense;

// Define global variables
Expense expenses[100];
int expenseCount = 0;

// Define function to add expense record
void addExpense() {
    Expense newExpense;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);
    printf("Enter category: ");
    scanf("%s", newExpense.category);
    printf("Enter description: ");
    scanf("%s", newExpense.description);
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    expenses[expenseCount] = newExpense;
    expenseCount++;
    printf("Expense added successfully!\n");
}

// Define function to display all expenses
void displayExpenses() {
    printf("Date\t\tCategory\tDescription\tAmount\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%s\t%s\t%s\t%.2f\n", expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

// Define function to calculate and display total expenses
void displayTotalExpenses() {
    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

// Define main function
int main() {
    int choice = 0;
    while (choice != 4) {
        printf("\nExpense Tracker Menu:\n1. Add Expense\n2. Display All Expenses\n3. Display Total Expenses\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                displayTotalExpenses();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}