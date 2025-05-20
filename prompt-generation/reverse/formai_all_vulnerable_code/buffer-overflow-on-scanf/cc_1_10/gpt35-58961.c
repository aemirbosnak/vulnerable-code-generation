//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
/*
Password Management Program

This program stores and retrieves passwords for different accounts.
The user can add, remove, update, and view accounts and their passwords.

Author: Your Name
Date: Today's Date
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_CHARS 20

int num_accounts = 0; // number of accounts currently stored

// structure for account information
struct Account {
    char name[MAX_CHARS]; // name of account
    char password[MAX_CHARS]; // password for account
};

// array of accounts
struct Account accounts[MAX_ACCOUNTS];

// function to print menu options
void print_menu() {
    printf("\n");
    printf("1. Add Account\n");
    printf("2. Remove Account\n");
    printf("3. Update Account Password\n");
    printf("4. View Accounts\n");
    printf("5. Exit Program\n");
    printf("\nEnter option number: ");
}

// function to add a new account
void add_account() {
    struct Account new_account;
    printf("Enter account name: ");
    scanf("%s", new_account.name);
    printf("Enter account password: ");
    scanf("%s", new_account.password);
    accounts[num_accounts] = new_account;
    num_accounts++;
}

// function to remove an existing account
void remove_account() {
    char name[MAX_CHARS];
    int i, j;
    printf("Enter account name to remove: ");
    scanf("%s", name);
    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) { // if name matches
            for (j = i; j < num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1]; // shift remaining accounts down
            }
            num_accounts--;
            printf("Account removed.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

// function to update an existing account's password
void update_account() {
    char name[MAX_CHARS], password[MAX_CHARS];
    int i;
    printf("Enter account name to update: ");
    scanf("%s", name);
    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) { // if name matches
            printf("Enter new password: ");
            scanf("%s", password);
            strcpy(accounts[i].password, password);
            printf("Password updated.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

// function to view all stored accounts and their passwords
void view_accounts() {
    int i;
    printf("\nAccounts:\n");
    for (i = 0; i < num_accounts; i++) {
        printf("%s\t%s\n", accounts[i].name, accounts[i].password);
    }
}

// main function
int main() {
    int option;
    while (1) { // loop until user chooses to exit
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_account();
                break;
            case 2:
                remove_account();
                break;
            case 3:
                update_account();
                break;
            case 4:
                view_accounts();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}