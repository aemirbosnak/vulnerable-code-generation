//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void viewAccounts(int index);
void deleteAccount();
void mainMenu();

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        mainMenu();
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", newAccount.name);  // Read string with spaces
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
    mainMenu();
}

void viewAccounts(int index) {
    if (index < accountCount) {
        printf("Account Number: %d\n", accounts[index].accountNumber);
        printf("Name: %s\n", accounts[index].name);
        printf("Balance: %.2f\n\n", accounts[index].balance);
        viewAccounts(index + 1);  // Recursive call
    } else {
        mainMenu();
    }
}

void deleteAccount() {
    int accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];  // Shift left to delete account
            }
            accountCount--;
            printf("Account deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Account number not found!\n");
    }
    
    mainMenu();
}

void mainMenu() {
    int choice;
    printf("\n=== Banking Record System ===\n");
    printf("1. Create Account\n");
    printf("2. View Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Exit\n");
    printf("Select an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            printf("=== List of Accounts ===\n");
            viewAccounts(0);  // Start from index 0
            break;
        case 3:
            deleteAccount();
            break;
        case 4:
            printf("Exiting the system...\n");
            exit(0);
        default:
            printf("Invalid option! Try again.\n");
            mainMenu();
    }
}

int main() {
    mainMenu();
    return 0;
}