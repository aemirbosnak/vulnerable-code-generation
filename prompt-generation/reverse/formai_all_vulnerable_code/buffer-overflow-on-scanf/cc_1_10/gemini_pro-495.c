//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction type enum
typedef enum {
    INCOME,
    EXPENSE
} transaction_type;

// Define the transaction struct
typedef struct {
    char description[50];
    double amount;
    transaction_type type;
} transaction;

// Declare the array of transactions
transaction transactions[MAX_TRANSACTIONS];

// Declare the current number of transactions
int num_transactions = 0;

// Declare the functions
void add_transaction(char *description, double amount, transaction_type type);
void print_transactions();
void calculate_balance();

// Get the user input
int main() {

    //Add a juicy banner
    printf("\n############################################################\n");
    printf("                   CASH MONEY FINANCE PLANNER                  \n");
    printf("############################################################\n");
    int choice;
    char description[50];
    double amount;
    transaction_type type;

    while (1) {
        // Display the menu
        printf("\nWhat would you like to do?\n");
        printf("1. Add a transaction\n");
        printf("2. Print the transactions\n");
        printf("3. Calculate the balance\n");
        printf("4. Quit\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {

            case 1:
                // Get the transaction details
                printf("\nEnter the transaction description: ");
                scanf(" %[^\n]%*c", description);
                printf("\nEnter the transaction amount: ");
                scanf("%lf", &amount);
                printf("\nEnter the transaction type (1 for income, 2 for expense): ");
                scanf("%d", &type);
                // Add the transaction
                add_transaction(description, amount, type);
                break;

            case 2:
                // Print the transactions
                print_transactions();
                break;

            case 3:
                // Calculate the balance
                calculate_balance();
                break;

            case 4:
                // Quit the program
                printf("\nMay your bank account always overflow, ciao!\n");
                return 0;

            default:
                // Invalid choice
                printf("\nInvalid choice, please try again.");
        }
    }

    return 0;
}

// Add a transaction to the array
void add_transaction(char *description, double amount, transaction_type type) {
    // Check if the array is full
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("\nError: The array of transactions is full.");
        return;
    }

    // Add the transaction to the array
    transactions[num_transactions].type = type;
    strcpy(transactions[num_transactions].description, description);
    transactions[num_transactions].amount = amount;

    // Increment the number of transactions
    num_transactions++;
}

// Print the transactions in the array
void print_transactions() {

    if(num_transactions == 0) {
      printf("\nNo transactions to display.\n");
      return;
    }

    // Print the header
    printf("\n%-5s   %-30s   %-10s\n", "Type", "Description", "Amount");

    // Print each transaction
    for (int i = 0; i < num_transactions; i++) {
        printf("%-5s   %-30s   %10.2f\n",
            transactions[i].type == INCOME ? "Income" : "Expense",
            transactions[i].description,
            transactions[i].amount);
    }
}

// Calculate the balance
void calculate_balance() {
    // Calculate the total income
    double total_income = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == INCOME) {
            total_income += transactions[i].amount;
        }
    }

    // Calculate the total expense
    double total_expense = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == EXPENSE) {
            total_expense += transactions[i].amount;
        }
    }

    // Calculate the balance
    double balance = total_income - total_expense;

    // Print the balance
    printf("\nYour balance is: $%.2f\n", balance);
}