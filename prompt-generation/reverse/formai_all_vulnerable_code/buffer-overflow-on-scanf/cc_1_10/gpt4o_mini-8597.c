//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char ownerName[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function declarations
void createAccount();
void deposit();
void withdraw();
void displayAccount();
void showAllAccounts();
int findAccount(int accountNumber);

int main() {
    int choice;

    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Show All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
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
                displayAccount();
                break;
            case 5:
                showAllAccounts();
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account numbering
    printf("Enter owner name: ");
    scanf("%s", newAccount.ownerName);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    
    accounts[index].balance += amount;
    printf("Successfully deposited %.2f to account number %d. New balance: %.2f\n", amount, accountNumber, accounts[index].balance);
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[index].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }
    
    accounts[index].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d. New balance: %.2f\n", amount, accountNumber, accounts[index].balance);
}

void displayAccount() {
    int accountNumber;
    printf("Enter account number to display: ");
    scanf("%d", &accountNumber);
    
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("\n=== Account Details ===\n");
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Owner Name: %s\n", accounts[index].ownerName);
    printf("Balance: %.2f\n", accounts[index].balance);
}

void showAllAccounts() {
    printf("\n=== All Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Owner Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].ownerName, accounts[i].balance);
    }
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}