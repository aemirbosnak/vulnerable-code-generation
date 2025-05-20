//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char holderName[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached!\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple incrementing account number
    printf("Enter account holder name: ");
    scanf("%s", newAccount.holderName);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void viewAccountDetails(int accountNumber) {
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }
    Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\nHolder Name: %s\nBalance: %.2f\n",
           account.accountNumber, account.holderName, account.balance);
}

void deposit(int accountNumber, float amount) {
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n", amount, accounts[accountNumber - 1].balance);
}

void withdraw(int accountNumber, float amount) {
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }
    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
        return;
    }
    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds for withdrawal!\n");
        return;
    }
    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, accounts[accountNumber - 1].balance);
}

void menu() {
    int choice;
    do {
        printf("\n*** Banking Record System ***\n");
        printf("1. Create Account\n2. View Account Details\n3. Deposit\n4. Withdraw\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2: {
                int accountNumber;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                viewAccountDetails(accountNumber);
                break;
            }
            case 3: {
                int accountNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            }
            case 5:
                printf("Exiting the Banking Record System. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}