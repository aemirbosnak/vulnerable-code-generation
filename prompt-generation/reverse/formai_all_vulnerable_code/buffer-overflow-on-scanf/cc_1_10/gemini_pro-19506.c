//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the main menu options
#define MENU_OPTION_ADD_INCOME 1
#define MENU_OPTION_ADD_EXPENSE 2
#define MENU_OPTION_VIEW_TRANSACTIONS 3
#define MENU_OPTION_QUIT 4

// Define the data structures for income and expenses
typedef struct {
    char description[50];
    float amount;
} Income;

typedef struct {
    char description[50];
    float amount;
} Expense;

// Create an array to store the income and expenses
Income incomes[100];
Expense expenses[100];

// Initialize the number of income and expenses to 0
int num_incomes = 0;
int num_expenses = 0;

// Function to add a new income
void add_income() {
    // Get the description of the income
    printf("Enter the description of the income: ");
    scanf("%s", incomes[num_incomes].description);

    // Get the amount of the income
    printf("Enter the amount of the income: ");
    scanf("%f", &incomes[num_incomes].amount);

    // Increment the number of incomes
    num_incomes++;
}

// Function to add a new expense
void add_expense() {
    // Get the description of the expense
    printf("Enter the description of the expense: ");
    scanf("%s", expenses[num_expenses].description);

    // Get the amount of the expense
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[num_expenses].amount);

    // Increment the number of expenses
    num_expenses++;
}

// Function to view all transactions
void view_transactions() {
    // Print the income transactions
    printf("\nIncomes:\n");
    for (int i = 0; i < num_incomes; i++) {
        printf("%s: $%.2f\n", incomes[i].description, incomes[i].amount);
    }

    // Print the expense transactions
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }
}

// Function to quit the program
void quit() {
    // Exit the program with a status code of 0
    exit(0);
}

// Function to display the main menu
void display_main_menu() {
    // Clear the screen
    system("cls");

    // Print the main menu options
    printf("Personal Finance Planner\n");
    printf("---------------------\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Transactions\n");
    printf("4. Quit\n");
}

// Function to get the user's choice
int get_user_choice() {
    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Return the user's choice
    return choice;
}

// Main function
int main() {
    // Display the main menu
    display_main_menu();

    // Get the user's choice
    int choice = get_user_choice();

    // Loop until the user chooses to quit
    while (choice != MENU_OPTION_QUIT) {
        // Handle the user's choice
        switch (choice) {
            case MENU_OPTION_ADD_INCOME:
                add_income();
                break;
            case MENU_OPTION_ADD_EXPENSE:
                add_expense();
                break;
            case MENU_OPTION_VIEW_TRANSACTIONS:
                view_transactions();
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

        // Display the main menu again
        display_main_menu();

        // Get the user's choice again
        choice = get_user_choice();
    }

    // Quit the program
    quit();

    return 0;
}