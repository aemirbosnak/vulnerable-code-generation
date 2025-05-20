//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account list is full!\n");
        return;
    }
    Account new_account;
    printf("Enter username: ");
    scanf("%s", new_account.username);
    
    printf("Enter password: ");
    scanf("%s", new_account.password);
    
    // Simple password strength check
    int length = strlen(new_account.password);
    if(length < 8 || !strpbrk(new_account.password, "0123456789") || 
       !strpbrk(new_account.password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") || 
       !strpbrk(new_account.password, "!@#$%^&*()")) {
        printf("Password must be at least 8 characters long and include:\n");
        printf(" - At least one number\n");
        printf(" - At least one uppercase letter\n");
        printf(" - At least one special character\n");
        return;
    }
    
    accounts[account_count++] = new_account;
    printf("Account added successfully.\n");
}

void display_accounts() {
    if (account_count == 0) {
        printf("No accounts to display.\n");
        return;
    }
    printf("Saved Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Username: %s, Password: %s\n", accounts[i].username, accounts[i].password);
    }
}

void delete_account() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username to delete: ");
    scanf("%s", username);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            for (int j = i; j < account_count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            account_count--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
    printf("Username not found.\n");
}

void save_accounts_to_file() {
    FILE *file = fopen("accounts.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s %s\n", accounts[i].username, accounts[i].password);
    }
    fclose(file);
    printf("Accounts saved to accounts.txt\n");
}

void load_accounts_from_file() {
    FILE *file = fopen("accounts.txt", "r");
    if (!file) {
        printf("No saved accounts found.\n");
        return;
    }
    Account temp;
    while(fscanf(file, "%s %s", temp.username, temp.password) == 2) {
        accounts[account_count++] = temp;
    }
    fclose(file);
    printf("Accounts loaded successfully.\n");
}

void menu() {
    while (1) {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Save Accounts\n");
        printf("5. Load Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                add_account(); 
                break;
            case 2: 
                display_accounts(); 
                break;
            case 3: 
                delete_account(); 
                break;
            case 4: 
                save_accounts_to_file(); 
                break;
            case 5: 
                load_accounts_from_file(); 
                break;
            case 6: 
                printf("Exiting...\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Password Manager!\n");
    menu();
    return 0;
}