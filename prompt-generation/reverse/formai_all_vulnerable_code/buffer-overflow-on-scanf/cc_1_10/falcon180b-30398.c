//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

struct Transaction {
    char description[100];
    double amount;
    time_t date;
};

int main() {
    int numTransactions = 0;
    struct Transaction transactions[MAX_TRANSACTIONS];

    // Prompt the user for their name
    printf("What is thy name, dear user?\n");
    scanf("%s", transactions[numTransactions].description);

    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random number of transactions
    int randNumTransactions = rand() % MAX_TRANSACTIONS + 1;

    // Loop through the desired number of transactions
    for (int i = 0; i < randNumTransactions; i++) {
        // Prompt the user for the transaction description
        printf("For what purpose dost thou spend thy coin, %s?\n", transactions[numTransactions].description);
        scanf("%s", transactions[numTransactions].description);

        // Prompt the user for the transaction amount
        printf("How much dost thou spend, %s?\n", transactions[numTransactions].description);
        scanf("%lf", &transactions[numTransactions].amount);

        // Get the current date and time
        time_t now = time(NULL);

        // Store the transaction date and time
        transactions[numTransactions].date = now;

        // Increment the number of transactions
        numTransactions++;
    }

    // Print the personal finance report
    printf("\nPersonal Finance Report for %s:\n", transactions[0].description);
    printf("=============================================================\n");
    printf("Transaction\tDate\tAmount\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%-20s", transactions[i].description);
        printf("%-20s", ctime(&transactions[i].date));
        printf("%-10.2f\n", transactions[i].amount);
    }

    return 0;
}