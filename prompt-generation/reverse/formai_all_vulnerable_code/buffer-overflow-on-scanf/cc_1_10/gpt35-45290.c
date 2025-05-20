//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNTS 10

// Struct to hold account information
typedef struct {
    char account_name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

// Global variables
Account accounts[MAX_ACCOUNTS];
int num_accounts;

// Function to add an account
void add_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Error: Cannot add any more accounts.\n");
        return;
    }

    printf("Enter account name: ");
    scanf("%s", accounts[num_accounts].account_name);

    printf("Enter password: ");
    scanf("%s", accounts[num_accounts].password);

    num_accounts++;
}

// Function to delete an account
void delete_account(char *account_name) {
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_name, account_name) == 0) {
            int j;
            // "Delete" account by shifting all accounts to the left
            for (j = i; j < num_accounts-1; j++) {
                strcpy(accounts[j].account_name, accounts[j+1].account_name);
                strcpy(accounts[j].password, accounts[j+1].password);
            }
            num_accounts--;
            printf("Account deleted.\n");
            return;
        }
    }
    // Account not found
    printf("Error: Account not found.\n");
}

// Function to display all accounts
void display_accounts() {
    int i;
    printf("Accounts:\n");
    for (i = 0; i < num_accounts; i++) {
        printf("%s\n", accounts[i].account_name);
    }
}

// Main function
int main() {
    int choice;
    char account_name[MAX_PASSWORD_LENGTH];

    num_accounts = 0;

    // Display menu and handle user input
    do {
        printf("1. Add account\n");
        printf("2. Delete account\n");
        printf("3. Display accounts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                printf("Enter account name to delete: ");
                scanf("%s", account_name);
                delete_account(account_name);
                break;
            case 3:
                display_accounts();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}