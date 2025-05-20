//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DEPOSIT 99999999
#define MAX_WITHDRAW 99999999

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int account_number;
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void deposit(int account_number, float amount) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    Account new_account = {""};
    strcpy(new_account.name, "");
    new_account.account_number = account_number;
    new_account.balance += amount;

    accounts[account_count++] = new_account;
    printf("Account created successfully. New account number: %d. New balance: %.2f\n", account_number, new_account.balance);
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }

    printf("Account not found.\n");
}

void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("%d. %s - %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    char command[5];
    int account_number;
    float amount;

    while (1) {
        printf("> ");
        scanf("%s%s", command, &command[5]);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "deposit") == 0) {
            scanf("%d%f", &account_number, &amount);
            deposit(account_number, amount);
        } else if (strcmp(command, "withdraw") == 0) {
            scanf("%d%f", &account_number, &amount);
            withdraw(account_number, amount);
        } else if (strcmp(command, "print") == 0) {
            print_accounts();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}