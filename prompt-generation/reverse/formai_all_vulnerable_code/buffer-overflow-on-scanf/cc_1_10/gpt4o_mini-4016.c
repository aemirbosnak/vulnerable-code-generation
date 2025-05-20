//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

typedef struct {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void encrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] + 3; // Simple Caesar cipher
    }
}

void decrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] - 3; // Reverse of the Caesar cipher
    }
}

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }
    
    char account_name[MAX_LENGTH];
    char password[MAX_LENGTH];
    
    printf("Enter account name: ");
    scanf("%s", account_name);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    encrypt(password);
    
    strcpy(accounts[account_count].account, account_name);
    strcpy(accounts[account_count].password, password);
    account_count++;
    
    printf("Account added successfully!\n");
}

void retrieve_account() {
    char account_name[MAX_LENGTH];
    
    printf("Enter account name to retrieve: ");
    scanf("%s", account_name);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account, account_name) == 0) {
            char decrypted_password[MAX_LENGTH];
            strcpy(decrypted_password, accounts[i].password);
            decrypt(decrypted_password);
            printf("Password for %s: %s\n", account_name, decrypted_password);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void delete_account() {
    char account_name[MAX_LENGTH];
    
    printf("Enter account name to delete: ");
    scanf("%s", account_name);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account, account_name) == 0) {
            for (int j = i; j < account_count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            account_count--;
            printf("Account deleted successfully!\n");
            return;
        }
    }
    
    printf("Account not found!\n");
}

void display_accounts() {
    printf("Stored Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account: %s\n", accounts[i].account);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add Account\n");
        printf("2. Retrieve Account\n");
        printf("3. Delete Account\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                retrieve_account();
                break;
            case 3:
                delete_account();
                break;
            case 4:
                display_accounts();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}