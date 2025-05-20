//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LEN 30
#define MAX_USERNAME_LEN 20
#define MAX_ACCOUNTS 100

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Account;

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

bool isValidChar(char c) {
    if ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9')
        || (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_')) {
        return true;
    }
    return false;
}

bool isUsernameTaken(char* username) {
    for (int i = 0; i < totalAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return true;
        }
    }
    return false;
}

void createAccount() {
    printf("\nEnter your username (up to 20 characters): ");
    char username[MAX_USERNAME_LEN];
    scanf("%s", username);

    if (isUsernameTaken(username)) {
        printf("\nThat username is already taken. Please try a different one.\n");
        return;
    }

    printf("\nEnter your new password (must be 8-30 characters long and contain at least one uppercase letter, one lowercase letter, and one symbol): ");
    char password[MAX_PASSWORD_LEN];
    scanf("%s", password);

    // check password requirements
    if (strlen(password) < 8 || strlen(password) > 30) {
        printf("\nPassword must be between 8 and 30 characters long.\n");
        return;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasSymbol = false;

    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = true;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = true;
        } else if (isValidChar(password[i])) {
            hasSymbol = true;
        } else {
            printf("\nPassword contains an invalid character: %c\n", password[i]);
            return;
        }
    }

    if (!hasUppercase || !hasLowercase || !hasSymbol) {
        printf("\nPassword must contain at least one uppercase letter, one lowercase letter, and one symbol.\n");
        return;
    }

    Account newAccount;
    strcpy(newAccount.username, username);
    strcpy(newAccount.password, password);
    accounts[totalAccounts] = newAccount;
    totalAccounts++;

    printf("\nAccount successfully created.\n");
}

void printAccounts() {
    printf("\nAccounts:\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("%s: %s\n", accounts[i].username, accounts[i].password);
    }
}

int main() {
    printf("--- Password Manager ---\n\n");

    while (true) {
        printf("Enter 1 to create an account, 2 to view existing accounts, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            createAccount();
        } else if (choice == 2) {
            printAccounts();
        } else if (choice == 3) {
            printf("\nExiting.\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}