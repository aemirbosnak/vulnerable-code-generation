//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of accounts and max length of strings
#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NO_LENGTH 20

// Structure to hold account information
typedef struct {
    char accountNumber[ACCOUNT_NO_LENGTH];
    char accountHolder[NAME_LENGTH];
    double balance;
} Account;

// Function prototypes
void createAccount(Account* accounts, int* accountCount);
void displayAccounts(const Account* accounts, int accountCount);
void deposit(Account* accounts, int accountCount);
void withdraw(Account* accounts, int accountCount);
void saveAccountsToFile(const Account* accounts, int accountCount);
void loadAccountsFromFile(Account* accounts, int* accountCount);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;
    
    loadAccountsFromFile(accounts, &accountCount); // Load existing accounts from file

    do {
        printf("\n===== Banking Record System =====\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                displayAccounts(accounts, accountCount);
                break;
            case 3:
                deposit(accounts, accountCount);
                break;
            case 4:
                withdraw(accounts, accountCount);
                break;
            case 5:
                saveAccountsToFile(accounts, accountCount); // Save accounts to file before exit
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount(Account* accounts, int* accountCount) {
    if (*accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    
    printf("Enter account number: ");
    scanf("%s", accounts[*accountCount].accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]s", accounts[*accountCount].accountHolder); // Read string with spaces
    accounts[*accountCount].balance = 0.0; // Initialize balance to 0.0

    (*accountCount)++;
    printf("Account created successfully!\n");
}

void displayAccounts(const Account* accounts, int accountCount) {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n===== Accounts List =====\n");
    for (int i = 0; i < accountCount; ++i) {
        printf("Account No: %s, Holder: %s, Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

void deposit(Account* accounts, int accountCount) {
    char accountNumber[ACCOUNT_NO_LENGTH];
    double amount;

    printf("Enter account number to deposit: ");
    scanf("%s", accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; ++i) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            printf("Successfully deposited %.2f into account %s.\n", amount, accountNumber);
            return;
        }
    }

    printf("Account number not found.\n");
}

void withdraw(Account* accounts, int accountCount) {
    char accountNumber[ACCOUNT_NO_LENGTH];
    double amount;

    printf("Enter account number to withdraw: ");
    scanf("%s", accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; ++i) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Successfully withdrew %.2f from account %s.\n", amount, accountNumber);
                return;
            } else {
                printf("Insufficient balance in account %s.\n", accountNumber);
                return;
            }
        }
    }

    printf("Account number not found.\n");
}

void saveAccountsToFile(const Account* accounts, int accountCount) {
    FILE* file = fopen("accounts.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    fwrite(accounts, sizeof(Account), accountCount, file);
    fclose(file);
    printf("Accounts saved successfully.\n");
}

void loadAccountsFromFile(Account* accounts, int* accountCount) {
    FILE* file = fopen("accounts.dat", "rb");
    if (file != NULL) {
        *accountCount = fread(accounts, sizeof(Account), MAX_ACCOUNTS, file);
        fclose(file);
        printf("Accounts loaded successfully. %d accounts found.\n", *accountCount);
    } else {
        printf("No existing accounts found, starting fresh.\n");
    }
}