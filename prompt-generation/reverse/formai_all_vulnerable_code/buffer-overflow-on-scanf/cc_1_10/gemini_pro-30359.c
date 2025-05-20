//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Data structures
typedef struct {
    char name[50];
    double amount;
} Transaction;

typedef struct {
    char name[50];
    double budget;
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} Category;

// Function prototypes
void add_transaction(Category *category, Transaction transaction);
void print_category(Category category);
void print_all_categories(Category categories[], int num_categories);

// Main function
int main() {
    // Create an array of categories
    Category categories[MAX_CATEGORIES];

    // Get the number of categories from the user
    int num_categories;
    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    // Get the details of each category
    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);

        printf("Enter the budget for category %d: ", i + 1);
        scanf("%lf", &categories[i].budget);

        // Initialize the number of transactions to 0
        categories[i].num_transactions = 0;
    }

    // Get the transactions for each category
    for (int i = 0; i < num_categories; i++) {
        printf("Enter the number of transactions for category %s: ", categories[i].name);
        scanf("%d", &categories[i].num_transactions);

        // Get the details of each transaction
        for (int j = 0; j < categories[i].num_transactions; j++) {
            printf("Enter the name of transaction %d for category %s: ", j + 1, categories[i].name);
            scanf("%s", categories[i].transactions[j].name);

            printf("Enter the amount of transaction %d for category %s: ", j + 1, categories[i].name);
            scanf("%lf", &categories[i].transactions[j].amount);
        }
    }

    // Print the details of each category
    print_all_categories(categories, num_categories);

    return 0;
}

// Function to add a transaction to a category
void add_transaction(Category *category, Transaction transaction) {
    // Check if the number of transactions has reached the maximum
    if (category->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: The maximum number of transactions has been reached.\n");
        return;
    }

    // Add the transaction to the category
    category->transactions[category->num_transactions++] = transaction;
}

// Function to print the details of a category
void print_category(Category category) {
    printf("Category: %s\n", category.name);
    printf("Budget: %.2lf\n", category.budget);
    printf("Transactions:\n");
    for (int i = 0; i < category.num_transactions; i++) {
        printf(" - %s: %.2lf\n", category.transactions[i].name, category.transactions[i].amount);
    }
    printf("\n");
}

// Function to print the details of all categories
void print_all_categories(Category categories[], int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        print_category(categories[i]);
    }
}