//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int accountNum;
    float balance;
} Account;

void addAccount(Account **accounts, int *numAccounts) {
    *numAccounts += 1;
    *accounts = realloc(*accounts, *numAccounts * sizeof(Account));
    printf("Enter account holder name: ");
    scanf("%s", (*accounts)[*numAccounts - 1].name);
    printf("Enter account number: ");
    scanf("%d", &(*accounts)[*numAccounts - 1].accountNum);
    printf("Enter account balance: ");
    scanf("%f", &(*accounts)[*numAccounts - 1].balance);
    printf("Account added successfully!\n");
}

void displayAccounts(Account *accounts, int numAccounts) {
    printf("Name\tAccount Number\tBalance\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%s\t%d\t\t%.2f\n", accounts[i].name, accounts[i].accountNum, accounts[i].balance);
    }
}

void deposit(Account *accounts, int numAccounts, int accountNum, float amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNum == accountNum) {
            accounts[i].balance += amount;
            printf("%.2f deposited successfully into account %d!\n", amount, accountNum);
            return;
        }
    }
    printf("Account %d not found!\n", accountNum);
}

void withdraw(Account *accounts, int numAccounts, int accountNum, float amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNum == accountNum) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("%.2f withdrawn successfully from account %d!\n", amount, accountNum);
                return;
            }
            else {
                printf("Insufficient balance in account %d!\n", accountNum);
                return;
            }
        }
    }
    printf("Account %d not found!\n", accountNum);
}

int main() {
    Account *accounts = NULL;
    int numAccounts = 0;
    int choice;
    do {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1. Add account\n");
        printf("2. Display accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAccount(&accounts, &numAccounts);
                break;
            case 2:
                displayAccounts(accounts, numAccounts);
                break;
            case 3:
                {
                    int accountNum;
                    float amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNum);
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount);
                    deposit(accounts, numAccounts, accountNum, amount);
                    break;
                }
            case 4:
                {
                    int accountNum;
                    float amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNum);
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount);
                    withdraw(accounts, numAccounts, accountNum, amount);
                    break;
                }
            case 5:
                printf("Thank you for using the Banking Record System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    free(accounts);
    return 0;
}