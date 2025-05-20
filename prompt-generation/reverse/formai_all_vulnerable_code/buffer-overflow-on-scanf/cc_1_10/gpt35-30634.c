//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Struct to store login credentials
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

// Function declarations
void displayMenu();
void addAccount(Account accounts[], int *numAccounts);
void viewAccount(Account accounts[], int numAccounts);
void changePassword(Account accounts[], int numAccounts);

int main() {
    Account accounts[MAX_LENGTH];
    int numAccounts = 0;
    char option;

    do {
        displayMenu();
        scanf(" %c", &option);

        switch(option) {
            case '1': addAccount(accounts, &numAccounts);
                      break;
            case '2': viewAccount(accounts, numAccounts);
                      break;
            case '3': changePassword(accounts, numAccounts);
                      break;
            case '4': break;
            default: printf("Invalid option, please choose again.\n");
        }
    } while(option != '4');

    printf("Exiting program...\n");

    return 0;
}

// Display the menu of options 
void displayMenu() {
    printf("\n--- Password Management ---\n");
    printf("1. Add an account\n");
    printf("2. View accounts\n");
    printf("3. Change password\n");
    printf("4. Exit\n");
    printf("Enter option: ");
}

// Add a new account to the array of accounts
void addAccount(Account accounts[], int *numAccounts) {
    Account newAccount;

    printf("\nEnter username: ");
    scanf(" %[^\n]", newAccount.username);
    printf("Enter password: ");
    scanf(" %[^\n]", newAccount.password);

    accounts[*numAccounts] = newAccount;

    printf("Account added successfully.\n");

    *numAccounts += 1;
}

// View all accounts stored in the array
void viewAccount(Account accounts[], int numAccounts) {
    if(numAccounts == 0) {
        printf("\nNo accounts found. Please add an account.\n");
        return;
    }

    printf("\n--- Accounts ---\n");

    for(int i = 0; i < numAccounts; i++) {
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n\n", accounts[i].password);
    }
}

// Change password for a specific account
void changePassword(Account accounts[], int numAccounts) {
    char username[MAX_LENGTH], oldPassword[MAX_LENGTH], newPassword[MAX_LENGTH];
    int accountFound = 0;

    printf("\nEnter username: ");
    scanf(" %[^\n]", username);
    printf("Enter old password: ");
    scanf(" %[^\n]", oldPassword);
    printf("Enter new password: ");
    scanf(" %[^\n]", newPassword);

    // Loop through accounts to find the correct one
    for(int i = 0; i < numAccounts; i++) {
        if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, oldPassword) == 0) {
            strcpy(accounts[i].password, newPassword);
            printf("\nPassword successfully changed for account %s.\n", username);
            accountFound = 1;
            break;
        }
    }

    if(!accountFound) {
        printf("\nAccount not found or password incorrect.\n");
    }
}