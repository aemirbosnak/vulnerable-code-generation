//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100
#define MAX_BALANCE 10000

typedef struct {
    int account_number;
    int balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account(int account_number, int initial_balance) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].balance = initial_balance;

    printf("Account created with number %d and balance %d.\n", account_number, initial_balance);
    num_accounts++;
}

void deposit(int account_number, int amount) {
    int index = 0;
    for (; index < num_accounts; index++) {
        if (accounts[index].account_number == account_number) {
            break;
        }
    }

    if (index == num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposit of %d into account %d successful.\n", amount, account_number);
}

void withdraw(int account_number, int amount) {
    int index = 0;
    for (; index < num_accounts; index++) {
        if (accounts[index].account_number == account_number) {
            break;
        }
    }

    if (index == num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    if (accounts[index].balance < amount) {
        printf("Insufficient funds in account %d.\n", account_number);
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawal of %d from account %d successful.\n", amount, account_number);
}

int check_balance(int account_number) {
    int index = 0;
    for (; index < num_accounts; index++) {
        if (accounts[index].account_number == account_number) {
            break;
        }
    }

    if (index == num_accounts) {
        printf("Invalid account number.\n");
        return -1;
    }

    printf("Balance of account %d is %d.\n", account_number, accounts[index].balance);
    return accounts[index].balance;
}

int main() {
    int choice;
    int account_number, amount;
    int balance;

    do {
        printf("\n1. Create an account\n2. Deposit money\n3. Withdraw money\n4. Check balance\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter initial balance: ");
                scanf("%d", &balance);
                create_account(account_number, balance);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                balance = check_balance(account_number);
                if (balance!= -1) {
                    printf("Balance of account %d is %d.\n", account_number, balance);
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice!= 5);

    return 0;
}