//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_ACCOUNTS 10

// stores the password and username for an account
struct account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// stores all the accounts
struct account accounts[MAX_ACCOUNTS];

// tracks the number of accounts
int numAccounts = 0;

// adds an account to the list of accounts
void addAccount(char* username, char* password) {
    // check if we've reached the maximum number of accounts
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Sorry, you've reached the maximum number of accounts.\n");
        return;
    }
    
    // create an account struct and add it to the accounts array
    struct account newAccount;
    strcpy(newAccount.username, username);
    strcpy(newAccount.password, password);
    accounts[numAccounts++] = newAccount;
    
    printf("Account added successfully.\n");
}

// prints all the accounts
void printAccounts() {
    if (numAccounts == 0) {
        printf("No accounts found.\n");
        return;
    }
    
    printf("Accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%d. Username: %s, Password: %s\n", i+1, accounts[i].username, accounts[i].password);
    }
}

// searches for an account by username
int findAccount(char* username) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return i;
        }
    }
    
    return -1;
}

// changes the password for an account
void changePassword(char* username, char* oldPassword, char* newPassword) {
    // find the account
    int accountIndex = findAccount(username);
    if (accountIndex == -1) {
        printf("Account not found.\n");
        return;
    }
    
    // check if the old password is correct
    if (strcmp(accounts[accountIndex].password, oldPassword) != 0) {
        printf("Incorrect password.\n");
        return;
    }
    
    // change the password
    strcpy(accounts[accountIndex].password, newPassword);
    
    printf("Password changed successfully.\n");
}

int main() {
    // print the menu
    printf("Password Manager\n");
    printf("1. Add Account\n");
    printf("2. Print Accounts\n");
    printf("3. Change Password\n");
    printf("4. Exit\n");
    
    // loop until the user chooses to exit
    int choice = 0;
    while (choice != 4) {
        // get the user's choice
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            // add an account
            char username[MAX_USERNAME_LENGTH];
            char password[MAX_PASSWORD_LENGTH];
            
            printf("Enter username: ");
            scanf("%s", username);
            
            printf("Enter password: ");
            scanf("%s", password);
            
            addAccount(username, password);
        }
        else if (choice == 2) {
            // print all accounts
            printAccounts();
        }
        else if (choice == 3) {
            // change a password
            char username[MAX_USERNAME_LENGTH];
            char oldPassword[MAX_PASSWORD_LENGTH];
            char newPassword[MAX_PASSWORD_LENGTH];
            
            printf("Enter username: ");
            scanf("%s", username);
            
            printf("Enter old password: ");
            scanf("%s", oldPassword);
            
            printf("Enter new password: ");
            scanf("%s", newPassword);
            
            changePassword(username, oldPassword, newPassword);
        }
        else if (choice == 4) {
            // exit
            printf("Goodbye!\n");
        }
        else {
            // invalid choice
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}