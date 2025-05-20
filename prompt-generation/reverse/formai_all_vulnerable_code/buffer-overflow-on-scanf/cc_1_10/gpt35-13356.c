//FormAI DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNumber;
    char accountType[10];
    char accountHolder[50];
    float balance;
};

typedef struct Account Account;

int countAccounts = 0;
Account accounts[100];

void createAccount() {
    Account account;
    printf("\nEnter account number:\n");
    scanf("%d", &account.accountNumber);
    printf("Enter account type:\n");
    scanf("%s", account.accountType);
    printf("Enter account holder name:\n");
    scanf("%s", account.accountHolder);
    printf("Enter opening balance:\n");
    scanf("%f", &account.balance);
    accounts[countAccounts++] = account;
    printf("\nAccount created successfully!\n");
}

void displayAccounts() {
    printf("\nAccount Number\tAccount Type\tAccount Holder\tBalance\n");
    for(int i=0; i<countAccounts; i++) {
        printf("%d\t\t%s\t\t%s\t\t%.2f\n", accounts[i].accountNumber, accounts[i].accountType, accounts[i].accountHolder, accounts[i].balance);
    }
}

void deposit() {
    int accountNumber;
    printf("\nEnter account number:\n");
    scanf("%d", &accountNumber);
    for(int i=0; i<countAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            float amount;
            printf("Enter amount to deposit:\n");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("\nDeposited %.2f successfully in account number %d\n", amount, accountNumber);
            return;
        }
    }
    printf("\nAccount number not found\n");
}

void withdraw() {
    int accountNumber;
    printf("\nEnter account number:\n");
    scanf("%d", &accountNumber);
    for(int i=0; i<countAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            float amount;
            printf("Enter amount to withdraw:\n");
            scanf("%f", &amount);
            if(accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("\nWithdrawn %.2f successfully from account number %d\n", amount, accountNumber);
                return;
            } else {
                printf("\nInsufficient balance\n");
                return;
            }
        }
    }
    printf("\nAccount number not found\n");
}

int main() {
    int choice;
    do {
        printf("\n======Banking Record System======\n");
        printf("\nPlease select an option:\n1. Create account\n2. Display accounts\n3. Deposit\n4. Withdraw\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: printf("\nExiting program...\n"); exit(0);
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}