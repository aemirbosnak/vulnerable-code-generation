//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNTS 100

void clearConsole() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

struct account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct password_manager {
    struct account accounts[MAX_ACCOUNTS];
    int numOfAccounts;
};

void addAccount(struct password_manager* manager) {
    if (manager->numOfAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached. Delete some accounts to make space.\n");
        return;
    }
    struct account newAccount;
    printf("Enter username (max length %d) and password (max length %d):\n", MAX_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%s%s", newAccount.username, newAccount.password);
    manager->accounts[manager->numOfAccounts] = newAccount;
    manager->numOfAccounts++;
    printf("Account added successfully.\n");
}

void viewAccounts(struct password_manager* manager) {
    printf("\nList of accounts:\n");
    for (int i = 0; i < manager->numOfAccounts; i++) {
        printf("%d. %s - %s\n", i+1, manager->accounts[i].username, manager->accounts[i].password);
    }
    printf("\n");
}

void deleteAccount(struct password_manager* manager) {
    if (manager->numOfAccounts == 0) {
        printf("There are no accounts to delete.\n");
        return;
    }
    viewAccounts(manager);
    int accountIndex;
    printf("Enter the index of the account you want to delete:\n");
    scanf("%d", &accountIndex);
    if (accountIndex <= 0 || accountIndex > manager->numOfAccounts) {
        printf("Invalid account index.\n");
        return;
    }
    for (int i = accountIndex-1; i < manager->numOfAccounts-1; i++) {
        manager->accounts[i] = manager->accounts[i+1];
    }
    manager->numOfAccounts--;
    printf("Account deleted successfully.\n");
}

int main() {
    struct password_manager manager;
    manager.numOfAccounts = 0;
    char userInput;
    while (1) {
        clearConsole();
        printf("Password Manager\n");
        printf("-----------------\n");
        printf("1. Add account\n2. View accounts\n3. Delete account\n4. Exit\n");
        printf("Enter an option number (1-4):\n");
        scanf(" %c", &userInput);
        switch (userInput) {
            case '1':
                addAccount(&manager);
                break;
            case '2':
                viewAccounts(&manager);
                break;
            case '3':
                deleteAccount(&manager);
                break;
            case '4':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
        printf("Press enter to continue.\n");
        while (getchar() != '\n');
        getchar();
    }
}