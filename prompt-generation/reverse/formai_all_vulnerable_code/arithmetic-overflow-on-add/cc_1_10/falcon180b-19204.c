//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    int balance;
    int transactions[MAX_TRANSACTIONS];
    int num_transactions;
} account_t;

void init_accounts(account_t accounts[MAX_ACCOUNTS]) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i].balance = 0;
        accounts[i].num_transactions = 0;
    }
}

void add_transaction(account_t *account, char type[10], int amount) {
    if (account->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: account is full.\n");
        return;
    }
    strcpy(account->transactions[account->num_transactions], type);
    account->balance += amount;
    account->num_transactions++;
}

void print_transactions(account_t account) {
    printf("Transactions for %s:\n", account.name);
    for (int i = 0; i < account.num_transactions; i++) {
        printf("%s: $%d\n", account.transactions[i], account.transactions[i+1]);
    }
}

int main() {
    account_t accounts[MAX_ACCOUNTS];
    init_accounts(accounts);

    int choice;
    do {
        printf("Personal Finance Planner\n");
        printf("1. Add account\n");
        printf("2. Add transaction\n");
        printf("3. Print transactions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account name: ");
                scanf("%s", accounts[0].name);
                break;
            case 2:
                printf("Enter account name: ");
                scanf("%s", accounts[0].name);
                char type[10];
                int amount;
                printf("Enter transaction type (deposit/withdrawal): ");
                scanf("%s", type);
                printf("Enter amount: $");
                scanf("%d", &amount);
                add_transaction(&accounts[0], type, amount);
                break;
            case 3:
                printf("Enter account name: ");
                scanf("%s", accounts[0].name);
                print_transactions(accounts[0]);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}