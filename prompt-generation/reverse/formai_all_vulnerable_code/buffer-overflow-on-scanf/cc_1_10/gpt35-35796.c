//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define the structure for Bank Account Records */
struct bankRecord {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

/* Function to create a new Bank Account */
struct bankRecord createNewAccount() {
    struct bankRecord newAccount; /* Create a new empty bank record */
    printf("\nEnter Account Number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter Account Holder Name: ");
    scanf("%s", newAccount.accountHolder);
    printf("Enter Account Balance: ");
    scanf("%f", &newAccount.balance);
    return newAccount;
}

/* Function to print the Bank Account Details */
void printAccountDetails(struct bankRecord account) {
    printf("\nAccount Number: %d", account.accountNumber);
    printf("\nAccount Holder: %s", account.accountHolder);
    printf("\nAccount Balance: $%0.2f", account.balance);
}

/* Main Function */
int main() {
    int choice, numAccounts = 0;
    struct bankRecord accounts[50]; /* Initialise an array of Bank Account records */

    do
    {
        printf("\n===Banking Record System Menu===\n");
        printf("1) Create New Account\n");
        printf("2) Display All Accounts\n");
        printf("3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: /* Create new Account */
            accounts[numAccounts] = createNewAccount();
            numAccounts++;
            break;

        case 2: /* Display all Accounts */
            printf("\n---Bank Account Details---\n");
            for (int i = 0; i < numAccounts; i++) {
                printAccountDetails(accounts[i]);
                printf("\n-------------------------\n");
            }
            break;

        case 3: /* Exit */
            printf("\nGoodbye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid Choice!\n");
            break;
        }
    } while (choice != 3);

    return 0;
}