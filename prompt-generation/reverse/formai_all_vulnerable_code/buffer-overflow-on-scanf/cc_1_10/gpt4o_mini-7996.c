//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 256
#define HASHING_CONSTANT 31

typedef struct {
    char accountName[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

unsigned long hash(const char *str) {
    unsigned long hash = 0;
    while (*str) {
        hash = (hash * HASHING_CONSTANT) + *str++;
    }
    return hash % MAX_ACCOUNTS;
}

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("You have reached the maximum number of accounts!\n");
        return;
    }

    Account newAccount;
    printf("Enter account name: ");
    scanf("%s", newAccount.accountName);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    accounts[accountCount++] = newAccount;
    printf("Account successfully added!\n");
}

void findAccount() {
    char accountName[MAX_LENGTH];
    printf("Enter the account name to find: ");
    scanf("%s", accountName);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountName, accountName) == 0) {
            printf("Account found: %s, Password: %s\n", accounts[i].accountName, accounts[i].password);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void removeAccount() {
    char accountName[MAX_LENGTH];
    printf("Enter account name to remove: ");
    scanf("%s", accountName);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountName, accountName) == 0) {
            // Shift remaining accounts down
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("Account successfully removed!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }
    
    printf("List of accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("- %s\n", accounts[i].accountName);
    }
}

void displayMenu() {
    printf("Welcome to the Sherlock Holmes Password Manager!\n");
    printf("1. Add an Account\n");
    printf("2. Find an Account\n");
    printf("3. Remove an Account\n");
    printf("4. List All Accounts\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                findAccount();
                break;
            case 3:
                removeAccount();
                break;
            case 4:
                listAccounts();
                break;
            case 5:
                printf("Goodbye, and may your passwords be ever secure, dear Watson!\n");
                exit(0);
            default:
                printf("Invalid selection! Please choose again.\n");
        }
    }
    return 0;
}