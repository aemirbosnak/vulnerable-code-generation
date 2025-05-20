//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

typedef struct {
    char accountName[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount();
void viewAccounts();
void deleteAccount();
void passwordManagement();

int main() {
    passwordManagement();
    return 0;
}

void passwordManagement() {
    int choice;

    do {
        printf("\n=== Password Management System ===\n");
        printf("1. Add Account\n");
        printf("2. View Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
}

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot add more accounts, maximum limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account name: ");
    fgets(newAccount.accountName, MAX_LENGTH, stdin);
    strtok(newAccount.accountName, "\n"); // Remove newline character

    printf("Enter username: ");
    fgets(newAccount.username, MAX_LENGTH, stdin);
    strtok(newAccount.username, "\n");

    printf("Enter password: ");
    fgets(newAccount.password, MAX_LENGTH, stdin);
    strtok(newAccount.password, "\n");

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account added successfully!\n");
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n=== Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account %d:\n", i + 1);
        printf("Name: %s\n", accounts[i].accountName);
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n", accounts[i].password);
        printf("\n");
    }
}

void deleteAccount() {
    if (accountCount == 0) {
        printf("No accounts available to delete.\n");
        return;
    }

    int index;
    printf("Enter the account number to delete (1 to %d): ", accountCount);
    scanf("%d", &index);
    getchar(); // consume newline

    if (index < 1 || index > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    // Shift accounts to fill the gap
    for (int i = index - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    accountCount--;
    printf("Account deleted successfully!\n");
}