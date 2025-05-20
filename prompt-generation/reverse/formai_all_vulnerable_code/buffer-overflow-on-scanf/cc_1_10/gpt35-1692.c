//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 5 // Maximum number of accounts
#define MAX_PASSWORD_LENGTH 50 // Maximum length of passwords

// Represents an account with a username and password
typedef struct account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} account_t;

// Global variables
account_t accounts[MAX_ACCOUNTS]; // Array of accounts
int num_accounts = 0; // Number of accounts currently in use

// Function to add a new account
void add_account() {
    // Check if maximum number of accounts has been reached
    if (num_accounts == MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    // Get username and password from user
    printf("Enter a username: ");
    scanf("%s", accounts[num_accounts].username);
    printf("Enter a password: ");
    scanf("%s", accounts[num_accounts].password);

    // Increment number of accounts
    num_accounts++;

    printf("Account created successfully.\n");
}

// Function to login to an existing account
int login() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Get username and password from user
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if username and password match an existing account
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0) {
            printf("Login successful.\n");
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

// Function to generate a random password
void generate_password() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    char password[MAX_PASSWORD_LENGTH];

    // Seed random number generator with current time
    srand(time(NULL));

    // Generate a random password
    for (int i = 0; i < MAX_PASSWORD_LENGTH - 1; i++) {
        password[i] = alphabet[rand() % strlen(alphabet)];
    }
    password[MAX_PASSWORD_LENGTH - 1] = '\0';

    printf("Your new password is: %s\n", password);
}

// Main function
int main() {
    int choice;

    // Menu loop
    while (1) {
        // Display menu
        printf("\n");
        printf("1. Add a new account\n");
        printf("2. Login to an existing account\n");
        printf("3. Generate a random password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform selected action
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                if (login()) {
                    printf("Welcome, %s!\n", accounts[num_accounts - 1].username);
                }
                break;
            case 3:
                generate_password();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}