//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 100
#define MAX_TRANSACTIONS 100

typedef struct {
    int transactionId;
    char type[10]; // "DEPOSIT" or "WITHDRAW"
    float amount;
} Transaction;

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    float balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function Prototypes
void createAccount();
void deposit();
void withdraw();
void viewAccount();
void viewAllAccounts();
void printTransactionHistory(const Account *account);

int main() {
    int choice;

    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: viewAccount(); break;
            case 5: viewAllAccounts(); break;
            case 6: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // simple account number generation
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;

    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);
    
    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Must be greater than zero.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    accounts[accountNumber - 1].transactions[accounts[accountNumber - 1].transactionCount++] = (Transaction) {accounts[accountNumber - 1].transactionCount + 1, "DEPOSIT", amount};
    printf("Deposited successfully! New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid amount. Must be greater than zero and less than the current balance.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    accounts[accountNumber - 1].transactions[accounts[accountNumber - 1].transactionCount++] = (Transaction) {accounts[accountNumber - 1].transactionCount + 1, "WITHDRAW", amount};
    printf("Withdrawn successfully! New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void viewAccount() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    Account *account = &accounts[accountNumber - 1];
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Current Balance: %.2f\n", account->balance);
    printTransactionHistory(account);
}

void viewAllAccounts() {
    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

void printTransactionHistory(const Account *account) {
    if (account->transactionCount == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("Transaction History:\n");
    for (int i = 0; i < account->transactionCount; i++) {
        printf("Transaction ID: %d, Type: %s, Amount: %.2f\n", account->transactions[i].transactionId, account->transactions[i].type, account->transactions[i].amount);
    }
}