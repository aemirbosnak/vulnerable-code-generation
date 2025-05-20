//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 10

struct Transaction
{
    char name[20];
    int amount;
    char type;
};

int main()
{
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;

    // Create a loop to get the user input
    while (1)
    {
        // Get the transaction name
        printf("Enter the transaction name: ");
        scanf("%s", transactions[numTransactions].name);

        // Get the transaction amount
        printf("Enter the transaction amount: ");
        scanf("%d", &transactions[numTransactions].amount);

        // Get the transaction type
        printf("Enter the transaction type (C/D): ");
        scanf(" %c", &transactions[numTransactions].type);

        // Increment the number of transactions
        numTransactions++;

        // Check if the user wants to continue
        printf("Do you want to continue? (Y/N): ");
        char continueInput;
        scanf(" %c", &continueInput);

        // If the user does not want to continue, break out of the loop
        if (continueInput == 'N')
        {
            break;
        }
    }

    // Print the transactions
    for (int i = 0; i < numTransactions; i++)
    {
        printf("%s: %d, %c\n", transactions[i].name, transactions[i].amount, transactions[i].type);
    }

    // Calculate the total amount of the transactions
    int totalAmount = 0;
    for (int i = 0; i < numTransactions; i++)
    {
        totalAmount += transactions[i].amount;
    }

    // Print the total amount of the transactions
    printf("Total amount: %d\n", totalAmount);

    return 0;
}