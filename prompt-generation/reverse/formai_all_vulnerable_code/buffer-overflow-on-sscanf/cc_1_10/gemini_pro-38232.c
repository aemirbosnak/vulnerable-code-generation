//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define some constants
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10
#define MAX_CHAR_LENGTH 100

// Define some data structures
typedef struct {
    char name[MAX_CHAR_LENGTH];
    double amount;
    char category[MAX_CHAR_LENGTH];
    time_t date;
} transaction_t;

typedef struct {
    char name[MAX_CHAR_LENGTH];
    double budget;
    double actual;
} category_t;

// Define some functions
void add_transaction(transaction_t *transactions, int *num_transactions, char *name, double amount, char *category, time_t date);
void add_category(category_t *categories, int *num_categories, char *name, double budget);
void print_transactions(transaction_t *transactions, int num_transactions);
void print_categories(category_t *categories, int num_categories);
void print_menu();
void get_input(char *input);

// Main function
int main() {
    // Initialize some variables
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    category_t categories[MAX_CATEGORIES];
    int num_categories = 0;

    // Main loop
    while (true) {
        // Print the menu
        print_menu();

        // Get input from the user
        char input[MAX_CHAR_LENGTH];
        get_input(input);

        // Parse the input
        char command[MAX_CHAR_LENGTH];
        sscanf(input, "%s", command);

        // Execute the command
        if (strcmp(command, "add") == 0) {
            // Add a new transaction
            char name[MAX_CHAR_LENGTH];
            double amount;
            char category[MAX_CHAR_LENGTH];
            time_t date;

            printf("Enter the transaction name: ");
            scanf("%s", name);

            printf("Enter the transaction amount: ");
            scanf("%lf", &amount);

            printf("Enter the transaction category: ");
            scanf("%s", category);

            date = time(NULL);

            add_transaction(transactions, &num_transactions, name, amount, category, date);
        } else if (strcmp(command, "add_category") == 0) {
            // Add a new category
            char name[MAX_CHAR_LENGTH];
            double budget;

            printf("Enter the category name: ");
            scanf("%s", name);

            printf("Enter the category budget: ");
            scanf("%lf", &budget);

            add_category(categories, &num_categories, name, budget);
        } else if (strcmp(command, "print") == 0) {
            // Print the transactions and categories
            print_transactions(transactions, num_transactions);
            print_categories(categories, num_categories);
        } else if (strcmp(command, "exit") == 0) {
            // Exit the program
            break;
        } else {
            // Invalid command
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new transaction
void add_transaction(transaction_t *transactions, int *num_transactions, char *name, double amount, char *category, time_t date) {
    // Check if the number of transactions has reached the maximum
    if (*num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: The maximum number of transactions has been reached.\n");
        return;
    }

    // Add the new transaction to the array
    strcpy(transactions[*num_transactions].name, name);
    transactions[*num_transactions].amount = amount;
    strcpy(transactions[*num_transactions].category, category);
    transactions[*num_transactions].date = date;

    // Increment the number of transactions
    (*num_transactions)++;
}

// Function to add a new category
void add_category(category_t *categories, int *num_categories, char *name, double budget) {
    // Check if the number of categories has reached the maximum
    if (*num_categories >= MAX_CATEGORIES) {
        printf("Error: The maximum number of categories has been reached.\n");
        return;
    }

    // Add the new category to the array
    strcpy(categories[*num_categories].name, name);
    categories[*num_categories].budget = budget;
    categories[*num_categories].actual = 0.0;

    // Increment the number of categories
    (*num_categories)++;
}

// Function to print the transactions
void print_transactions(transaction_t *transactions, int num_transactions) {
    // Print the header
    printf("Transactions:\n");
    printf("------------------------------------------------------------------------------\n");
    printf("| Name | Amount | Category | Date |\n");
    printf("------------------------------------------------------------------------------\n");

    // Print the transactions
    for (int i = 0; i < num_transactions; i++) {
        printf("| %-20s | %-6.2f | %-10s | %s |\n", transactions[i].name, transactions[i].amount, transactions[i].category, ctime(&transactions[i].date));
    }

    // Print the footer
    printf("------------------------------------------------------------------------------\n");
}

// Function to print the categories
void print_categories(category_t *categories, int num_categories) {
    // Print the header
    printf("Categories:\n");
    printf("------------------------------------------------------------------------------\n");
    printf("| Name | Budget | Actual |\n");
    printf("------------------------------------------------------------------------------\n");

    // Print the categories
    for (int i = 0; i < num_categories; i++) {
        printf("| %-20s | %-6.2f | %-6.2f |\n", categories[i].name, categories[i].budget, categories[i].actual);
    }

    // Print the footer
    printf("------------------------------------------------------------------------------\n");
}

// Function to print the menu
void print_menu() {
    printf("Personal Finance Planner\n");
    printf("--------------------------\n");
    printf("Commands:\n");
    printf("  add: Add a new transaction\n");
    printf("  add_category: Add a new category\n");
    printf("  print: Print the transactions and categories\n");
    printf("  exit: Exit the program\n");
    printf("--------------------------\n");
}

// Function to get input from the user
void get_input(char *input) {
    // Get the input from the user
    fgets(input, MAX_CHAR_LENGTH, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';
}