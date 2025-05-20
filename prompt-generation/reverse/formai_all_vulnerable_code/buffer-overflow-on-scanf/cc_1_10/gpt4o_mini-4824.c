//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ACCOUNTS 100
#define MAX_PASSWORD_LENGTH 256

typedef struct {
    char username[100];
    char password[MAX_PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void display_menu() {
    printf("\n=== Surprise Password Management System ===\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Search Account\n");
    printf("5. Exit\n");
    printf("===========================================\n");
    printf("Choose an option: ");
}

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Oh no! You can't add more accounts! Maximum limit reached.\n");
        return;
    }
    
    Account new_account;

    printf("Surprise! Enter the username: ");
    scanf("%s", new_account.username);
    
    printf("Then, what's the password? (Max %d characters): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%s", new_account.password);

    accounts[account_count++] = new_account;
    printf("Yay! Account added successfully!\n");
}

void view_accounts() {
    if (account_count == 0) {
        printf("Oops! No accounts available to view.\n");
        return;
    }

    printf("Here are your saved accounts...\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account %d: Username: %s, Password: %s\n", i + 1, accounts[i].username, accounts[i].password);
    }
}

void delete_account() {
    if (account_count == 0) {
        printf("Oh dear! No accounts to delete!\n");
        return;
    }
    
    char username[100];
    printf("Which username's account do you want to delete? Surprise me with the username: ");
    scanf("%s", username);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            for (int j = i; j < account_count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            account_count--;
            printf("Wham! The account with username %s has been deleted!\n", username);
            return;
        }
    }
    printf("Uh-oh! Account with username %s not found!\n", username);
}

void search_account() {
    if (account_count == 0) {
        printf("Oh my! No accounts to search through!\n");
        return;
    }
    
    char username[100];
    printf("Enter the username to search for: ");
    scanf("%s", username);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Surprise! Account found - Username: %s, Password: %s\n", accounts[i].username, accounts[i].password);
            return;
        }
    }
    printf("Womp womp! Account with username %s not found!\n", username);
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                delete_account();
                break;
            case 4:
                search_account();
                break;
            case 5:
                printf("Exiting the Surprise Password Management System! Take care!\n");
                break;
            default:
                printf("Hmm... That's not a valid option. Try again!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}