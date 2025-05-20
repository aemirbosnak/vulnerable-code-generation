//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define TRANSACTION_HISTORY_LENGTH 100

typedef struct {
    double amount;
    char description[100];
} Transaction;

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    double balance;
    Transaction transactions[TRANSACTION_HISTORY_LENGTH];
    int transactionCount;
} BankAccount;

BankAccount* accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }

    BankAccount* newAccount = (BankAccount*)malloc(sizeof(BankAccount));
    printf("Enter account holder's name: ");
    getchar(); // to consume newline
    fgets(newAccount->accountHolder, NAME_LENGTH, stdin);
    newAccount->accountHolder[strcspn(newAccount->accountHolder, "\n")] = 0; // remove newline
    newAccount->accountNumber = accountCount + 1; // simple account number
    newAccount->balance = 0.0;
    newAccount->transactionCount = 0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount->accountNumber);
}

void depositFunds() {
    int accountNumber;
    double amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    BankAccount* account = accounts[accountNumber - 1];
    account->balance += amount;

    // record transaction
    Transaction newTransaction = {amount, "Deposit"};
    account->transactions[account->transactionCount] = newTransaction;
    account->transactionCount++;

    printf("Successfully deposited %.2f to account number %d. New balance is %.2f.\n", amount, accountNumber, account->balance);
}

void withdrawFunds() {
    int accountNumber;
    double amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    BankAccount* account = accounts[accountNumber - 1];
    if (amount > account->balance) {
        printf("Insufficient funds. Current balance is %.2f.\n", account->balance);
        return;
    }

    account->balance -= amount;

    // record transaction
    Transaction newTransaction = {amount, "Withdrawal"};
    account->transactions[account->transactionCount] = newTransaction;
    account->transactionCount++;

    printf("Successfully withdrew %.2f from account number %d. New balance is %.2f.\n", amount, accountNumber, account->balance);
}

void displayAccountDetails() {
    int accountNumber;
    printf("Enter account number to view details: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    BankAccount* account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Balance: %.2f\n", account->balance);
    printf("Transaction History:\n");
    for (int i = 0; i < account->transactionCount; i++) {
        printf(" %d: %s - %.2f\n", i + 1, account->transactions[i].description, account->transactions[i].amount);
    }
}

void listAccounts() {
    printf("Listing all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Account Holder: %s, Balance: %.2f\n", accounts[i]->accountNumber, accounts[i]->accountHolder, accounts[i]->balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. Display Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositFunds(); break;
            case 3: withdrawFunds(); break;
            case 4: displayAccountDetails(); break;
            case 5: listAccounts(); break;
            case 6: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}