//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 30

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
} Account;

void createAccount(Account *accounts, int *accountCount) {
    if (*accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = *accountCount + 1; // Assign a new account number
    printf("Enter name for the new account: ");
    getchar(); // Clear newline from previous input
    fgets(newAccount.name, NAME_LEN, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline
    newAccount.balance = 0.0;

    accounts[*accountCount] = newAccount;
    (*accountCount)++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit(Account *accounts, int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Amount must be positive!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposited $%.2f to account number %d. New balance: $%.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw(Account *accounts, int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Amount must be positive!\n");
        return;
    }
    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance! Current balance: $%.2f\n", accounts[accountNumber - 1].balance);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew $%.2f from account number %d. New balance: $%.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void viewAccounts(Account *accounts, int accountCount) {
    if (accountCount == 0) {
        printf("No accounts available!\n");
        return;
    }
    
    printf("\n--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: $%.2f\n\n", accounts[i].balance);
    }
}

void saveAccounts(Account *accounts, int accountCount) {
    FILE *file = fopen("accounts.dat", "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    fwrite(accounts, sizeof(Account), accountCount, file);
    fclose(file);
    printf("Account data saved successfully!\n");
}

void loadAccounts(Account *accounts, int *accountCount) {
    FILE *file = fopen("accounts.dat", "rb");
    if (!file) {
        printf("No accounts found. Starting fresh.\n");
        return;
    }
    *accountCount = fread(accounts, sizeof(Account), MAX_ACCOUNTS, file);
    fclose(file);
    printf("Account data loaded successfully! Total accounts: %d\n", *accountCount);
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    loadAccounts(accounts, &accountCount);
    
    int choice;
    while (1) {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Accounts\n");
        printf("5. Save Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                deposit(accounts, accountCount);
                break;
            case 3:
                withdraw(accounts, accountCount);
                break;
            case 4:
                viewAccounts(accounts, accountCount);
                break;
            case 5:
                saveAccounts(accounts, accountCount);
                break;
            case 6:
                printf("Thank you for using our banking system! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}