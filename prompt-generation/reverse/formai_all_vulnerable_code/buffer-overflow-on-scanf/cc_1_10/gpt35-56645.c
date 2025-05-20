//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20
#define MAX_NUM_ACCOUNTS 100

// Define the account structure
typedef struct account {
    char username[50];
    char password[PASSWORD_LENGTH];
} Account;

// Declare the array of accounts
Account accounts[MAX_NUM_ACCOUNTS];

// Declare the number of accounts currently in the system
int numAccounts = 0;

// Declare the function prototypes
void addAccount();
void removeAccount();
void changePassword();
void displayAccounts();

// Define the main function
int main() {
    int choice;

    printf("Welcome to the Password Management Program!\n");

    // Start the main loop of the program
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add account\n");
        printf("2. Remove account\n");
        printf("3. Change password\n");
        printf("4. Display accounts\n");
        printf("5. Exit\n");

        // Get the user's choice
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add account
                addAccount();
                break;

            case 2: // Remove account
                removeAccount();
                break;

            case 3: // Change password
                changePassword();
                break;

            case 4: // Display accounts
                displayAccounts();
                break;

            case 5: // Exit
                printf("Goodbye!\n");
                exit(0);

            default: // Invalid choice
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a new account to the system
void addAccount() {
    // Only allow adding a new account if there is room in the array
    if (numAccounts >= MAX_NUM_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    // Get the new username and password from the user
    char newUsername[50];
    char newPassword[PASSWORD_LENGTH];
    printf("Enter the new username: ");
    scanf("%s", newUsername);
    printf("Enter the new password (max %d characters): ", PASSWORD_LENGTH - 1);
    scanf("%s", newPassword);

    // Create a new account and add it to the array
    Account newAccount;
    strcpy(newAccount.username, newUsername);
    strcpy(newAccount.password, newPassword);
    accounts[numAccounts] = newAccount;
    numAccounts++;

    printf("Account created successfully.\n");
}

// Function to remove an account from the system
void removeAccount() {
    // Get the username of the account to remove from the user
    char username[50];
    printf("Enter the username of the account to remove: ");
    scanf("%s", username);

    // Search for the account in the array
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            // Account found - shift all the accounts after it back in the array
            int j;
            for (j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            printf("Account removed successfully.\n");
            return;
        }
    }

    // Account not found
    printf("Account not found.\n");
}

// Function to change the password of an account
void changePassword() {
    // Get the username of the account to change the password for from the user
    char username[50];
    printf("Enter the username to change the password for: ");
    scanf("%s", username);

    // Search for the account in the array
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            // Account found - get the new password from the user
            char newPassword[PASSWORD_LENGTH];
            printf("Enter the new password (max %d characters): ", PASSWORD_LENGTH - 1);
            scanf("%s", newPassword);

            // Update the password for the account
            strcpy(accounts[i].password, newPassword);

            printf("Password changed successfully.\n");
            return;
        }
    }

    // Account not found
    printf("Account not found.\n");
}

// Function to display all accounts in the system
void displayAccounts() {
    printf("\nUsername\tPassword\n");
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("%s\t\t%s\n", accounts[i].username, accounts[i].password);
    }
}