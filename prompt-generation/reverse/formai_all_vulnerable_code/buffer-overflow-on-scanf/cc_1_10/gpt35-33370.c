//FormAI DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME 20
#define MAX_PASSWORD 20
#define MAX_ACCOUNTS 10

typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} Account;

typedef struct {
    Account accounts[MAX_ACCOUNTS];
    int count;
} PasswordManager;

int menu() {
    int choice;

    printf("\n--- Password Manager ---\n");
    printf("1. List accounts\n");
    printf("2. Add account\n");
    printf("3. Remove account\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

int validate_username(char *username) {
    int i;

    if (strlen(username) < 6 || strlen(username) > 15)
        return 0;

    for (i = 0; i < strlen(username); i++) {
        if (!isalnum(username[i]))
            return 0;
    }

    return 1;
}

int validate_password(char *password) {
    int i;
    int has_upper = 0, has_lower = 0, has_digit = 0;

    if (strlen(password) < 8 || strlen(password) > 15)
        return 0;

    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else
            return 0;
    }

    if (!has_upper || !has_lower || !has_digit)
        return 0;

    return 1;
}

int add_account(PasswordManager *manager) {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int i;

    printf("\nEnter username (6-15 alphanumeric characters): ");
    scanf("%s", username);

    if (!validate_username(username)) {
        printf("Invalid username: must be 6-15 alphanumeric characters.\n");
        return 0;
    }

    for (i = 0; i < manager->count; i++) {
        if (strcmp(username, manager->accounts[i].username) == 0) {
            printf("Username already exists.\n");
            return 0;
        }
    }

    printf("Enter password (8-15 characters, must contain at least one uppercase letter, one lowercase letter, and one digit): ");
    scanf("%s", password);

    if (!validate_password(password)) {
        printf("Invalid password: must be 8-15 characters and contain at least one uppercase letter, one lowercase letter, and one digit.\n");
        return 0;
    }

    if (manager->count == MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return 0;
    }

    strcpy(manager->accounts[manager->count].username, username);
    strcpy(manager->accounts[manager->count].password, password);
    manager->count++;

    printf("Account added successfully.\n");

    return 1;
}

int remove_account(PasswordManager *manager) {
    char username[MAX_USERNAME];
    int i, j;

    printf("\nEnter username to remove: ");
    scanf("%s", username);

    for (i = 0; i < manager->count; i++) {
        if (strcmp(username, manager->accounts[i].username) == 0) {
            for (j = i; j < manager->count-1; j++)
                strcpy(manager->accounts[j].username, manager->accounts[j+1].username);
            manager->count--;
            printf("Account removed successfully.\n");
            return 1;
        }
    }

    printf("Account not found.\n");
    return 0;
}

void list_accounts(PasswordManager *manager) {
    int i;

    printf("\n--- Account List ---\n");

    if (manager->count == 0) {
        printf("No accounts found.\n");
        return;
    }

    for (i = 0; i < manager->count; i++) {
        printf("%s\n", manager->accounts[i].username);
    }
}

int main() {
    PasswordManager manager;
    int choice;

    manager.count = 0;

    do {
        choice = menu();

        switch (choice) {
            case 1:
                list_accounts(&manager);
                break;
            case 2:
                add_account(&manager);
                break;
            case 3:
                remove_account(&manager);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}