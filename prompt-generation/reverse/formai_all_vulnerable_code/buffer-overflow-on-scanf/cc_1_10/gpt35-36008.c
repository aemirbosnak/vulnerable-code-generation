//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare structure for expense record
struct ExpenseRecord {
    char date[11];
    char category[20];
    float amount;
};

// Define function to add expenses to record
void addExpense(struct ExpenseRecord record[], int size) {
    printf("\nEnter the date of the expense (MM/DD/YYYY):\n");
    scanf("%s", record[size].date);
    printf("\nEnter the category of the expense:\n");
    scanf("%s", record[size].category);
    printf("\nEnter the amount of the expense:\n");
    scanf("%f", &record[size].amount);
    printf("\nExpense added successfully!\n");
}

// Define function to display all expenses in record
void displayExpenses(struct ExpenseRecord record[], int size) {
    printf("\n%-15s %-20s %-10s\n", "Date", "Category", "Amount");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-15s %-20s $%-9.2f\n", record[i].date, record[i].category, record[i].amount);
    }
}

// Define function to calculate total expenses for a given category
float calculateTotalExpenses(struct ExpenseRecord record[], int size, char category[]) {
    float totalExpenses = 0.0;
    for (int i = 0; i < size; i++) {
        if (strcmp(record[i].category, category) == 0) {
            totalExpenses += record[i].amount;
        }
    }
    return totalExpenses;
}

int main() {
    // Declare variable to hold number of expenses
    int numExpenses = 0;
    // Declare array of ExpenseRecords
    struct ExpenseRecord expenses[100];

    // Print welcome message and menu options
    printf("\nWelcome to the Expense Tracker!\n");
    printf("Please select an option:\n");
    printf("1. Add an expense\n");
    printf("2. Display all expenses\n");
    printf("3. Calculate total expenses for a category\n");
    printf("4. Exit\n");

    // Loop until exit option selected
    int option = 0;
    while (option != 4) {
        // Prompt user for option
        printf("\nEnter an option: ");
        scanf("%d", &option);

        // Perform action based on selected option
        switch (option) {
            case 1:
                addExpense(expenses, numExpenses);
                numExpenses++;
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("\nEnter the category to calculate total expenses for:\n");
                char category[20];
                scanf("%s", category);
                float totalExpenses = calculateTotalExpenses(expenses, numExpenses, category);
                printf("\nThe total expenses for category '%s' is $%.2f\n", category, totalExpenses);
                break;
            case 4:
                printf("\nExiting Expense Tracker...\n");
                break;
            default:
                printf("\nInvalid option, please try again!\n");
                break;
        }
    }

    return 0;
}