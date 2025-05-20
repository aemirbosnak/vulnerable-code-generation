//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME 50
#define MAX_AMOUNT 1000000

typedef struct {
    char name[MAX_NAME];
    int account_number;
    double balance;
} Account;

int account_count = 0;
Account accounts[MAX_ACCOUNTS];

void create_account(char* name) {
    strcpy(accounts[account_count].name, name);
    accounts[account_count].account_number = ++account_count;
    accounts[account_count].balance = 0.0;
    printf("Account created for %s with account number %d\n", name, accounts[account_count].account_number);
}

void deposit(int account_number, double amount) {
    int i;
    for(i=0; i<account_count; i++) {
        if(accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            printf("Deposit of %.2f made to account %d\n", amount, accounts[i].account_number);
            return;
        }
    }
    printf("Account not found\n");
}

void withdraw(int account_number, double amount) {
    int i;
    for(i=0; i<account_count; i++) {
        if(accounts[i].account_number == account_number) {
            if(accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal of %.2f made from account %d\n", amount, accounts[i].account_number);
                return;
            }
            else {
                printf("Insufficient balance\n");
            }
        }
    }
    printf("Account not found\n");
}

void check_balance(int account_number) {
    int i;
    for(i=0; i<account_count; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Balance in account %d is %.2f\n", accounts[i].account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account not found\n");
}

int main() {
    int choice;
    char name[MAX_NAME];
    while(1) {
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                create_account(name);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &choice);
                printf("Enter amount: ");
                scanf("%lf", &choice);
                deposit(choice, choice);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &choice);
                printf("Enter amount: ");
                scanf("%lf", &choice);
                withdraw(choice, choice);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &choice);
                check_balance(choice);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}