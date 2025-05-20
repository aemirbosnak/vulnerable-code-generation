//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define struct for bank account
typedef struct bankAccount {
    int accountNumber;
    char name[50];
    float balance;
} BankAccount;

// Function to display account details
void displayAccountDetails(BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder Name: %s\n", account.name);
    printf("Account Balance: %.2f\n\n", account.balance);
}

// Function to deposit money in account
void depositMoney(BankAccount *account, float amount) {
    account->balance += amount;
    printf("Deposit successful! New balance: %.2f\n\n", account->balance);
}

// Function to withdraw money from account
void withdrawMoney(BankAccount *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: %.2f\n\n", account->balance);
    } else {
        printf("Insufficient balance for withdrawal.\n\n");
    }
}

// Main function
int main() {
    int numAccounts = 0;
    printf("Enter number of bank accounts: ");
    scanf("%d", &numAccounts);

    BankAccount accounts[numAccounts];

    // Input account details
    for (int i = 0; i < numAccounts; i++) {
        printf("\nAccount %d:\n", i+1);
        printf("Enter account number: ");
        scanf("%d", &accounts[i].accountNumber);
        printf("Enter account holder name: ");
        scanf("%s", accounts[i].name);
        printf("Enter account balance: ");
        scanf("%f", &accounts[i].balance);
    }

    // Display account details
    printf("\nAll Accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("--- Account %d ---\n", i+1);
        displayAccountDetails(accounts[i]);
    }

    // Deposit money into account
    int accountNum;
    float amount;
    printf("Enter account number for deposit: ");
    scanf("%d", &accountNum);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            depositMoney(&accounts[i], amount);
        }
    }

    // Withdraw money from account
    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNum);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            withdrawMoney(&accounts[i], amount);
        }
    }

    return 0;
}