//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_OF_ACCOUNTS 10

// Account struct
typedef struct Account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

// Function to add account to password manager
void addAccount(Account* accounts, int* numOfAccounts) {
    if (*numOfAccounts >= MAX_NUM_OF_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    // Check if username already exists
    for (int i=0; i<*numOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    // Validate password
    if (strlen(password) >= MAX_PASSWORD_LENGTH) {
        printf("Password too long. Maximum length is %d characters.\n", MAX_PASSWORD_LENGTH);
        return;
    }

    Account newAccount;
    strcpy(newAccount.username, username);
    strcpy(newAccount.password, password);

    accounts[*numOfAccounts] = newAccount;
    (*numOfAccounts)++;
    printf("Account added successfully.\n");
}

// Function to remove account from password manager
void removeAccount(Account* accounts, int* numOfAccounts) {
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username to remove: ");
    scanf("%s", username);

    bool accountRemoved = false;

    // Find and remove account
    for (int i=0; i<*numOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            accountRemoved = true;
            for (int j=i; j<*numOfAccounts-1; j++) {
                accounts[j] = accounts[j+1];
            }
            (*numOfAccounts)--;
            printf("Account removed successfully.\n");
            break;
        }
    }

    // Print message if account not found
    if (!accountRemoved) {
        printf("Account not found.\n");
    }
}

// Function to display all accounts in password manager
void displayAccounts(Account* accounts, int numOfAccounts) {
    if (numOfAccounts == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("Accounts:\n");
    for (int i=0; i<numOfAccounts; i++) {
        printf("Username: %s, Password: %s\n", accounts[i].username, accounts[i].password);
    }
}

int main() {
    Account accounts[MAX_NUM_OF_ACCOUNTS];
    int numOfAccounts = 0;
    int choice;

    while (true) {
        // Display menu
        printf("\n1. Add Account\n");
        printf("2. Remove Account\n");
        printf("3. Display Accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accounts, &numOfAccounts);
                break;
            case 2:
                removeAccount(accounts, &numOfAccounts);
                break;
            case 3:
                displayAccounts(accounts, numOfAccounts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}