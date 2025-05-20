//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: authentic
/*
 * Expense Tracker Program
 *
 * A program that allows users to keep track of their expenses
 * and generate a report of their spending habits.
 *
 * Usage:
 * 1. Compile the program using the command `gcc -o expense_tracker expense_tracker.c`
 * 2. Run the program using the command `./expense_tracker`
 * 3. Follow the prompts to add expenses, view the report, and exit the program
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store expense information
struct Expense {
    char description[100];
    float amount;
    int date;
};

// Global variables
struct Expense *expenses;
int num_expenses = 0;

// Function to add an expense
void add_expense() {
    // Prompt the user for expense information
    printf("Enter the description of the expense: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter the date of the expense (YYYYMMDD): ");
    scanf("%d", &expenses[num_expenses].date);

    // Increment the number of expenses
    num_expenses++;
}

// Function to view the expense report
void view_report() {
    // Print the expense report
    printf("Expense Report:\n");
    printf("----------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2f - %d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

// Main function
int main() {
    // Initialize the expenses array
    expenses = (struct Expense *) malloc(sizeof(struct Expense) * 100);

    // Main menu
    int option;
    do {
        printf("Welcome to the Expense Tracker Program\n");
        printf("------------------------------------\n");
        printf("1. Add an expense\n");
        printf("2. View the expense report\n");
        printf("3. Exit the program\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        // Add an expense
        if (option == 1) {
            add_expense();
        }
        // View the expense report
        else if (option == 2) {
            view_report();
        }
        // Exit the program
        else if (option == 3) {
            break;
        }
    } while (1);

    // Free the memory
    free(expenses);

    return 0;
}