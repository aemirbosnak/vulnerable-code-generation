//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Global variables to store user's income and expenses
float income = 0, expenses = 0;

// Function to display the main menu
void displayMenu() {
    printf("PERSONAL FINANCE PLANNER\n");
    printf("------------------------\n\n");
    printf("1. Enter Income\n");
    printf("2. Enter Expenses\n");
    printf("3. View Income\n");
    printf("4. View Expenses\n");
    printf("5. Calculate Savings\n");
    printf("6. Exit\n\n");
}

// Function to get user's choice from the menu
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get user's income
void getIncome() {
    printf("\nEnter your monthly income: $");
    scanf("%f", &income);
    printf("Income added successfully!\n\n");
}

// Function to get user's expenses
void getExpenses() {
    float expense;
    char choice;
    do {
        printf("\nEnter your monthly expenses: $");
        scanf("%f", &expense);
        expenses += expense;
        printf("Expense added successfully!\n");
        printf("Do you want to add another expense? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to clear the input buffer
    } while(choice == 'y' || choice == 'Y');
    printf("\n");
}

// Function to display user's income
void showIncome() {
    printf("\nYour monthly income is: $%.2f\n\n", income);
}

// Function to display user's expenses
void showExpenses() {
    printf("\nYour monthly expenses are: $%.2f\n\n", expenses);
}

// Function to calculate user's savings
void calculateSavings() {
    float savings = income - expenses;
    if (savings > 0) {
        printf("\nCongratulations! You are saving $%.2f per month!\n\n", savings);
    } else if (savings < 0) {
        printf("\nUh-oh! You are spending $%.2f more than you are earning!\n\n", -savings);
    } else {
        printf("\nYour income and expenses are balanced. You are not saving anything.\n\n");
    }
}

int main() {
    int choice;
    do {
        system("clear"); // Clear the screen on each iteration
        displayMenu();
        choice = getChoice();
        switch(choice) {
            case 1: getIncome(); break;
            case 2: getExpenses(); break;
            case 3: showIncome(); break;
            case 4: showExpenses(); break;
            case 5: calculateSavings(); break;
            case 6: printf("Thank you for using Personal Finance Planner!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
        printf("Press enter to continue...");
        while(getchar() != '\n'); // Clear the input buffer
        getchar(); // Wait for user to press enter
    } while(choice != 6);
    return 0;
}