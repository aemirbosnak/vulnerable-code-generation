//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

void create_account(Account accounts[], int size);
void deposit(Account accounts[], int size);
void withdraw(Account accounts[], int size);
void check_balance(Account accounts[], int size);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int size = 0;

    while(size < MAX_ACCOUNTS) {
        printf("Enter account number: ");
        scanf("%d", &accounts[size].account_number);
        printf("Enter name: ");
        scanf("%s", accounts[size].name);
        accounts[size].balance = 0.0;
        size++;
    }

    int choice;
    while(1) {
        printf("\nBanking System Menu\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account(accounts, size);
                break;
            case 2:
                deposit(accounts, size);
                break;
            case 3:
                withdraw(accounts, size);
                break;
            case 4:
                check_balance(accounts, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void create_account(Account accounts[], int size) {
    printf("Enter account number: ");
    scanf("%d", &accounts[size].account_number);
    printf("Enter name: ");
    scanf("%s", accounts[size].name);
    accounts[size].balance = 0.0;
    size++;
}

void deposit(Account accounts[], int size) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for(int i=0; i<size; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &accounts[i].balance);
            printf("Deposit successful!\n");
            break;
        }
    }
}

void withdraw(Account accounts[], int size) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for(int i=0; i<size; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &accounts[i].balance);
            printf("Withdrawal successful!\n");
            break;
        }
    }
}

void check_balance(Account accounts[], int size) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    for(int i=0; i<size; i++) {
        if(accounts[i].account_number == account_number) {
            printf("Current balance: $%.2f\n", accounts[i].balance);
            break;
        }
    }
}