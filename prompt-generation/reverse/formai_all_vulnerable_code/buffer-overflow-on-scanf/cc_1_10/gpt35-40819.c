//FormAI DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the expense information
struct Expense {
    char date[10];
    char category[20];
    float amount;
};

// Define a function to display the menu options and return the user's choice
int menu() {
    int choice;
    printf("\n-- Expense Tracker Menu --\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Define a function to add a new expense to the array
void addExpense(struct Expense expenses[], int *count) {
    printf("\nEnter the expense date (in mm/dd/yyyy format): ");
    scanf("%s", expenses[*count].date);
    printf("Enter the expense category: ");
    scanf("%s", expenses[*count].category);
    printf("Enter the expense amount: $");
    scanf("%f", &expenses[*count].amount);
    printf("Expense added successfully!\n");
    (*count)++;
}

// Define a function to display all the expenses in the array
void viewExpenses(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses found.\n");
    } else {
        printf("\n%-12s %-20s %s\n", "Date", "Category", "Amount");
        for (int i = 0; i < count; i++) {
            printf("%-12s %-20s $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
        }
    }
}

int main() {
    // Define array to hold expenses and counter for number of expenses
    struct Expense expenses[100];
    int count = 0;

    // Display menu and get user's choice
    int choice = menu();

    // Loop through menu options until user chooses to exit
    while (choice != 3) {
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        choice = menu();
    }

    // Exit program
    printf("\nGoodbye!\n");
    return 0;
}