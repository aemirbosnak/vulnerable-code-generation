//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int balance;
    int transactions[MAX_TRANSACTIONS];
    int num_transactions;
} Account;

void print_account(Account* account) {
    printf("Name: %s\n", account->name);
    printf("Balance: %d\n", account->balance);
    printf("Transactions: ");
    for (int i = 0; i < account->num_transactions; i++) {
        printf("%d ", account->transactions[i]);
    }
    printf("\n");
}

int main() {
    Account accounts[5];
    int num_accounts = 0;

    while (num_accounts < 5) {
        printf("Enter account name: ");
        scanf("%s", accounts[num_accounts].name);
        printf("Enter balance: ");
        scanf("%d", &accounts[num_accounts].balance);
        accounts[num_accounts].num_transactions = 0;
        num_accounts++;
    }

    while (1) {
        printf("Enter transaction type (1 for deposit, 2 for withdrawal, 3 for print): ");
        int transaction_type;
        scanf("%d", &transaction_type);

        if (transaction_type == 1) {
            printf("Enter account number: ");
            int account_number;
            scanf("%d", &account_number);
            printf("Enter amount: ");
            int amount;
            scanf("%d", &amount);
            accounts[account_number].balance += amount;
            accounts[account_number].transactions[accounts[account_number].num_transactions] = amount;
            accounts[account_number].num_transactions++;
        } else if (transaction_type == 2) {
            printf("Enter account number: ");
            int account_number;
            scanf("%d", &account_number);
            printf("Enter amount: ");
            int amount;
            scanf("%d", &amount);
            accounts[account_number].balance -= amount;
            accounts[account_number].transactions[accounts[account_number].num_transactions] = -amount;
            accounts[account_number].num_transactions++;
        } else if (transaction_type == 3) {
            printf("Enter account number: ");
            int account_number;
            scanf("%d", &account_number);
            print_account(&accounts[account_number]);
        } else {
            break;
        }
    }

    return 0;
}