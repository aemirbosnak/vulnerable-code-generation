//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESCRIPTION 100

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
    int type; // 1 for income, -1 for expense
} Transaction;

int main() {
    // Create an array of transactions
    Transaction transactions[MAX_TRANSACTIONS];

    // Get the number of transactions from the user
    int numTransactions;
    printf("How many transactions would you like to enter? ");
    scanf("%d", &numTransactions);

    // Get the details of each transaction from the user
    for (int i = 0; i < numTransactions; i++) {
        printf("Enter the description of transaction %d: ", i + 1);
        scanf(" %[^\n]", transactions[i].description);

        printf("Enter the amount of transaction %d: ", i + 1);
        scanf("%f", &transactions[i].amount);

        // Get the type of transaction from the user
        int type;
        printf("Enter the type of transaction %d (1 for income, -1 for expense): ", i + 1);
        scanf("%d", &type);
        transactions[i].type = type;
    }

    // Calculate the total income and expenses
    float totalIncome = 0;
    float totalExpenses = 0;
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].type == 1) {
            totalIncome += transactions[i].amount;
        } else {
            totalExpenses += transactions[i].amount;
        }
    }

    // Print the total income and expenses
    printf("Total income: $%.2f\n", totalIncome);
    printf("Total expenses: $%.2f\n", totalExpenses);

    // Calculate the net income
    float netIncome = totalIncome - totalExpenses;

    // Print the net income
    printf("Net income: $%.2f\n", netIncome);

    return 0;
}