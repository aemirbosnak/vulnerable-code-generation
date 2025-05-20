//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for transactions
typedef struct {
    char description[50];
    float amount;
    int category;
} Transaction;

// Define arrays for categories
const char* categories[] = {
    "Groceries",
    "Rent",
    "Utilities",
    "Transportation",
    "Entertainment",
    "Miscellaneous"
};

// Define constants for category indices
#define NUM_CATEGORIES 6
#define MAX_TRANSACTIONS 100

// Global variables
float balance = 0.0;
Transaction transactions[MAX_TRANSACTIONS];
int numTransactions = 0;

// Function to display available categories
void displayCategories() {
    int i;
    for (i = 0; i < NUM_CATEGORIES; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
}

// Function to add a transaction
void addTransaction() {
    if (numTransactions >= MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter transaction description: ");
    scanf("%s", transactions[numTransactions].description);

    printf("Enter transaction amount: ");
    scanf("%f", &transactions[numTransactions].amount);

    printf("Enter transaction category (1-6): ");
    int categoryInput;
    scanf("%d", &categoryInput);

    transactions[numTransactions].category = categoryInput - 1;
    balance += transactions[numTransactions].amount;
    numTransactions++;
}

// Function to display transactions
void displayTransactions() {
    int i;
    for (i = 0; i < numTransactions; i++) {
        printf("%s: %.2f (Category: %d)\n", transactions[i].description, transactions[i].amount, transactions[i].category + 1);
        balance -= transactions[i].amount;
    }
    printf("Total balance: %.2f\n", balance);
}

int main() {
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                displayTransactions();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}