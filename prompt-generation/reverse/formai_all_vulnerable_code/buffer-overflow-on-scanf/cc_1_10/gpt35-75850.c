//FormAI DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bankAccount {
    char name[50];
    int accountNum;
    int balance;
};

int numAccounts = 0; // Global variable to keep track of number of accounts
struct bankAccount accounts[10]; // Global array to store 10 bank accounts

void addAccount() {
    if(numAccounts >= 10) { // Check if maximum number of accounts have been added
        printf("Sorry, maximum number of accounts reached.\n");
        return;
    }
    struct bankAccount newAccount;
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNum);
    printf("Enter balance: ");
    scanf("%d", &newAccount.balance);
    accounts[numAccounts] = newAccount;
    numAccounts++;
    printf("New account added successfully.\n");
}

void showAccount(int accountIndex) {
    printf("Name: %s\n", accounts[accountIndex].name);
    printf("Account Number: %d\n", accounts[accountIndex].accountNum);
    printf("Balance: %d\n", accounts[accountIndex].balance);
}

void searchAccount() {
    int accountNum;
    printf("Enter account number to search: ");
    scanf("%d", &accountNum);
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNum == accountNum) {
            showAccount(i);
            return;
        }
    }
    printf("Account number not found.\n");
}

void deposit() {
    int accountNum, amount;
    printf("Enter account number: ");
    scanf("%d", &accountNum);
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNum == accountNum) {
            printf("Enter amount to deposit: ");
            scanf("%d", &amount);
            accounts[i].balance += amount;
            printf("$%d deposited successfully to account number %d.\n", amount, accountNum);
            showAccount(i);
            return;
        }
    }
    printf("Account number not found.\n");
}

void withdraw() {
    int accountNum, amount;
    printf("Enter account number: ");
    scanf("%d", &accountNum);
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNum == accountNum) {
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if(accounts[i].balance < amount) {
                printf("Insufficient balance.\n");
                showAccount(i);
                return;
            }
            accounts[i].balance -= amount;
            printf("$%d withdrawn successfully from account number %d.\n", amount, accountNum);
            showAccount(i);
            return;
        }
    }
    printf("Account number not found.\n");
}

int main() {
    int option;
    while(1) {
        printf("\n----------------- BANKING RECORD SYSTEM -----------------\n");
        printf("1. Add account\n");
        printf("2. Search account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addAccount();
                break;
            case 2:
                searchAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}