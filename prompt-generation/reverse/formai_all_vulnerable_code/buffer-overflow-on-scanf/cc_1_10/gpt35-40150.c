//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of accounts that can be created
#define MAX_ACCOUNTS 100

// Structure for bank account
struct Account {
    int accountNumber;
    char accountType[20];
    float balance;
};

// Function to create a new account
void createAccount(struct Account accounts[], int *count) {
    // Check if maximum accounts limit has been reached
    if (*count == MAX_ACCOUNTS) {
        printf("Error: Maximum accounts limit reached\n");
        return;
    }

    int accountNumber;
    char accountType[20];
    float balance;

    // Get account details from user
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    // Check if account number already exists
    for (int i = 0; i < *count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Error: Account number already exists\n");
            return;
        }
    }

    printf("Enter account type (savings or current): ");
    scanf("%s", accountType);

    printf("Enter balance: ");
    scanf("%f", &balance);

    // Create new account
    struct Account newAccount = { accountNumber, accountType, balance };

    // Add new account to array of accounts
    accounts[*count] = newAccount;

    // Increment count of accounts
    (*count)++;

    printf("Account created successfully\n");
}

// Function to display account details
void displayAccount(struct Account account) {
    printf("Account number: %d\n", account.accountNumber);
    printf("Account type: %s\n", account.accountType);
    printf("Balance: %.2f\n", account.balance);
}

// Function to search for an account by account number
void searchAccount(struct Account accounts[], int count, int accountNumber) {
    // Search for account with given account number
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            displayAccount(accounts[i]);
            return;
        }
    }

    printf("Error: Account not found\n");
}

// Function to deposit money into an account
void depositMoney(struct Account accounts[], int count, int accountNumber, float amount) {
    // Search for account with given account number
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount ₹%.2f deposited successfully\n", amount);
            printf("New balance: ₹%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Error: Account not found\n");
}

// Function to withdraw money from an account
void withdrawMoney(struct Account accounts[], int count, int accountNumber, float amount) {
    // Search for account with given account number
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Amount ₹%.2f withdrawn successfully\n", amount);
                printf("New balance: ₹%.2f\n", accounts[i].balance);
            } else {
                printf("Error: Insufficient balance\n");
            }
            return;
        }
    }

    printf("Error: Account not found\n");
}

// Function to display all accounts
void displayAllAccounts(struct Account accounts[], int count) {
    // Check if there are any accounts
    if (count == 0) {
        printf("No accounts found\n");
        return;
    }

    printf("All accounts:\n");
    for (int i = 0; i < count; i++) {
        displayAccount(accounts[i]);
        printf("\n");
    }
}

int main() {
    int count = 0; // Count of current accounts
    struct Account accounts[MAX_ACCOUNTS];

    int option;

    do {
        printf("\n");
        printf("1. Create account\n");
        printf("2. Search account\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Display all accounts\n");
        printf("6. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    searchAccount(accounts, count, accountNumber);
                }
                break;
            case 3:
                {
                    int accountNumber;
                    float amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter amount: ");
                    scanf("%f", &amount);
                    depositMoney(accounts, count, accountNumber, amount);
                }
                break;
            case 4:
                {
                    int accountNumber;
                    float amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter amount: ");
                    scanf("%f", &amount);
                    withdrawMoney(accounts, count, accountNumber, amount);
                }
                break;
            case 5:
                displayAllAccounts(accounts, count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid option selected\n");
                break;
        }
    } while (option != 6);

    return 0;
}