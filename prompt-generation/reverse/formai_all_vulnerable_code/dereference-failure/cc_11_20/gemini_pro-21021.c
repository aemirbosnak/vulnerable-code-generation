//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int amount;
} transaction_t;

typedef struct {
    char *name;
    int balance;
    transaction_t *transactions;
    int num_transactions;
} account_t;

int main() {
    account_t accounts[10];
    int num_accounts = 0;

    // Get user input
    while (1) {
        char line[1024];
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        // Parse the line
        char *command = strtok(line, " ");
        if (strcmp(command, "add") == 0) {
            // Add a new account
            char *name = strtok(NULL, " ");
            int amount = atoi(strtok(NULL, " "));
            accounts[num_accounts++] = (account_t) { .name = name, .balance = amount, .transactions = NULL, .num_transactions = 0 };
        } else if (strcmp(command, "deposit") == 0) {
            // Deposit money into an account
            char *name = strtok(NULL, " ");
            int amount = atoi(strtok(NULL, " "));
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].name, name) == 0) {
                    accounts[i].balance += amount;
                    break;
                }
            }
        } else if (strcmp(command, "withdraw") == 0) {
            // Withdraw money from an account
            char *name = strtok(NULL, " ");
            int amount = atoi(strtok(NULL, " "));
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].name, name) == 0) {
                    accounts[i].balance -= amount;
                    break;
                }
            }
        } else if (strcmp(command, "transfer") == 0) {
            // Transfer money between accounts
            char *from_name = strtok(NULL, " ");
            char *to_name = strtok(NULL, " ");
            int amount = atoi(strtok(NULL, " "));
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].name, from_name) == 0) {
                    accounts[i].balance -= amount;
                    break;
                }
            }
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].name, to_name) == 0) {
                    accounts[i].balance += amount;
                    break;
                }
            }
        } else if (strcmp(command, "print") == 0) {
            // Print the balances of all accounts
            for (int i = 0; i < num_accounts; i++) {
                printf("%s: %d\n", accounts[i].name, accounts[i].balance);
            }
        }
    }

    return 0;
}