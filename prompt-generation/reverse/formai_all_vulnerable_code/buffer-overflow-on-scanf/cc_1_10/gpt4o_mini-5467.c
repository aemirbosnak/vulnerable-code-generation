//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void display_menu();
void add_account();
void view_accounts();
void encrypt_password(char *password);
void decrypt_password(char *password);
int is_valid_password(const char *password);

void encrypt_password(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 5; // Simple encryption by shifting ASCII values
    }
}

void decrypt_password(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 5; // Simple decryption by reversing the shift
    }
}

int is_valid_password(const char *password) {
    int length = strlen(password);
    if (length < 8) return 0; // Minimum length check
    int has_upper = 0, has_lower = 0, has_digit = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
    }

    return has_upper && has_lower && has_digit; 
}

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }

    char password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", accounts[account_count].username);

    while (1) {
        printf("Enter password: ");
        scanf("%s", password);

        if (is_valid_password(password)) {
            strcpy(accounts[account_count].password, password);
            encrypt_password(accounts[account_count].password);
            account_count++;
            printf("Account added successfully!\n");
            return;
        } else {
            printf("Password must be at least 8 characters long, "
                   "contain at least one uppercase letter, "
                   "one lowercase letter, and one digit.\n");
        }
    }
}

void view_accounts() {
    if (account_count == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("Stored Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        char decrypted_password[MAX_LENGTH];
        strcpy(decrypted_password, accounts[i].password);
        decrypt_password(decrypted_password);
        printf("Username: %s, Password: %s\n", accounts[i].username, decrypted_password);
    }
}

void display_menu() {
    printf("\nPassword Manager Menu:\n");
    printf("1. Add account\n");
    printf("2. View accounts\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}