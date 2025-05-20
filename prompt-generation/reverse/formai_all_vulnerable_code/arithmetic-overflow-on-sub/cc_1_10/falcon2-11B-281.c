//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT 5
#define MAX_NAME_LEN 20
#define MAX_BALANCE 10000

typedef struct {
    char name[MAX_NAME_LEN];
    int account_num;
    int balance;
} Account;

Account accounts[MAX_ACCOUNT];
int num_accounts = 0;

void create_account() {
    char name[MAX_NAME_LEN];
    int account_num;
    int balance;

    printf("Enter account name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    account_num = num_accounts++;
    balance = 0;

    accounts[account_num] = (Account) {.name = name,.account_num = account_num,.balance = balance };
}

void deposit(int account_num) {
    int amount;

    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    accounts[account_num].balance += amount;
}

void withdraw(int account_num) {
    int amount;

    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (accounts[account_num].balance < amount) {
        printf("Insufficient funds\n");
    } else {
        accounts[account_num].balance -= amount;
    }
}

int check_balance(int account_num) {
    return accounts[account_num].balance;
}

void print_account(int account_num) {
    printf("%s, account %d has $%d balance\n", accounts[account_num].name, accounts[account_num].account_num, accounts[account_num].balance);
}

int main() {
    int choice, account_num, amount;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Print account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit(num_accounts - 1); break;
            case 3: withdraw(num_accounts - 1); break;
            case 4: printf("%d\n", check_balance(num_accounts - 1)); break;
            case 5: print_account(num_accounts - 1); break;
            case 6: exit(0);
        }
    }
}