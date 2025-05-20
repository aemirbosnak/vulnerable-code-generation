//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int account_number;
    double balance;
} account;

int main() {
    account accounts[100];
    int num_accounts = 0;

    while (1) {
        printf("Command (n/d/w/b/q): ");
        char command;
        scanf(" %c", &command);

        if (command == 'n') {
            printf("Name: ");
            char name[100];
            scanf(" %s", name);

            printf("Account number: ");
            int account_number;
            scanf(" %d", &account_number);

            printf("Balance: ");
            double balance;
            scanf(" %lf", &balance);

            account new_account = {strdup(name), account_number, balance};
            accounts[num_accounts++] = new_account;
        } else if (command == 'd') {
            printf("Account number: ");
            int account_number;
            scanf(" %d", &account_number);

            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    free(accounts[i].name);
                    for (int j = i + 1; j < num_accounts; j++) {
                        accounts[j - 1] = accounts[j];
                    }
                    num_accounts--;
                    break;
                }
            }
        } else if (command == 'w') {
            printf("Account number: ");
            int account_number;
            scanf(" %d", &account_number);

            printf("Amount: ");
            double amount;
            scanf(" %lf", &amount);

            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    accounts[i].balance -= amount;
                    break;
                }
            }
        } else if (command == 'b') {
            printf("Account number: ");
            int account_number;
            scanf(" %d", &account_number);

            printf("Amount: ");
            double amount;
            scanf(" %lf", &amount);

            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    accounts[i].balance += amount;
                    break;
                }
            }
        } else if (command == 'q') {
            break;
        }
    }

    for (int i = 0; i < num_accounts; i++) {
        printf("%s %d %.2lf\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
        free(accounts[i].name);
    }

    return 0;
}