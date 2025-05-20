//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>

// Define structure to hold bank account information
struct bankAccount {
    char name[50];
    int accountNumber;
    float balance;
};

int main() {
    // Define variables
    int numAccounts;
    float depositAmount, withdrawAmount;
    int accountNumToDeposit, accountNumToWithdraw;

    // Get number of bank accounts from user
    printf("Enter the number of bank accounts: ");
    scanf("%d", &numAccounts);

    // Create array of bankAccount structures
    struct bankAccount accounts[numAccounts];

    // Fill in account information for each bank account
    for (int i = 0; i < numAccounts; i++) {
        printf("\nEnter name for account %d: ", i+1);
        scanf("%s", accounts[i].name);
        printf("Enter account number for account %d: ", i+1);
        scanf("%d", &accounts[i].accountNumber);
        printf("Enter starting balance for account %d: ", i+1);
        scanf("%f", &accounts[i].balance);
    }

    // Deposit money into account
    printf("\n\nEnter account number to deposit into: ");
    scanf("%d", &accountNumToDeposit);
    printf("\nEnter amount to deposit: ");
    scanf("%f", &depositAmount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumToDeposit) {
            accounts[i].balance += depositAmount;
            printf("\nDeposit of $%.2f successful. New balance is $%.2f\n", depositAmount, accounts[i].balance);
            break;
        }
    }

    // Withdraw money from account
    printf("\n\nEnter account number to withdraw from: ");
    scanf("%d", &accountNumToWithdraw);
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &withdrawAmount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumToWithdraw) {
            if (accounts[i].balance >= withdrawAmount) {
                accounts[i].balance -= withdrawAmount;
                printf("\nWithdrawal of $%.2f successful. New balance is $%.2f\n", withdrawAmount, accounts[i].balance);
            } else {
                printf("\nInsufficient funds to withdraw $%.2f. Current balance is $%.2f\n", withdrawAmount, accounts[i].balance);
            }
            break;
        }
    }

    return 0;
}