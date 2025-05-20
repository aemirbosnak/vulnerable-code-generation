//FormAI DATASET v1.0 Category: Expense Tracker ; Style: lively
// Welcome to your Expense Tracker program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for keeping track of expenses
struct Expense {
    char name[50];
    char date[20];
    float amount;
};

// Function to add a new expense
void addExpense(struct Expense expenses[], int *numExpenses) {
    char name[50], date[20];
    float amount;
    printf("Enter name of expense: ");
    scanf(" %[^\n]", name);
    printf("Enter date of expense (DD/MM/YYYY): ");
    scanf(" %s", date);
    printf("Enter amount of expense: ");
    scanf(" %f", &amount);
    struct Expense newExpense;
    strcpy(newExpense.name, name);
    strcpy(newExpense.date, date);
    newExpense.amount = amount;
    expenses[*numExpenses] = newExpense;
    *numExpenses += 1;
    printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses(struct Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. Name: %s | Date: %s | Amount: Rs.%.2f\n", i+1, expenses[i].name, expenses[i].date, expenses[i].amount);
    }
}

// Function to calculate total expenses
float calculateTotal(struct Expense expenses[], int numExpenses) {
    float total = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    int choice, numExpenses = 0;
    struct Expense expenses[50];
    printf("Welcome to your Expense Tracker!\n");
    do {
        printf("\nWhat would you like to do?\n1. Add a new expense\n2. View all expenses\n3. Calculate total expenses\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expenses: Rs.%.2f\n", calculateTotal(expenses, numExpenses));
                break;
            case 4:
                printf("Thank you for using your Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}