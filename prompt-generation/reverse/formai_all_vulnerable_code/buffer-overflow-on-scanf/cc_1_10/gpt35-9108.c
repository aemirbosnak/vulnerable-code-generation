//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structure to hold each expense entry
typedef struct {
    char date[11];
    char description[50];
    float amount;
} Expense;

// Display main menu options to user
void displayMenu(void) {
    printf("\n--- Expense Tracker ---\n\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. View expenses by date\n");
    printf("4. Exit program\n");
}

// Get user input and validate it
int getIntInput(void) {
    char input[10];
    int validInput = 0;

    while (!validInput) {
        printf("Enter your choice (1-4): ");
        scanf("%s", input);

        // Check if input is a positive integer between 1-4
        if (isdigit(input[0])) {
            int choice = atoi(input);
            if (choice >= 1 && choice <= 4) {
                return choice;
            }
        }

        printf("Invalid input. Please enter a positive integer between 1-4\n");
        fflush(stdin);
    }
}

// Function to add a new expense
void addExpense(Expense expenses[], int *numExpenses) {
    printf("\n--- Adding New Expense ---\n");

    // Get date of expense
    char date[11];
    printf("Enter date of expense (MM/DD/YYYY): ");
    scanf("%s", date);

    // Get description of expense
    char description[50];
    printf("Enter description of expense: ");
    getchar(); // Consume newline character from previous input
    fgets(description, 50, stdin);
    description[strcspn(description, "\n")] = '\0'; // Remove newline character from description

    // Get amount of expense
    float amount;
    printf("Enter amount of expense: ");
    scanf("%f", &amount);

    // Create new expense entry and add it to array of expenses
    Expense newExpense = {date, description, amount};
    expenses[*numExpenses] = newExpense;

    printf("Expense added successfully!\n");
    *numExpenses += 1;
}

// Function to print all expenses to console
void viewAllExpenses(Expense expenses[], int numExpenses) {
    printf("\n--- All Expenses ---\n");

    // Check if there are any expenses in array
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    // Print header row
    printf("%-15s %-50s %-10s\n", "Date", "Description", "Amount");

    // Loop through expenses array and print each entry
    for (int i = 0; i < numExpenses; i++) {
        printf("%-15s %-50s $%-10.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
    }
}

// Function to print expenses by date to console
void viewExpensesByDate(Expense expenses[], int numExpenses) {
    printf("\n--- Expenses by Date ---\n");

    // Check if there are any expenses in array
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    // Get date to filter expenses by
    char date[11];
    printf("Enter date to filter expenses (MM/DD/YYYY): ");
    scanf("%s", date);

    // Print header row
    printf("%-50s %-10s\n", "Description", "Amount");

    // Loop through expenses array and print entries with matching date
    int entriesFound = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, date) == 0) {
            printf("%-50s $%-10.2f\n", expenses[i].description, expenses[i].amount);
            entriesFound = 1;
        }
    }

    // Check if any entries were found for given date
    if (!entriesFound) {
        printf("No expenses found for given date.\n");
    }
}

int main(void) {
    // Initialize array to hold expenses and number of expenses
    Expense expenses[100];
    int numExpenses = 0;

    int choice;

    do {
        displayMenu();
        choice = getIntInput();

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewAllExpenses(expenses, numExpenses);
                break;
            case 3:
                viewExpensesByDate(expenses, numExpenses);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
        }
    } while (choice != 4);

    return 0;
}