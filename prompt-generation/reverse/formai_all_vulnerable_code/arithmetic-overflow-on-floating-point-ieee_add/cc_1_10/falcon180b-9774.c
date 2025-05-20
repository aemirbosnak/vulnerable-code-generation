//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

// Struct to represent a transaction
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    float amount;
} Transaction;

// Struct to represent a category
typedef struct {
    char name[MAX_NAME_LENGTH];
    float totalSpent;
} Category;

// Function to add a transaction
void addTransaction(Transaction* transaction, int numTransactions, Category* categories, int numCategories) {
    char input[100];
    printf("Enter transaction name: ");
    scanf("%s", input);
    strcpy(transaction->name, input);
    printf("Enter transaction category: ");
    scanf("%s", input);
    strcpy(transaction->category, input);
    printf("Enter transaction amount: ");
    scanf("%f", &transaction->amount);

    // Find the category and update its total spent
    int categoryIndex = -1;
    for (int i = 0; i < numCategories; i++) {
        if (strcmp(categories[i].name, transaction->category) == 0) {
            categoryIndex = i;
            break;
        }
    }
    if (categoryIndex == -1) {
        printf("Category not found. Creating new category.\n");
        strcpy(categories[numCategories].name, transaction->category);
        categories[numCategories].totalSpent = 0;
        numCategories++;
    } else {
        categories[categoryIndex].totalSpent += transaction->amount;
    }

    // Add the transaction to the list
    numTransactions++;
}

// Function to calculate the total spent in a category
float calculateTotalSpent(Category* category) {
    return category->totalSpent;
}

// Function to print a category's details
void printCategory(Category* category) {
    printf("Category: %s\n", category->name);
    printf("Total spent: $%.2f\n", calculateTotalSpent(category));
}

// Function to print all categories
void printCategories(Category* categories, int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        printCategory(&categories[i]);
    }
}

// Function to print all transactions
void printTransactions(Transaction* transactions, int numTransactions) {
    for (int i = 0; i < numTransactions; i++) {
        printf("Transaction %d:\n", i + 1);
        printf("Name: %s\n", transactions[i].name);
        printf("Category: %s\n", transactions[i].category);
        printf("Amount: $%.2f\n\n", transactions[i].amount);
    }
}

int main() {
    int numTransactions = 0;
    int numCategories = 0;

    // Initialize categories
    Category categories[MAX_CATEGORIES];
    strcpy(categories[numCategories].name, "Groceries");
    categories[numCategories].totalSpent = 0;
    numCategories++;

    // Add transactions
    Transaction transactions[MAX_TRANSACTIONS];
    while (numTransactions < MAX_TRANSACTIONS) {
        addTransaction(&transactions[numTransactions], numTransactions, categories, numCategories);
        numTransactions++;
    }

    // Print categories
    printf("Categories:\n");
    printCategories(categories, numCategories);

    // Print transactions
    printf("\nTransactions:\n");
    printTransactions(transactions, numTransactions);

    return 0;
}