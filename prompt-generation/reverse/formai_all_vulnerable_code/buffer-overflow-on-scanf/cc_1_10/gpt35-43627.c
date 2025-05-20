//FormAI DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNTS 10

struct Account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    while (1) {
        int option;
        printf("\n1. Add account\n2. View accounts\n3. Quit\n");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (numAccounts == MAX_ACCOUNTS) {
                    printf("Cannot add any more accounts!\n");
                    break;
                }

                struct Account newAccount;

                printf("Enter username: ");
                scanf("%s", newAccount.username);

                printf("Enter password: ");
                scanf("%s", newAccount.password);

                accounts[numAccounts] = newAccount;
                numAccounts++;

                printf("Account added successfully!\n");

                break;
            }

            case 2: {
                for (int i = 0; i < numAccounts; i++) {
                    printf("Username: %s\nPassword: %s\n", accounts[i].username, accounts[i].password);
                }

                break;
            }

            case 3: {
                printf("Exiting...\n");

                return 0;
            }

            default: {
                printf("Invalid option!\n");

                break;
            }
        }
    }
}