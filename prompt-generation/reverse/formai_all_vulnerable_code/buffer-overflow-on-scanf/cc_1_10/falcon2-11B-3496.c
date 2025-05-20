//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int id;
    char name[100];
    double balance;
}Account;

int main()
{
    // Create an array of accounts
    Account accounts[100];
    int numAccounts = 100;

    // Initialize an account
    Account acc;
    acc.id = 0;
    strcpy(acc.name, "John Doe");
    acc.balance = 0.0;
    accounts[0] = acc;

    // Create a transaction record
    char transType[100];
    double transAmount;
    char transDesc[100];

    // Perform transactions
    printf("Enter transaction type (D for deposit, W for withdraw): ");
    scanf("%s", transType);
    if (strcmp(transType, "D") == 0) {
        printf("Enter deposit amount: ");
        scanf("%lf", &transAmount);
        printf("Enter transaction description: ");
        scanf("%s", transDesc);
    }
    else if (strcmp(transType, "W") == 0) {
        printf("Enter withdrawal amount: ");
        scanf("%lf", &transAmount);
        printf("Enter transaction description: ");
        scanf("%s", transDesc);
    }

    // Update account balance
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(transType, "D") == 0) {
            accounts[i].balance += transAmount;
        }
        else if (strcmp(transType, "W") == 0) {
            accounts[i].balance -= transAmount;
        }
    }

    // Display account information
    printf("Account ID: %d\n", accounts[0].id);
    printf("Account Name: %s\n", accounts[0].name);
    printf("Balance: %.2lf\n", accounts[0].balance);

    // Display transaction record
    printf("Transaction Type: %s\n", transType);
    printf("Transaction Amount: %.2lf\n", transAmount);
    printf("Transaction Description: %s\n", transDesc);

    // Output formatted time
    time_t rawtime;
    struct tm *timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("Time: %s\n", asctime(timeinfo));

    // Free allocated memory
    for (int i = 0; i < numAccounts; i++) {
        free(accounts[i].name);
    }
    free(accounts);

    return 0;
}