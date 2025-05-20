//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    newAccount.balance = 0.0;  // initialize balance to zero

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void viewAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number to view details: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float depositAmount;
    printf("Enter account number to deposit: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter deposit amount: ");
            scanf("%f", &depositAmount);
            accounts[i].balance += depositAmount;
            printf("Deposit successful! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float withdrawAmount;
    printf("Enter account number to withdraw: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &withdrawAmount);
            if (withdrawAmount > accounts[i].balance) {
                printf("Insufficient funds.\n");
            } else {
                accounts[i].balance -= withdrawAmount;
                printf("Withdrawal successful! New Balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayMenu() {
    printf("\n=== Banking System ===\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("======================\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccountDetails();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}