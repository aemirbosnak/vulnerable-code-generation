//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    // Declare variables
    int num_accounts = 0;
    double total_balance = 0.0;
    char account_type[MAX];

    // Create an array of accounts
    struct account
    {
        char name[MAX];
        double balance;
        char type[MAX];
    } accounts[MAX];

    // Get the number of accounts from the user
    printf("How many accounts do you have? ");
    scanf("%d", &num_accounts);

    // Create the accounts
    for (int i = 0; i < num_accounts; i++)
    {
        accounts[i].name[0] = '\0';
        accounts[i].balance = 0.0;
        accounts[i].type[0] = '\0';
    }

    // Get the account information from the user
    for (int i = 0; i < num_accounts; i++)
    {
        printf("Enter the name of account %d: ", i + 1);
        scanf("%s", accounts[i].name);

        printf("Enter the balance of account %d: ", i + 1);
        scanf("%lf", &accounts[i].balance);

        printf("Enter the type of account %d: ", i + 1);
        scanf("%s", accounts[i].type);
    }

    // Calculate the total balance
    for (int i = 0; i < num_accounts; i++)
    {
        total_balance += accounts[i].balance;
    }

    // Print the total balance
    printf("Total balance: $%.2lf", total_balance);

    return 0;
}