//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LEN 24

typedef struct Account {
    char name[50];
    char username[24];
    char password[MAX_PASSWORD_LEN + 1];
} Account;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

void add_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account new_account;
    printf("Enter account name: ");
    fgets(new_account.name, sizeof(new_account.name), stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0;

    printf("Enter username: ");
    fgets(new_account.username, sizeof(new_account.username), stdin);
    new_account.username[strcspn(new_account.username, "\n")] = 0;

    printf("Enter password (maximum %d characters): ", MAX_PASSWORD_LEN);
    fgets(new_account.password, sizeof(new_account.password), stdin);
    new_account.password[strcspn(new_account.password, "\n")] = 0;

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("Account added successfully.\n");
}

void view_accounts() {
    if (num_accounts == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("%-30s%-24s\n", "Account Name", "Username");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-30s%-24s\n", accounts[i].name, accounts[i].username);
    }
}

void view_password() {
    if (num_accounts == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter account name: ");
    char account_name[50];
    fgets(account_name, sizeof(account_name), stdin);
    account_name[strcspn(account_name, "\n")] = 0;

    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(account_name, accounts[i].name) == 0) {
            printf("Password for %s is %s.\n", account_name, accounts[i].password);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    while (1) {
        printf("\nPassword Manager\n");
        printf("----------------\n");
        printf("1. Add account\n");
        printf("2. View accounts\n");
        printf("3. View password\n");
        printf("4. Exit\n");

        int option;
        printf("\nEnter option: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                add_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                view_password();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}