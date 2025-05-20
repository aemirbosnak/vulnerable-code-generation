//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_ACCOUNTS 50

struct account {
    char username[25];
    char password[MAX_PASSWORD_LENGTH];
};

struct account accounts[MAX_NUM_ACCOUNTS];
int num_accounts = 0;

void add_account() {
    if (num_accounts == MAX_NUM_ACCOUNTS) {
        printf("Error: maximum number of accounts reached.\n");
        return;
    }

    struct account new_account;

    printf("Enter username for new account: ");
    scanf("%24s", new_account.username);

    printf("Enter password for new account (must be less than %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%19s", new_account.password);

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("Account added successfully.\n");
}

void list_accounts() {
    printf("Current Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %s\n", accounts[i].username, accounts[i].password);
    }
}

void login() {
    char username[25];
    char password[MAX_PASSWORD_LENGTH];

    printf("Username: ");
    scanf("%24s", username);

    printf("Password: ");
    scanf("%19s", password);

    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nPassword Management\n");
        printf("1. Add account\n");
        printf("2. List accounts\n");
        printf("3. Login\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_account(); break;
            case 2: list_accounts(); break;
            case 3: login(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}