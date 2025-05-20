//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define BUFFER_SIZE 256

typedef struct {
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
} Account;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void displayMenu() {
    printf("=== Password Manager ===\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Exit\n");
    printf("========================\n");
    printf("Choose an option: ");
}

void addAccount(Account accounts[], int *accountCount) {
    if (*accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot add more accounts.\n");
        return;
    }

    Account newAccount;
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    accounts[*accountCount] = newAccount;
    (*accountCount)++;
    printf("Account added successfully!\n");
}

void viewAccounts(Account accounts[], int accountCount) {
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("=== List of Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("%d. Username: %s  |  Password: %s\n", i + 1, accounts[i].username, accounts[i].password);
    }
    printf("========================\n");
}

void deleteAccount(Account accounts[], int *accountCount) {
    if (*accountCount == 0) {
        printf("No accounts to delete.\n");
        return;
    }

    int index;
    viewAccounts(accounts, *accountCount);
    printf("Enter the account number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = index - 1; i < *accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    (*accountCount)--; // Decrement account count
    printf("Account deleted successfully!\n");
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int option;

    do {
        clearScreen();
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addAccount(accounts, &accountCount);
                break;
            case 2:
                viewAccounts(accounts, accountCount);
                break;
            case 3:
                deleteAccount(accounts, &accountCount);
                break;
            case 4:
                printf("Exiting the Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("Press Enter to continue...");
        getchar(); // Clear newline left by scanf
        getchar(); // Wait for user to press Enter
    } while (option != 4);

    return 0;
}