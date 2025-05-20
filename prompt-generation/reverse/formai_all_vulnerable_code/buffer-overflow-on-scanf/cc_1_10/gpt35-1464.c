//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LENGTH 20

struct Account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct PasswordManager {
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts;
};

void printMenu() {
    printf("\n\nPassword Manager\n\n");
    printf("1. View Accounts\n");
    printf("2. Add Account\n");
    printf("3. Remove Account\n");
    printf("4. Change Password\n");
    printf("5. Exit\n\n");
}

void printAccounts(struct PasswordManager *pm) {
    printf("\nAccounts:\n\n");
    for (int i = 0; i < pm->numAccounts; i++) {
        printf("Username: %s, Password: %s\n", pm->accounts[i].username, pm->accounts[i].password);
    }
}

void addAccount(struct PasswordManager *pm) {
    if (pm->numAccounts == MAX_ACCOUNTS) {
        printf("\nMax number of accounts reached.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("\nEnter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(pm->accounts[pm->numAccounts].username, username);
    strcpy(pm->accounts[pm->numAccounts].password, password);
    pm->numAccounts += 1;

    printf("\nAccount added successfully.\n");
}

void removeAccount(struct PasswordManager *pm) {
    if (pm->numAccounts == 0) {
        printf("\nNo accounts to remove.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];

    printf("\nEnter username to remove: ");
    scanf("%s", username);

    for (int i = 0; i < pm->numAccounts; i++) {
        if (strcmp(pm->accounts[i].username, username) == 0) {
            for (int j = i; j < pm->numAccounts - 1; j++) {
                strcpy(pm->accounts[j].username, pm->accounts[j + 1].username);
                strcpy(pm->accounts[j].password, pm->accounts[j + 1].password);
            }
            pm->numAccounts -= 1;
            printf("\nAccount removed successfully.\n");
            return;
        }
    }

    printf("\nAccount not found.\n");
}

void changePassword(struct PasswordManager *pm) {
    if (pm->numAccounts == 0) {
        printf("\nNo accounts to change password for.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];
    char oldPassword[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];

    printf("\nEnter username for account to change password: ");
    scanf("%s", username);

    printf("Enter old password: ");
    scanf("%s", oldPassword);

    for (int i = 0; i < pm->numAccounts; i++) {
        if (strcmp(pm->accounts[i].username, username) == 0 && strcmp(pm->accounts[i].password, oldPassword) == 0) {
            printf("Enter new password: ");
            scanf("%s", newPassword);
            strcpy(pm->accounts[i].password, newPassword);
            printf("\nPassword changed successfully.\n");
            return;
        }
    }

    printf("\nInvalid username or password.\n");
}

int main() {
    struct PasswordManager pm;
    pm.numAccounts = 0;

    int choice;

    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printAccounts(&pm);
                break;
            case 2:
                addAccount(&pm);
                break;
            case 3:
                removeAccount(&pm);
                break;
            case 4:
                changePassword(&pm);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}