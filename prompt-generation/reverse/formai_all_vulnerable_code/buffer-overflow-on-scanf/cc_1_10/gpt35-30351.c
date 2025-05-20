//FormAI DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 25
#define MAX_PASSWORD_LENGTH 25
#define MAX_ACCOUNTS 10

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

void addAccount(Account accounts[], int* numAccounts) {
    if (*numAccounts >= MAX_ACCOUNTS) {
        printf("Sorry, you have reached the maximum number of accounts (%d).\n", MAX_ACCOUNTS);
        return;
    }
    printf("Enter a username:\n");
    scanf("%s", accounts[*numAccounts].username);
    printf("Enter a password:\n");
    scanf("%s", accounts[*numAccounts].password);
    (*numAccounts)++;
    printf("Account created.\n");
}

void displayAccounts(Account accounts[], int numAccounts) {
    if (numAccounts == 0) {
        printf("No accounts found.\n");
        return;
    }
    printf("Accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Username: %s, Password: %s\n", accounts[i].username, accounts[i].password);
    }
}

void deleteAccount(Account accounts[], int* numAccounts, char* username) {
    int index = -1;
    for (int i = 0; i < *numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    for (int i = index; i < *numAccounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    (*numAccounts)--;
    printf("Account deleted.\n");
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    printf("Welcome to the password manager!\n");
    while (1) {
        printf("Enter a command (add, display, delete, exit):\n");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            addAccount(accounts, &numAccounts);
        } else if (strcmp(command, "display") == 0) {
            displayAccounts(accounts, numAccounts);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter the username of the account to delete:\n");
            char username[MAX_USERNAME_LENGTH];
            scanf("%s", username);
            deleteAccount(accounts, &numAccounts, username);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}