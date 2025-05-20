//FormAI DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_ACCOUNTS 10

// Struct to hold username and password for an account
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

// Function prototypes
void menu();
void add_account(Account accounts[], int* num_accounts);
void view_accounts(Account accounts[], int num_accounts);
bool login(Account accounts[], int num_accounts);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;

    bool logged_in = login(accounts, num_accounts);

    if (logged_in) {
        menu();
    }

    return 0;
}

void menu() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int input;

    while (true) {
        printf("\n=== PASSWORD MANAGER ===\n");
        printf("1. Add account\n");
        printf("2. View accounts\n");
        printf("3. Logout\n");
        printf("Enter choice: ");

        scanf("%d", &input);

        switch (input) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                view_accounts(accounts, num_accounts);
                break;
            case 3:
                printf("\nLogging out...\n");
                return;
            default:
                printf("\nInvalid input. Try again.\n");
        }
    }
}

void add_account(Account accounts[], int* num_accounts) {
    if (*num_accounts >= MAX_ACCOUNTS) {
        printf("\nYou have reached the maximum number of accounts.\n");
        return;
    }

    Account new_account;

    printf("\nEnter a username: ");
    scanf("%s", new_account.username);

    printf("Enter a password (max 20 characters): ");
    scanf("%s", new_account.password);

    accounts[*num_accounts] = new_account;
    *num_accounts += 1;

    printf("\nAccount added successfully.\n");
}

void view_accounts(Account accounts[], int num_accounts) {
    if (num_accounts == 0) {
        printf("\nYou have not saved any accounts.\n");
        return;
    }

    printf("\n=== SAVED ACCOUNTS ===\n");

    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d:\n", i+1);
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n", accounts[i].password);
    }
}

bool login(Account accounts[], int num_accounts) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("=== WELCOME TO PASSWORD MANAGER ===\n");

    while (true) {
        printf("\nPlease login to continue.\n");
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        for (int i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
                printf("\nLogged in as %s.\n", username);
                return true;
            }
        }

        printf("\nInvalid username or password. Please try again.\n");
    }
}