//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    printf("Enter Account Holder's Name: ");
    scanf(" %[^\n]%*c", accounts[accountCount].name);
    printf("Enter Account Number: ");
    scanf(" %[^\n]%*c", accounts[accountCount].accountNumber);
    
    accounts[accountCount].balance = 0.0;
    accountCount++;
    printf("Account created successfully!\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter Account Number: ");
    scanf(" %[^\n]%*c", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            float amount;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited $%.2f to account %s\n", amount, accounts[i].accountNumber);
            } else {
                printf("Invalid deposit amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter Account Number: ");
    scanf(" %[^\n]%*c", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            float amount;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrew $%.2f from account %s\n", amount, accounts[i].accountNumber);
            } else {
                printf("Invalid withdrawal amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void checkBalance() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter Account Number: ");
    scanf(" %[^\n]%*c", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Balance for account %s: $%.2f\n", accounts[i].accountNumber, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void listAccounts() {
    printf("\nList of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Name: %s, Account Number: %s, Balance: $%.2f\n",
               accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
}

int main() {
    int choice;
    
    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Add Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. List Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}