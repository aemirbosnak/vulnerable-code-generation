//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LEN];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if(accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached. Cannot create new account.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple sequential account number
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.accountHolder);
    newAccount.balance = 0.0;
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

void viewAccount(int accountNumber) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }
    Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.accountHolder);
    printf("Balance: $%.2f\n", acc.balance);
}

void deposit(int accountNumber, double amount) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }
    if(amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }
    accounts[accountNumber - 1].balance += amount;
    printf("Deposited $%.2f to Account Number %d. New Balance: $%.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw(int accountNumber, double amount) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }
    if(amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    if(amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds for withdrawal.\n");
        return;
    }
    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew $%.2f from Account Number %d. New Balance: $%.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void listAccounts() {
    if(accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    printf("Account List:\n");
    for(int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: $%.2f\n", 
                accounts[i].accountNumber, 
                accounts[i].accountHolder, 
                accounts[i].balance);
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            createAccount();
        } 
        else if(choice == 2) {
            int accNum;
            printf("Enter account number: ");
            scanf("%d", &accNum);
            viewAccount(accNum);
        } 
        else if(choice == 3) {
            int accNum;
            double amount;
            printf("Enter account number: ");
            scanf("%d", &accNum);
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            deposit(accNum, amount);
        } 
        else if(choice == 4) {
            int accNum;
            double amount;
            printf("Enter account number: ");
            scanf("%d", &accNum);
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            withdraw(accNum, amount);
        } 
        else if(choice == 5) {
            listAccounts();
        } 
        else if(choice == 6) {
            printf("Exiting the system. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}