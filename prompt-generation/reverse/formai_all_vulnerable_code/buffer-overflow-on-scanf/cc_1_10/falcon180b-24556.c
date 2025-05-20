//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int accountNumber;
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    printf("Enter your name: ");
    scanf("%s", accounts[numAccounts].name);
    printf("Enter your account number: ");
    scanf("%d", &accounts[numAccounts].accountNumber);
    printf("Enter your initial balance: ");
    scanf("%lf", &accounts[numAccounts].balance);
    numAccounts++;
}

void deposit() {
    int accountNumber;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Enter the amount you want to deposit: ");
            scanf("%lf", &accounts[i].balance);
            break;
        }
    }
}

void withdraw() {
    int accountNumber;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Enter the amount you want to withdraw: ");
            scanf("%lf", &accounts[i].balance);
            if(accounts[i].balance >= 0) {
                break;
            } else {
                printf("Insufficient funds.\n");
            }
        }
    }
}

void checkBalance() {
    int accountNumber;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Your balance is: %.2lf\n", accounts[i].balance);
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("Welcome to the Banking Record System!\n");
        printf("Please choose an option:\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
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
                checkBalance();
                break;
            case 5:
                printf("Thank you for using the Banking Record System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);
    return 0;
}