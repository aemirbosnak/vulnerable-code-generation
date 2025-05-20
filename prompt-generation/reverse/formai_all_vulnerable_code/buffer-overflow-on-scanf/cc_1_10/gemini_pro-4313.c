//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions and categories
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

// Define the transaction structure
typedef struct {
    char description[50];
    float amount;
    int category;
} transaction;

// Define the category structure
typedef struct {
    char name[20];
    float total;
} category;

// Declare the global variables
transaction transactions[MAX_TRANSACTIONS];
category categories[MAX_CATEGORIES];
int num_transactions = 0;
int num_categories = 0;

// Function to add a transaction
void add_transaction(char *description, float amount, int category) {
    // Check if the number of transactions has reached the maximum
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    // Add the transaction to the array
    strcpy(transactions[num_transactions].description, description);
    transactions[num_transactions].amount = amount;
    transactions[num_transactions].category = category;

    // Increment the number of transactions
    num_transactions++;

    // Update the total for the category
    categories[category].total += amount;
}

// Function to add a category
void add_category(char *name) {
    // Check if the number of categories has reached the maximum
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }

    // Add the category to the array
    strcpy(categories[num_categories].name, name);
    categories[num_categories].total = 0;

    // Increment the number of categories
    num_categories++;
}

// Function to print the transactions
void print_transactions() {
    // Print the header
    printf("Transactions:\n");

    // Print the transactions
    for (int i = 0; i < num_transactions; i++) {
        printf("  %s: $%.2f (category %d)\n",
            transactions[i].description,
            transactions[i].amount,
            transactions[i].category);
    }
}

// Function to print the categories
void print_categories() {
    // Print the header
    printf("Categories:\n");

    // Print the categories
    for (int i = 0; i < num_categories; i++) {
        printf("  %s: $%.2f\n",
            categories[i].name,
            categories[i].total);
    }
}

// Function to get the user input
void get_user_input() {
    // Get the number of transactions
    printf("Enter the number of transactions: ");
    int num_transactions_input;
    scanf("%d", &num_transactions_input);

    // Add the transactions
    for (int i = 0; i < num_transactions_input; i++) {
        // Get the description
        printf("Enter the description: ");
        char description[50];
        scanf(" %[^\n]", description);

        // Get the amount
        printf("Enter the amount: ");
        float amount;
        scanf("%f", &amount);

        // Get the category
        printf("Enter the category: ");
        int category;
        scanf("%d", &category);

        // Add the transaction
        add_transaction(description, amount, category);
    }

    // Get the number of categories
    printf("Enter the number of categories: ");
    int num_categories_input;
    scanf("%d", &num_categories_input);

    // Add the categories
    for (int i = 0; i < num_categories_input; i++) {
        // Get the name
        printf("Enter the name: ");
        char name[20];
        scanf(" %[^\n]", name);

        // Add the category
        add_category(name);
    }
}

// Main function
int main() {
    // Get the user input
    get_user_input();

    // Print the transactions
    print_transactions();

    // Print the categories
    print_categories();

    return 0;
}