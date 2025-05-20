//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A transaction record
typedef struct {
    char description[50]; // Description of the transaction
    float amount;        // Amount of the transaction
    int type;            // Type of the transaction (1 for income, 0 for expense)
} Transaction;

// The main function
int main() {
    // Declare an array of transactions
    Transaction transactions[100];

    // Get the number of transactions from the user
    int num_transactions;
    printf("How many transactions do you want to enter? ");
    scanf("%d", &num_transactions);

    // Get the details of each transaction from the user
    for (int i = 0; i < num_transactions; i++) {
        printf("Enter the description of transaction %d: ", i + 1);
        scanf(" %[^\n]%*c", transactions[i].description); // Read a line of text with spaces
        printf("Enter the amount of transaction %d: ", i + 1);
        scanf("%f", &transactions[i].amount);
        printf("Enter the type of transaction %d (1 for income, 0 for expense): ", i + 1);
        scanf("%d", &transactions[i].type);
    }

    // Calculate the total income and expenses
    float total_income = 0;
    float total_expenses = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 1) {
            total_income += transactions[i].amount;
        } else {
            total_expenses += transactions[i].amount;
        }
    }

    // Print the total income and expenses
    printf("Total income: %.2f\n", total_income);
    printf("Total expenses: %.2f\n", total_expenses);

    // Calculate the net balance
    float net_balance = total_income - total_expenses;

    // Print the net balance
    if (net_balance >= 0) {
        printf("Net balance: %.2f\n", net_balance);
    } else {
        printf("Net balance: (%.2f)\n", -net_balance);
    }

    return 0;
}