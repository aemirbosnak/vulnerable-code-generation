//FormAI DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_PASSWORD_LENGTH 20

struct Account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct UserManager {
    struct Account accounts[MAX_ACCOUNTS];
    int count;
};

void print_menu() {
    printf("Welcome to Password Manager!\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Change Password\n");
    printf("4. Logout\n");
    printf("5. Exit\n");
}

void create_account(struct UserManager* userManager) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Create Account\n");
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    struct Account newAccount = {0};
    strcpy(newAccount.username, username);
    strcpy(newAccount.password, password);

    userManager->accounts[userManager->count] = newAccount;
    userManager->count++;
}

int find_account(struct UserManager* userManager, char* username) {
    for (int i = 0; i < userManager->count; i++) {
        if (strcmp(userManager->accounts[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void login(struct UserManager* userManager) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Login\n");
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    int accountIndex = find_account(userManager, username);

    if (accountIndex != -1 && strcmp(userManager->accounts[accountIndex].password, password) == 0) {
        printf("Successfully logged in!\n");
    } else {
        printf("Invalid username or password.\n");
    }
}

void change_password(struct UserManager* userManager) {
    char username[MAX_PASSWORD_LENGTH];
    char oldPassword[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];

    printf("Change Password\n");
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter old password: ");
    scanf("%s", oldPassword);

    int accountIndex = find_account(userManager, username);

    if (accountIndex != -1 && strcmp(userManager->accounts[accountIndex].password, oldPassword) == 0) {
        printf("Enter new password: ");
        scanf("%s", newPassword);

        strcpy(userManager->accounts[accountIndex].password, newPassword);

        printf("Password changed successfully!\n");
    } else {
        printf("Invalid username or password.\n");
    }
}

int main() {
    struct UserManager userManager = {0};
    int choice = 0;

    while (choice != 5) {
        print_menu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account(&userManager);
                break;
            case 2:
                login(&userManager);
                break;
            case 3:
                change_password(&userManager);
                break;
            case 4:
                printf("Logged out successfully!\n");
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}