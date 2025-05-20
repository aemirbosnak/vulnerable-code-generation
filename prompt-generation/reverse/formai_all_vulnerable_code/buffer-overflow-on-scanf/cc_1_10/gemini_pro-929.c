//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LEN 20
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int balance;
    int num_transactions;
    struct {
        int amount;
        char description[50];
    } transactions[MAX_TRANSACTIONS];
} account_t;

account_t accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account(char *name, int balance) {
    if (num_accounts == MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = balance;
    accounts[num_accounts].num_transactions = 0;

    num_accounts++;
}

void deposit(char *name, int amount) {
    int i;

    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            accounts[i].balance += amount;
            accounts[i].transactions[accounts[i].num_transactions].amount = amount;
            strcpy(accounts[i].transactions[accounts[i].num_transactions].description, "Deposit");
            accounts[i].num_transactions++;
            return;
        }
    }

    printf("Error: Account not found.\n");
}

void withdraw(char *name, int amount) {
    int i;

    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            if (accounts[i].balance < amount) {
                printf("Error: Insufficient funds.\n");
                return;
            }

            accounts[i].balance -= amount;
            accounts[i].transactions[accounts[i].num_transactions].amount = amount;
            strcpy(accounts[i].transactions[accounts[i].num_transactions].description, "Withdrawal");
            accounts[i].num_transactions++;
            return;
        }
    }

    printf("Error: Account not found.\n");
}

void print_statement(char *name) {
    int i;

    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Account Statement for %s\n", accounts[i].name);
            printf("Balance: %d\n", accounts[i].balance);
            printf("Transactions:\n");

            for (int j = 0; j < accounts[i].num_transactions; j++) {
                printf("  %d %s\n", accounts[i].transactions[j].amount, accounts[i].transactions[j].description);
            }

            return;
        }
    }

    printf("Error: Account not found.\n");
}

int main() {
    char command[50];
    char name[MAX_NAME_LEN];
    int amount;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            scanf("%s %d", name, &amount);
            create_account(name, amount);
        } else if (strcmp(command, "deposit") == 0) {
            scanf("%s %d", name, &amount);
            deposit(name, amount);
        } else if (strcmp(command, "withdraw") == 0) {
            scanf("%s %d", name, &amount);
            withdraw(name, amount);
        } else if (strcmp(command, "statement") == 0) {
            scanf("%s", name);
            print_statement(name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}