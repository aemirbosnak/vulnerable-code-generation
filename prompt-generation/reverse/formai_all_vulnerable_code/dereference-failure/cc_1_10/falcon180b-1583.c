//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a transaction
typedef struct {
    char *description;
    double amount;
    int month;
    int day;
    int year;
} Transaction;

// Function to add a transaction
void addTransaction(Transaction *transactions, int numTransactions, char *description, double amount, int month, int day, int year) {
    if (numTransactions == 0) {
        transactions = (Transaction *) malloc(sizeof(Transaction));
        numTransactions = 1;
    } else {
        transactions = (Transaction *) realloc(transactions, sizeof(Transaction) * numTransactions + 1);
        numTransactions++;
    }
    transactions[numTransactions - 1].description = description;
    transactions[numTransactions - 1].amount = amount;
    transactions[numTransactions - 1].month = month;
    transactions[numTransactions - 1].day = day;
    transactions[numTransactions - 1].year = year;
}

// Function to display a transaction
void displayTransaction(Transaction transaction) {
    printf("Transaction: %s\n", transaction.description);
    printf("Amount: $%.2f\n", transaction.amount);
    printf("Date: %d/%d/%d\n", transaction.month, transaction.day, transaction.year);
    printf("\n");
}

// Function to calculate the total amount spent in a given month and year
double calculateTotal(Transaction *transactions, int numTransactions, int month, int year) {
    double total = 0;
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].month == month && transactions[i].year == year) {
            total += transactions[i].amount;
        }
    }
    return total;
}

// Function to calculate the average amount spent in a given month and year
double calculateAverage(Transaction *transactions, int numTransactions, int month, int year) {
    double total = calculateTotal(transactions, numTransactions, month, year);
    if (total == 0) {
        return 0;
    }
    return total / numTransactions;
}

// Function to display a summary of transactions in a given month and year
void displaySummary(Transaction *transactions, int numTransactions, int month, int year) {
    double total = calculateTotal(transactions, numTransactions, month, year);
    double average = calculateAverage(transactions, numTransactions, month, year);
    printf("Summary for %d/%d:\n", month, year);
    printf("Total amount spent: $%.2f\n", total);
    printf("Average amount spent: $%.2f\n", average);
    printf("\n");
}

int main() {
    // Initialize the array of transactions
    Transaction transactions[0];
    int numTransactions = 0;

    // Add some transactions
    addTransaction(transactions, numTransactions, "Groceries", 100.50, 1, 1, 2021);
    addTransaction(transactions, numTransactions, "Rent", 1000.00, 1, 1, 2021);
    addTransaction(transactions, numTransactions, "Utilities", 150.00, 1, 1, 2021);
    addTransaction(transactions, numTransactions, "Entertainment", 50.00, 1, 1, 2021);

    // Display all transactions
    printf("All transactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        displayTransaction(transactions[i]);
    }

    // Display summary for January 2021
    displaySummary(transactions, numTransactions, 1, 2021);

    return 0;
}