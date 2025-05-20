//FormAI DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_PASSWORD_LENGTH 25
#define MAX_ACCOUNTS 10

// Define struct for storing account information
struct account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Function prototypes
int menu();
void login(struct account accounts[], int numAccounts);
void addAccount(struct account accounts[], int *numAccounts);
void deleteAccount(struct account accounts[], int *numAccounts);

int main() {
    // Initialize variables
    struct account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    // Display welcome message
    printf("Welcome to Password Manager!\n\n");

    do {
        // Display main menu and get user choice
        choice = menu();

        // Perform action based on user choice
        switch (choice) {
            case 1:
                login(accounts, numAccounts);
                break;
            case 2:
                addAccount(accounts, &numAccounts);
                break;
            case 3:
                deleteAccount(accounts, &numAccounts);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to display the main menu and get user choice
int menu() {
    int choice;

    printf("Main Menu:\n");
    printf("1. Login\n");
    printf("2. Add Account\n");
    printf("3. Delete Account\n");
    printf("4. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

// Function to handle the login functionality
void login(struct account accounts[], int numAccounts) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int i;

    // Get username and password from user
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Search for matching account in accounts array
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0 &&
                strcmp(accounts[i].password, password) == 0) {
            printf("\nLogin successful!\n\n");
            return;
        }
    }

    printf("\nInvalid username or password. Please try again.\n\n");
}

// Function to handle the add account functionality
void addAccount(struct account accounts[], int *numAccounts) {
    // Check if accounts array is already full
    if (*numAccounts == MAX_ACCOUNTS) {
        printf("\nCannot add account. Maximum number of accounts reached.\n\n");
        return;
    }

    // Get account information from user
    printf("Enter new username: ");
    scanf("%s", accounts[*numAccounts].username);
    printf("Enter new password: ");
    scanf("%s", accounts[*numAccounts].password);

    // Increment number of accounts
    (*numAccounts)++;

    printf("\nAccount added successfully!\n\n");
}

// Function to handle the delete account functionality
void deleteAccount(struct account accounts[], int *numAccounts) {
    char username[MAX_PASSWORD_LENGTH];
    int i, j;

    // Get username of account to delete from user
    printf("Enter username of account to delete: ");
    scanf("%s", username);

    // Search for matching account in accounts array
    for (i = 0; i < *numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            // Move all accounts after deleted account back by one index
            for (j = i + 1; j < *numAccounts; j++) {
                strcpy(accounts[j - 1].username, accounts[j].username);
                strcpy(accounts[j - 1].password, accounts[j].password);
            }

            // Decrement number of accounts
            (*numAccounts)--;

            printf("\nAccount deleted successfully!\n\n");
            return;
        }
    }

    printf("\nAccount not found. Please try again.\n\n");
}