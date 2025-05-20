//Falcon-180B DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} account;

void add_account(account *accounts, int num_accounts) {
    printf("Enter username: ");
    scanf("%s", accounts[num_accounts].username);

    printf("Enter password: ");
    scanf("%s", accounts[num_accounts].password);

    printf("Account added successfully!\n");
}

void login(account *accounts, int num_accounts) {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    int i = 0;
    while (i < num_accounts) {
        if (strcmp(username, accounts[i].username) == 0) {
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            if (strcmp(password, accounts[i].password) == 0) {
                printf("Login successful!\n");
            } else {
                printf("Incorrect password.\n");
            }

            break;
        }
        i++;
    }
}

int main() {
    account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;

    while (num_accounts < MAX_ACCOUNTS) {
        printf("1. Add account\n2. Login\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_account(accounts, num_accounts);
        } else if (choice == 2) {
            login(accounts, num_accounts);
        }
    }

    return 0;
}