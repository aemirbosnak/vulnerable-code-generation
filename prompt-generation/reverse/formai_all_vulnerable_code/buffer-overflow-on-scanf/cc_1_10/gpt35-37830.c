//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char account_name[50];
    char password[MAX_PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account() {
    if (num_accounts == MAX_ACCOUNTS) {
        printf("ERROR: the password manager is full!\n");
        return;
    }

    Account new_account;

    printf("Enter the account name: ");
    scanf("%s", new_account.account_name);

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the account password: ");
    scanf("%s", password);

    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("ERROR: password is too long!\n");
        return;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (!isdigit(password[i]) && !isalpha(password[i])) {
            printf("ERROR: password contains invalid characters!\n");
            return;
        }
    }

    strcpy(new_account.password, password);

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("Account added successfully!\n");
}

void view_accounts() {
    if (num_accounts == 0) {
        printf("There are no accounts to display.\n");
        return;
    }

    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %s\n", accounts[i].account_name, accounts[i].password);
    }
}

void delete_account() {
    if (num_accounts == 0) {
        printf("There are no accounts to delete.\n");
        return;
    }

    char account_name[50];
    printf("Enter the account name to delete: ");
    scanf("%s", account_name);

    int index_to_delete = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_name, account_name) == 0) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        printf("ERROR: account not found!\n");
        return;
    }

    for (int i = index_to_delete; i < num_accounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }

    num_accounts--;

    printf("Account deleted successfully!\n");
}

int main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1: Add an account\n");
        printf("2: View all accounts\n");
        printf("3: Delete an account\n");
        printf("4: Quit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_account();
        } else if (choice == 2) {
            view_accounts();
        } else if (choice == 3) {
            delete_account();
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}