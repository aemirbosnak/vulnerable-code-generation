//FormAI DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for password and username
#define MAX_LENGTH 20

// Struct that represents an individual account
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

// Function to check if a password is strong enough
int is_strong_password(char *password) {
    int length = strlen(password);
    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_symbol = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= 'a' && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= '0' && c <= '9') {
            has_number = 1;
        } else {
            has_symbol = 1;
        }
    }

    return length >= 8 && has_uppercase && has_lowercase && has_number && has_symbol;
}

// Main function
int main() {
    // Initialize variables for number of accounts and choice
    int num_accounts = 0;
    int choice;

    // Array to store all the accounts
    Account accounts[MAX_LENGTH];

    // Loop for menu
    while (1) {
        printf("\nPassword Manager\n");
        printf("-----------------------------\n");
        printf("1. Add Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Account
                printf("\nAdd Account\n");
                printf("-----------------------------\n");

                // Prompt for username and password
                printf("Enter username: ");
                scanf("%s", accounts[num_accounts].username);

                printf("Enter password: ");
                scanf("%s", accounts[num_accounts].password);

                // Check if password is strong enough
                if (!is_strong_password(accounts[num_accounts].password)) {
                    printf("Password is not strong enough!\n");
                    break;
                }

                // Increment number of accounts
                num_accounts++;

                printf("Account added successfully.\n");
                break;
            case 2:
                // Display all accounts
                printf("\nDisplay All Accounts\n");
                printf("-----------------------------\n");

                // Loop through all accounts and display username and password
                for (int i = 0; i < num_accounts; i++) {
                    printf("Username: %s\n", accounts[i].username);
                    printf("Password: %s\n", accounts[i].password);
                }

                // Check if there are any accounts
                if (num_accounts == 0) {
                    printf("No accounts found.\n");
                }

                break;
            case 3:
                // Exit
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}