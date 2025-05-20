//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void addUserAccount();
void deleteUserAccount();
void displayUserAccounts();
int getAccountIndex(char* username);
bool isValidUsername(char* username);

// Define constants
#define MAX_USERS 100
#define USERNAME_LENGTH 20

// Struct to represent a user account
typedef struct {
    char username[USERNAME_LENGTH];
    int id;
} UserAccount;

// Global variables
UserAccount userAccounts[MAX_USERS];
int numAccounts = 0;

int main() {
    int choice = 0;

    // Main loop
    while (true) {
        printf("\nSystem Administration Tool\n");
        printf("===========================\n");
        printf("1. Add user account\n");
        printf("2. Delete user account\n");
        printf("3. Display user accounts\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUserAccount();
                break;
            case 2:
                deleteUserAccount();
                break;
            case 3:
                displayUserAccounts();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to add a new user account
void addUserAccount() {
    if (numAccounts >= MAX_USERS) {
        printf("Maximum number of accounts reached. Cannot add new account.\n");
        return;
    }

    char username[USERNAME_LENGTH];

    // Prompt user for username
    while (true) {
        printf("Enter new username (up to %d characters): ", USERNAME_LENGTH-1);
        scanf("%s", username);

        if (!isValidUsername(username)) {
            printf("Invalid username. Username can only contain alphanumeric characters and underscores.\n");
        } else {
            break;
        }
    }

    // Create new account
    UserAccount newAccount;
    strcpy(newAccount.username, username);
    newAccount.id = numAccounts + 1;

    // Add to account list
    userAccounts[numAccounts] = newAccount;
    numAccounts++;

    printf("User account added successfully. ID: %d, Username: %s\n", newAccount.id, newAccount.username);
}

// Function to delete an existing user account
void deleteUserAccount() {
    char username[USERNAME_LENGTH];

    // Prompt user for username
    printf("Enter username to delete: ");
    scanf("%s", username);

    // Get account index
    int accountIndex = getAccountIndex(username);

    if (accountIndex == -1) {
        printf("User account '%s' not found.\n", username);
    } else {
        // Remove account from list
        for (int i = accountIndex; i < numAccounts-1; i++) {
            userAccounts[i] = userAccounts[i+1];
        }
        numAccounts--;

        printf("User account '%s' deleted successfully.\n", username);
    }
}

// Function to display all user accounts
void displayUserAccounts() {
    printf("User Accounts\n");
    printf("-------------\n");

    if (numAccounts == 0) {
        printf("No user accounts found.\n");
    } else {
        for (int i = 0; i < numAccounts; i++) {
            printf("ID: %d, Username: %s\n", userAccounts[i].id, userAccounts[i].username);
        }
    }
}

// Function to get index of an account given a username
int getAccountIndex(char* username) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(userAccounts[i].username, username) == 0) {
            return i;
        }
    }
    return -1; // account not found
}

// Function to check if a username is valid
bool isValidUsername(char* username) {
    for (int i = 0; i < strlen(username); i++) {
        if (!(isalnum(username[i]) || username[i] == '_')) {
            return false;
        }
    }
    return true;
}