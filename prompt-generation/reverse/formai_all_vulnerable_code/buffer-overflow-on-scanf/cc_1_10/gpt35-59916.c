//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_ACCOUNTS 5

struct Account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void create_account(struct Account accounts[], int* num_accounts) {
    if (*num_accounts < MAX_ACCOUNTS) {
        struct Account new_account;
        printf("Enter a username (max %d characters): ", MAX_USERNAME_LENGTH-1);
        scanf("%s", new_account.username);
        printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH-1);
        scanf("%s", new_account.password);
        accounts[*num_accounts] = new_account;
        (*num_accounts)++;
        printf("Account created successfully.\n");
    } else {
        printf("Account creation failed. Maximum number of accounts reached.\n");
    }
}

void view_accounts(struct Account accounts[], int num_accounts) {
    if (num_accounts > 0) {
        printf("Accounts:\n");
        for (int i = 0; i < num_accounts; i++) {
            printf("%s\n", accounts[i].username);
        }
    } else {
        printf("No accounts found.\n");
    }
}

void view_password(struct Account accounts[], int num_accounts, char* username) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Password for '%s': %s\n", username, accounts[i].password);
            return;
        }
    }
    printf("No account found for '%s'.\n", username);
}

void change_password(struct Account accounts[], int num_accounts, char* username, char* new_password) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            strncpy(accounts[i].password, new_password, MAX_PASSWORD_LENGTH-1);
            printf("Password changed successfully.\n");
            return;
        }
    }
    printf("No account found for '%s'.\n", username);
}

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;

    printf("Password Manager\n");
    printf("1. Create account\n");
    printf("2. View accounts\n");
    printf("3. View password\n");
    printf("4. Change password\n");
    printf("5. Quit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                view_accounts(accounts, num_accounts);
                break;
            case 3: {
                char username[MAX_USERNAME_LENGTH];
                printf("Enter username: ");
                scanf("%s", username);
                view_password(accounts, num_accounts, username);
                break;
            }
            case 4: {
                char username[MAX_USERNAME_LENGTH];
                char new_password[MAX_PASSWORD_LENGTH];
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter new password (max %d characters): ", MAX_PASSWORD_LENGTH-1);
                scanf("%s", new_password);
                change_password(accounts, num_accounts, username, new_password);
                break;
            }
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}