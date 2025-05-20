//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the maximum length of a transaction description
#define MAX_DESCRIPTION_LENGTH 100

// Define the different transaction types
typedef enum {
    INCOME,
    EXPENSE
} transaction_type;

// Define a transaction struct
typedef struct {
    transaction_type type;
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
} transaction;

// Function to print the main menu
void print_main_menu() {
    printf("Personal Finance Planner\n");
    printf("------------------------\n");
    printf("1. Add a transaction\n");
    printf("2. View transactions\n");
    printf("3. Calculate net worth\n");
    printf("4. Quit\n");
}

// Function to get the user's input
int get_user_input(int min, int max) {
    int input;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        }
    }
}

// Function to add a transaction
void add_transaction(transaction *transactions, int *num_transactions) {
    // Get the transaction type
    printf("Enter the transaction type (1 for income, 2 for expense): ");
    scanf("%d", &transactions[*num_transactions].type);

    // Get the transaction description
    printf("Enter the transaction description: ");
    scanf(" %[^\n]%*c", transactions[*num_transactions].description);

    // Get the transaction amount
    printf("Enter the transaction amount: ");
    scanf("%lf", &transactions[*num_transactions].amount);

    // Increment the number of transactions
    (*num_transactions)++;
}

// Function to view transactions
void view_transactions(transaction *transactions, int num_transactions) {
    printf("Transactions:\n");
    printf("------------------------\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. Type: %s, Description: %s, Amount: %lf\n", i + 1, transactions[i].type == INCOME ? "Income" : "Expense", transactions[i].description, transactions[i].amount);
    }
}

// Function to calculate net worth
double calculate_net_worth(transaction *transactions, int num_transactions) {
    double net_worth = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == INCOME) {
            net_worth += transactions[i].amount;
        } else {
            net_worth -= transactions[i].amount;
        }
    }
    return net_worth;
}

// Function to quit the program
void quit() {
    printf("Thank you for using the Personal Finance Planner.\n");
    exit(0);
}

// Main function
int main() {
    // Array to store the transactions
    transaction transactions[MAX_TRANSACTIONS];

    // Number of transactions
    int num_transactions = 0;

    // Main loop
    while (1) {
        // Print the main menu
        print_main_menu();

        // Get the user's input
        int choice = get_user_input(1, 4);

        // Call the appropriate function based on the user's input
        switch (choice) {
            case 1:
                add_transaction(transactions, &num_transactions);
                break;
            case 2:
                view_transactions(transactions, num_transactions);
                break;
            case 3:
                printf("Your net worth is: %lf\n", calculate_net_worth(transactions, num_transactions));
                break;
            case 4:
                quit();
                break;
        }
    }

    return 0;
}