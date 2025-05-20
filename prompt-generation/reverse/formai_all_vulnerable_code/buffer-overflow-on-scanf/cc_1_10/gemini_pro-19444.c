//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store income and expense details
typedef struct {
    char description[50];
    float amount;
} Transaction;

// Function to get user input
void getInput(char *prompt, float *value) {
    printf("%s", prompt);
    scanf("%f", value);
}

// Function to calculate total income
float calculateTotalIncome(Transaction *transactions, int numTransactions) {
    float totalIncome = 0;
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].amount > 0) {
            totalIncome += transactions[i].amount;
        }
    }
    return totalIncome;
}

// Function to calculate total expenses
float calculateTotalExpenses(Transaction *transactions, int numTransactions) {
    float totalExpenses = 0;
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].amount < 0) {
            totalExpenses += transactions[i].amount;
        }
    }
    return totalExpenses;
}

// Function to print transaction details
void printTransactions(Transaction *transactions, int numTransactions) {
    printf("Transactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%s: %f\n", transactions[i].description, transactions[i].amount);
    }
}

// Function to print financial summary
void printSummary(float totalIncome, float totalExpenses) {
    printf("\nFinancial Summary:\n");
    printf("Total Income: %f\n", totalIncome);
    printf("Total Expenses: %f\n", totalExpenses);
    printf("Net Income: %f\n", totalIncome + totalExpenses);
}

int main() {
    // Number of transactions
    int numTransactions;
    getInput("Enter the number of transactions: ", &numTransactions);

    // Array to store transaction details
    Transaction transactions[numTransactions];

    // Get transaction details from the user
    for (int i = 0; i < numTransactions; i++) {
        printf("\nEnter details for transaction %d:\n", i + 1);
        getInput("Description: ", transactions[i].description);
        getInput("Amount: ", &transactions[i].amount);
    }

    // Calculate total income and expenses
    float totalIncome = calculateTotalIncome(transactions, numTransactions);
    float totalExpenses = calculateTotalExpenses(transactions, numTransactions);

    // Print transaction details
    printTransactions(transactions, numTransactions);

    // Print financial summary
    printSummary(totalIncome, totalExpenses);

    return 0;
}