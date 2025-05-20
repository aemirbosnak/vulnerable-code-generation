//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LEN 100

typedef struct {
    char account_name[MAX_LEN];
    char password[MAX_LEN];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function to load accounts from file
void load_accounts() {
    FILE *file = fopen("passwords.txt", "r");
    if (file) {
        while (fscanf(file, "%s %s", accounts[account_count].account_name, accounts[account_count].password) == 2) {
            account_count++;
        }
        fclose(file);
    }
}

// Function to save accounts to file
void save_accounts() {
    FILE *file = fopen("passwords.txt", "w");
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s %s\n", accounts[i].account_name, accounts[i].password);
    }
    fclose(file);
}

// Function to add a new account
void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Reached maximum account limit!\n");
        return;
    }

    printf("Enter account name: ");
    scanf("%s", accounts[account_count].account_name);
    printf("Enter password: ");
    scanf("%s", accounts[account_count].password);

    account_count++;
    save_accounts();
    printf("Account added successfully.\n");
}

// Function to display all accounts
void display_accounts() {
    printf("\nStored Accounts and Passwords:\n");
    for (int i = 0; i < account_count; i++) {
        printf("%d. %s - %s\n", i + 1, accounts[i].account_name, accounts[i].password);
    }
}

// Function to delete an account
void delete_account() {
    display_accounts();
    int index;
    printf("Enter the account number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > account_count) {
        printf("Invalid account number!\n");
        return;
    }

    // Shift accounts down
    for (int i = index - 1; i < account_count - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    account_count--;

    save_accounts();
    printf("Account deleted successfully.\n");
}

// Main menu
void main_menu() {
    int choice;
    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting Password Manager...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Entry point of program
int main() {
    load_accounts();
    main_menu();
    return 0;
}