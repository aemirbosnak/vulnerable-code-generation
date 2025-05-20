//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_ACCOUNTS 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

int numAccounts = 0;
Account accounts[MAX_ACCOUNTS];

void addAccount() {
    if (numAccounts == MAX_ACCOUNTS) {
        printf("Max number of accounts reached.\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", accounts[numAccounts].username);
    
    printf("Enter password: ");
    scanf("%s", accounts[numAccounts].password);
    
    numAccounts++;
    printf("Account created successfully.\n");
}

void viewAccounts() {
    if (numAccounts == 0) {
        printf("No accounts found.\n");
        return;
    }
    
    printf("%-20s | %-20s\n", "Username", "Password");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < numAccounts; i++) {
        printf("%-20s | %-20s\n", accounts[i].username, accounts[i].password);
    }
}

void saveAccounts() {
    FILE *file = fopen("accounts.txt", "w");
    
    if (numAccounts == 0) {
        fprintf(file, "No accounts found.");
    } else {
        fprintf(file, "%-20s | %-20s\n", "Username", "Password");
        fprintf(file, "----------------------------------------\n");
        
        for (int i = 0; i < numAccounts; i++) {
            fprintf(file, "%-20s | %-20s\n", accounts[i].username, accounts[i].password);
        }
    }
    
    fclose(file);
    printf("Accounts saved to file successfully.\n");
}

void loadAccounts() {
    FILE *file = fopen("accounts.txt", "r");
    
    if (file == NULL) {
        printf("No previous accounts found.\n");
        return;
    }
    
    // Clear any existing accounts
    numAccounts = 0;
    
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 4];
    fgets(line, sizeof(line), file); // Skip header
    fgets(line, sizeof(line), file);
    
    while (!feof(file)) {
        char *username = strtok(line, " |");
        char *password = strtok(NULL, " |");
        
        // Remove any trailing whitespace
        username[strcspn(username, "\n")] = 0;
        password[strcspn(password, "\n")] = 0;
        
        // Add account to array
        strcpy(accounts[numAccounts].username, username);
        strcpy(accounts[numAccounts].password, password);
        numAccounts++;
        
        fgets(line, sizeof(line), file);
    }
    
    fclose(file);
    printf("Accounts loaded from file successfully.\n");
}

int main() {
    int choice;
    
    loadAccounts();
    
    do {
        printf("\nPassword Management Menu\n");
        printf("------------------------\n");
        printf("1. Add Account\n");
        printf("2. View All Accounts\n");
        printf("3. Save Accounts to File\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                saveAccounts();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}