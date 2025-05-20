//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    
    printf("Enter account holder's name: ");
    scanf(" %[^\n]%*c", newAccount.name);  // Read string with spaces
    newAccount.balance = 0.0;
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void viewAccountDetails(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void deposit(int accountNumber, float amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Successfully deposited $%.2f to account #%d.\n", amount, accountNumber);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(int accountNumber, float amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > accounts[i].balance) {
                printf("Insufficient funds to withdraw $%.2f from account #%d.\n", amount, accountNumber);
            } else {
                accounts[i].balance -= amount;
                printf("Successfully withdrew $%.2f from account #%d.\n", amount, accountNumber);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void listAllAccounts() {
    printf("Listing all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", 
                accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;
    int accountNumber;
    float amount;

    while (1) {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. View Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                viewAccountDetails(accountNumber);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            case 5:
                listAllAccounts();
                break;
            case 6:
                printf("Thank you for using our banking system! Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}