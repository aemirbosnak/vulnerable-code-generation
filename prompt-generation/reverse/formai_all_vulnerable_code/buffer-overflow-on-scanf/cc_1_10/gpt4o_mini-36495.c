//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 10
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_HISTORY 10

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[MAX_NAME_LENGTH];
    float balance;
    char transactionHistory[MAX_TRANSACTION_HISTORY][100];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit();
void withdraw();
void viewAccountDetails();
void displayMenu();
void handleOption(int choice);
void displayTransactionHistory(Account *acc);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleOption(choice);
    }

    return 0;
}

void displayMenu() {
    printf("\n---- Banking Record System ----\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
}

void handleOption(int choice) {
    switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            viewAccountDetails();
            break;
        case 5:
            printf("Exiting the system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts limit reached!\n");
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number: ");
    scanf("%s", accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            snprintf(accounts[i].transactionHistory[accounts[i].transactionCount++], 100, "Deposited: %.2f", amount);
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number: ");
    scanf("%s", accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                snprintf(accounts[i].transactionHistory[accounts[i].transactionCount++], 100, "Withdrew: %.2f", amount);
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
                return;
            } else {
                printf("Insufficient balance!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void viewAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];

    printf("Enter account number: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder's Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            displayTransactionHistory(&accounts[i]);
            return;
        }
    }
    printf("Account not found!\n");
}

void displayTransactionHistory(Account *acc) {
    printf("Transaction History:\n");
    for (int i = 0; i < acc->transactionCount; i++) {
        printf("%s\n", acc->transactionHistory[i]);
    }
}