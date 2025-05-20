//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESCRIPTION 50

// Structure to store transaction details
typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
    char type; // 'I' for income, 'E' for expense
} Transaction;

// Global variables
Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

// Function prototypes
void add_transaction();
void view_transactions();
void calculate_balance();
void menu();

int main() {
    menu();
    return 0;
}

// Display the menu and get user choice
void menu() {
    int choice;
    do {
        printf("\nPersonal Finance Planner Menu:\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Calculate Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                view_transactions();
                break;
            case 3:
                calculate_balance();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Function to add a new transaction
void add_transaction() {
    if (transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }
    Transaction new_transaction;
    printf("Enter transaction description: ");
    getchar(); // consume the newline character left by previous input
    fgets(new_transaction.description, MAX_DESCRIPTION, stdin);
    new_transaction.description[strcspn(new_transaction.description, "\n")] = 0; // remove newline

    printf("Enter transaction amount: ");
    scanf("%f", &new_transaction.amount);

    printf("Is it Income (I) or Expense (E)? ");
    getchar(); // consume the newline character
    new_transaction.type = getchar();

    transactions[transaction_count] = new_transaction;
    transaction_count++;
    printf("Transaction added successfully!\n");
}

// Function to view all transactions
void view_transactions() {
    if (transaction_count == 0) {
        printf("No transactions available.\n");
        return;
    }

    printf("\n--- Transactions ---\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("%d. %s: %.2f (%s)\n", i + 1, transactions[i].description, transactions[i].amount,
               transactions[i].type == 'I' ? "Income" : "Expense");
    }
    printf("-------------------\n");
}

// Function to calculate the current balance
void calculate_balance() {
    float balance = 0.0;
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].type == 'I') {
            balance += transactions[i].amount; // add income
        } else if (transactions[i].type == 'E') {
            balance -= transactions[i].amount; // subtract expense
        }
    }
    printf("Current balance: %.2f\n", balance);
}