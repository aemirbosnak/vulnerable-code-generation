//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_PASSWORD_LENGTH 100

struct account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account(char* username, char* password) {
    // Check if account already exists
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Account already exists for username %s\n", username);
            return;
        }
    }
    // Add new account
    strcpy(accounts[num_accounts].username, username);
    strcpy(accounts[num_accounts].password, password);
    num_accounts++;
    printf("Account added for username %s\n", username);
}

void remove_account(char* username) {
    // Find position of account to be removed
    int remove_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            remove_index = i;
            break;
        }
    }
    // Remove account
    if (remove_index == -1) {
        printf("Account not found for username %s\n", username);
    } else {
        for (int i = remove_index; i < num_accounts - 1; i++) {
            strcpy(accounts[i].username, accounts[i+1].username);
            strcpy(accounts[i].password, accounts[i+1].password);
        }
        num_accounts--;
        printf("Account removed for username %s\n", username);
    }
}

void update_password(char* username, char* new_password) {
    // Find account to be updated
    int update_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            update_index = i;
            break;
        }
    }
    // Update password
    if (update_index == -1) {
        printf("Account not found for username %s\n", username);
    } else {
        strcpy(accounts[update_index].password, new_password);
        printf("Password updated for username %s\n", username);
    }
}

void list_accounts() {
    printf("List of accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s\n", accounts[i].username);
    }
}

void print_menu() {
    printf("\n");
    printf("Password Manager\n");
    printf("----------------\n");
    printf("1. Add account\n");
    printf("2. Remove account\n");
    printf("3. Update password\n");
    printf("4. List accounts\n");
    printf("5. Exit\n");
    printf("----------------\n");
}

int main() {
    while (1) {
        print_menu();
        int selection;
        printf("Enter selection: ");
        scanf("%d", &selection);
        if (selection == 1) {
            char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
            printf("Enter new account username: ");
            scanf("%s", username);
            printf("Enter new account password: ");
            scanf("%s", password);
            add_account(username, password);
        } else if (selection == 2) {
            char username[MAX_PASSWORD_LENGTH];
            printf("Enter account username to remove: ");
            scanf("%s", username);
            remove_account(username);
        } else if (selection == 3) {
            char username[MAX_PASSWORD_LENGTH], new_password[MAX_PASSWORD_LENGTH];
            printf("Enter account username to update password: ");
            scanf("%s", username);
            printf("Enter new password: ");
            scanf("%s", new_password);
            update_password(username, new_password);
        } else if (selection == 4) {
            list_accounts();
        } else if (selection == 5) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid selection, please try again.\n");
        }
    }
    return 0;
}