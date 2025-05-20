//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 50
#define MAX_PASSWORD_LENGTH 20

struct account {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
};

void print_menu() {
    printf("1. Add account\n");
    printf("2. View all accounts\n");
    printf("3. Delete account\n");
    printf("4. Change password\n");
    printf("5. Exit\n");
}

int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_account(struct account *accounts, int *num_accounts) {
    if (*num_accounts < MAX_ACCOUNTS) {
        printf("Enter the username: ");
        scanf("%s", accounts[*num_accounts].username);
        printf("Enter the password: ");
        scanf("%s", accounts[*num_accounts].password);
        *num_accounts = *num_accounts + 1;
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void view_all_accounts(struct account *accounts, int num_accounts) {
    if (num_accounts == 0) {
        printf("There are no accounts.\n");
    } else {
        printf("Username\tPassword\n");
        for (int i = 0; i < num_accounts; i++) {
            printf("%s\t\t%s\n", accounts[i].username, accounts[i].password);
        }
    }
}

void delete_account(struct account *accounts, int *num_accounts) {
    char username[20];
    printf("Enter the username of the account to delete: ");
    scanf("%s", username);
    for (int i = 0; i < *num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            for (int j = i; j < *num_accounts - 1; j++) {
                strcpy(accounts[j].username, accounts[j+1].username);
                strcpy(accounts[j].password, accounts[j+1].password);
            }
            *num_accounts = *num_accounts - 1;
            printf("Account deleted.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void change_password(struct account *accounts, int num_accounts) {
    char username[20];
    printf("Enter the username of the account to change password: ");
    scanf("%s", username);
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Enter the new password: ");
            scanf("%s", accounts[i].password);
            printf("Password changed.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;
    do {
        print_menu();
        choice = get_choice();
        switch (choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                view_all_accounts(accounts, num_accounts);
                break;
            case 3:
                delete_account(accounts, &num_accounts);
                break;
            case 4:
                change_password(accounts, num_accounts);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}