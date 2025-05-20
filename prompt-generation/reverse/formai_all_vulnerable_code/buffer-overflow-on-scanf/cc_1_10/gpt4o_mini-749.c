//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int accNumber;
    char name[50];
    float balance;
} Account;

void createAccount(Account *accounts, int *count) {
    printf("Enter Account Number: ");
    scanf("%d", &accounts[*count].accNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]s", accounts[*count].name);
    accounts[*count].balance = 0.0;
    (*count)++;
}

void deposit(Account *accounts, int count) {
    int accNum;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    for(int i = 0; i < count; i++) {
        if(accounts[i].accNumber == accNum) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposited %.2f to Account Number %d\n", amount, accNum);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(Account *accounts, int count) {
    int accNum;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    for(int i = 0; i < count; i++) {
        if(accounts[i].accNumber == accNum) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if(amount > accounts[i].balance) {
                printf("Insufficient Balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawn %.2f from Account Number %d\n", amount, accNum);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccountDetails(Account *accounts, int count) {
    int accNum;
    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    for(int i = 0; i < count; i++) {
        if(accounts[i].accNumber == accNum) {
            printf("Account Number: %d\n", accounts[i].accNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAllAccounts(Account *accounts, int count) {
    printf("\nAll Accounts:\n");
    for(int i = 0; i < count; i++) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n", accounts[i].accNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    Account accounts[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                deposit(accounts, count);
                break;
            case 3:
                withdraw(accounts, count);
                break;
            case 4:
                displayAccountDetails(accounts, count);
                break;
            case 5:
                displayAllAccounts(accounts, count);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Option. Try Again.\n");
        }
    }

    return 0;
}