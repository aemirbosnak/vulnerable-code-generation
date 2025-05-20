//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TRANSACTIONS 100

// Structure to hold a transaction record
typedef struct Transaction {
    int id;
    char date[11];
    char type[10];
    char description[50];
    float amount;
} Transaction;

// Global variables
Transaction transactions[MAX_TRANSACTIONS];
int numTransactions = 0;

// Function prototypes
void addTransaction();
void viewTransactions();
float getTotalExpense();

int main() {
    int option;

    // Loop until user decides to exit
    do {
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Get Total Expense\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addTransaction();
                break;

            case 2:
                viewTransactions();
                break;

            case 3:
                printf("Total Expense: %.2f\n", getTotalExpense());
                break;

            case 4:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        printf("\n");

    } while(option != 4);

    return 0;
}

void addTransaction() {
    Transaction t;

    // Get transaction details from user
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", t.date);
    printf("Enter type (eg. Food, Transport, Rent): ");
    scanf("%s", t.type);
    printf("Enter description: ");
    scanf("%s", t.description);
    printf("Enter amount: ");
    scanf("%f", &t.amount);

    // Assign a unique id to the transaction
    t.id = numTransactions + 1;

    // Add transaction to transactions array
    transactions[numTransactions++] = t;

    printf("Transaction added successfully\n");
}

void viewTransactions() {
    if(numTransactions == 0) {
        printf("No transactions found!\n");
        return;
    }

    printf("Transaction Records\n");
    printf("---------------------------------------------\n");

    printf("%-10s %-10s %-20s %-10s %-10s\n", "ID", "Date", "Type", "Description", "Amount");
    printf("---------------------------------------------\n");

    for(int i = 0; i < numTransactions; i++) {
        printf("%-10d %-10s %-20s %-10s %-10.2f\n",
            transactions[i].id,
            transactions[i].date,
            transactions[i].type,
            transactions[i].description,
            transactions[i].amount
        );
    }
}

float getTotalExpense() {
    float total = 0;

    for(int i = 0; i < numTransactions; i++) {
        total += transactions[i].amount;
    }

    return total;
}