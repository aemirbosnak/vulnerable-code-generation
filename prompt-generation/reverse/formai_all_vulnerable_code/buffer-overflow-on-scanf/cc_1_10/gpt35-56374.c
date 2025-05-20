//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LENGTH 20

// Structure to hold account information
struct account {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Global array to hold all the accounts
struct account accounts[MAX_ACCOUNTS];

// Function to save the account information to a file
void saveAccounts() {
    FILE* file = fopen("accounts.dat", "w");
    if (file) {
        fwrite(accounts, sizeof(accounts), 1, file);
        fclose(file);
    }
}

// Function to load the accounts from the file
void loadAccounts() {
    FILE* file = fopen("accounts.dat", "r");
    if (file) {
        fread(accounts, sizeof(accounts), 1, file);
        fclose(file);
    }
}

// Function to add a new account
void addAccount() {
    // Prompt the user for the account name and password
    printf("Enter the account name: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", name);
    
    printf("Enter the password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);
    
    // Create a new account object and add it to the array
    struct account newAccount = {0};
    strncpy(newAccount.name, name, MAX_PASSWORD_LENGTH);
    strncpy(newAccount.password, password, MAX_PASSWORD_LENGTH);
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (strlen(accounts[i].name) == 0) {
            accounts[i] = newAccount;
            break;
        }
    }
    
    // Save the accounts to file
    saveAccounts();
}

// Function to remove an existing account
void removeAccount() {
    // Prompt the user for the account name to remove
    printf("Enter the account name to remove: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", name);
    
    // Search for the account and remove it if found
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            accounts[i] = (struct account){0};
            break;
        }
    }
    
    // Save the accounts to file
    saveAccounts();
}

// Function to list all existing accounts
void listAccounts() {
    printf("Accounts:\n");
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (strlen(accounts[i].name) > 0) {
            printf("- %s\n", accounts[i].name);
        }
    }
}

// Function to run the password manager program
void runPasswordManager() {
    // Load the accounts from file
    loadAccounts();
    
    // Main loop to prompt the user for options
    int running = 1;
    while (running) {
        printf("\nSelect an option:\n");
        printf("1. Add account\n");
        printf("2. Remove account\n");
        printf("3. List accounts\n");
        printf("4. Quit\n");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addAccount();
                break;
            case 2:
                removeAccount();
                break;
            case 3:
                listAccounts();
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

// Main function to start the program
int main() {
    printf("Password Manager\n");
    runPasswordManager();
    return 0;
}