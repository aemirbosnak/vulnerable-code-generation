//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char owner[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = numAccounts + 1; // Starting account number from 1
    printf("Enter owner's name: ");
    scanf("%s", newAccount.owner);
    newAccount.balance = 0;
    accounts[numAccounts++] = newAccount;
    
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber <= 0 || accNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    accounts[accNumber - 1].balance += amount;
    printf("Amount deposited successfully! New balance: %.2f\n", accounts[accNumber - 1].balance);
}

void withdrawMoney() {
    int accNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber <= 0 || accNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > accounts[accNumber - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }
    
    accounts[accNumber - 1].balance -= amount;
    printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[accNumber - 1].balance);
}

void viewAccountDetails() {
    int accNumber;
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber <= 0 || accNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }
    
    Account acc = accounts[accNumber - 1];
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Owner: %s\n", acc.owner);
    printf("Balance: %.2f\n", acc.balance);
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                viewAccountDetails();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}