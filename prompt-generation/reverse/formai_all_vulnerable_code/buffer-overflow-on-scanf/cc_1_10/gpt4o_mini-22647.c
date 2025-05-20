//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_ACCOUNTS 50

typedef struct {
    char service[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to display menu
void displayMenu() {
    printf("\nPassword Manager\n");
    printf("1. Add new account\n");
    printf("2. List all accounts\n");
    printf("3. Update an account\n");
    printf("4. Delete an account\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

// Function to add a new account
void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot add more accounts.\n");
        return;
    }
    
    Account newAccount;

    printf("Enter service name: ");
    scanf("%s", newAccount.service);
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    accounts[accountCount++] = newAccount;
    printf("Account added successfully!\n");
}

// Function to list all accounts
void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts saved.\n");
        return;
    }

    printf("\nList of accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Service: %s, Username: %s\n", accounts[i].service, accounts[i].username);
    }
}

// Function to update an account
void updateAccount() {
    char service[50];
    printf("Enter service name to update: ");
    scanf("%s", service);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].service, service) == 0) {
            printf("Updating account for service: %s\n", service);
            printf("Enter new username: ");
            scanf("%s", accounts[i].username);
            printf("Enter new password: ");
            scanf("%s", accounts[i].password);
            printf("Account updated successfully!\n");
            return;
        }
    }

    printf("Account for service '%s' not found.\n", service);
}

// Function to delete an account
void deleteAccount() {
    char service[50];
    printf("Enter service name to delete: ");
    scanf("%s", service);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].service, service) == 0) {
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("Account for service '%s' deleted successfully!\n", service);
            return;
        }
    }

    printf("Account for service '%s' not found.\n", service);
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addAccount();
                break;
            case 2:
                listAccounts();
                break;
            case 3:
                updateAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                printf("Exiting Password Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}