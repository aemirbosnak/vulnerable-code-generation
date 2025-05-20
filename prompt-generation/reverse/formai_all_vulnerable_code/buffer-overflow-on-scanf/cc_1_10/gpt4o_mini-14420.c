//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_ACCOUNTS 50

typedef struct {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }
    
    Account newAccount;
    printf("Enter service name: ");
    scanf("%s", newAccount.service);
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);
    
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account added successfully!\n");
}

void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts available!\n");
        return;
    }
    printf("\nStored Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Service: %s, Username: %s\n", accounts[i].service, accounts[i].username);
    }
    printf("\n");
}

void deleteAccount() {
    if (accountCount == 0) {
        printf("No accounts to delete!\n");
        return;
    }

    char serviceToDelete[MAX_PASSWORD_LENGTH];
    printf("Enter the service name to delete: ");
    scanf("%s", serviceToDelete);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].service, serviceToDelete) == 0) {
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("Account deleted successfully!\n");
            return;
        }
    }
    printf("No account found for the given service!\n");
}

void findAccount() {
    if (accountCount == 0) {
        printf("No accounts available!\n");
        return;
    }

    char serviceToFind[MAX_PASSWORD_LENGTH];
    printf("Enter the service name to find: ");
    scanf("%s", serviceToFind);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].service, serviceToFind) == 0) {
            printf("Service: %s, Username: %s, Password: %s\n", 
                    accounts[i].service, accounts[i].username, accounts[i].password);
            return;
        }
    }
    printf("No account found for the given service!\n");
}

void clearScreen() {
    // Simple function to clear the terminal screen
    printf("\033[H\033[J");
}

void displayMenu() {
    clearScreen();
    printf("Password Manager\n");
    printf("1. Add Account\n");
    printf("2. List Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Find Account\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                listAccounts();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                findAccount();
                break;
            case 5:
                printf("Exiting Password Manager! Stay secure.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        sleep(2);
    }

    return 0; // This line is never reached, but it's here for completeness.
}