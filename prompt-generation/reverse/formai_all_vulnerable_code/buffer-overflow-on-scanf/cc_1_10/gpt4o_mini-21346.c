//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define PASSWORD_LENGTH 20
#define USERNAME_LENGTH 30

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void add_account();
void view_accounts(int index);
void delete_account();
void menu();
void confirm_delete(int index);

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot add more accounts.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", accounts[account_count].username);
    printf("Enter password: ");
    scanf("%s", accounts[account_count].password);
    account_count++;

    printf("Account added successfully!\n\n");
    menu();
}

void view_accounts(int index) {
    if (index >= account_count) {
        printf("No more accounts to display.\n\n");
        menu();
        return;
    }

    printf("Username: %s, Password: %s\n", accounts[index].username, accounts[index].password);
    view_accounts(index + 1);
}

void delete_account() {
    if (account_count == 0) {
        printf("No accounts available to delete.\n\n");
        menu();
        return;
    }

    printf("Enter index of account to delete (0 to %d): ", account_count - 1);
    int index;
    scanf("%d", &index);
    
    if (index < 0 || index >= account_count) {
        printf("Invalid index! Please try again.\n");
        delete_account();
        return;
    }

    confirm_delete(index);
}

void confirm_delete(int index) {
    printf("Are you sure you want to delete account '%s'? (Y/N): ", accounts[index].username);
    char choice;
    getchar();  // To clear newline character from buffer
    choice = getchar();

    if (choice == 'Y' || choice == 'y') {
        for (int i = index; i < account_count - 1; i++) {
            accounts[i] = accounts[i + 1];
        }
        account_count--;
        printf("Account deleted successfully!\n\n");
    } else {
        printf("Account deletion cancelled.\n\n");
    }

    menu();
}

void menu() {
    printf("Password Management System\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    
    int option;
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            add_account();
            break;
        case 2:
            view_accounts(0);
            break;
        case 3:
            delete_account();
            break;
        case 4:
            printf("Exiting the system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option! Try again.\n\n");
            menu();
            break;
    }
}

int main() {
    menu();
    return 0;
}