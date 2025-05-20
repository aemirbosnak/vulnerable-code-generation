//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define FILENAME "bank_accounts.dat"

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

// Function Prototypes
void addAccount();
void viewAccounts();
void depositFunds();
void withdrawFunds();
void saveAccounts();
void loadAccounts(int *accountCount);
void displayAccountDetails(Account account);

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

int main() {
    loadAccounts(&totalAccounts);
    
    int choice;
    do {
        printf("\n----- Banking Record System -----\n");
        printf("1. Add New Account\n");
        printf("2. View All Accounts\n");
        printf("3. Deposit Funds\n");
        printf("4. Withdraw Funds\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAccount(); break;
            case 2: viewAccounts(); break;
            case 3: depositFunds(); break;
            case 4: withdrawFunds(); break;
            case 5: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    saveAccounts();
    return 0;
}

void addAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Account limit reached. Unable to add new account.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = totalAccounts + 1;
    printf("Enter name for the new account: ");
    getchar(); // consume newline
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0;  // Remove newline character
    newAccount.balance = 0.0;

    accounts[totalAccounts] = newAccount;
    totalAccounts++;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

void viewAccounts() {
    printf("\n--- List of All Accounts ---\n");
    for (int i = 0; i < totalAccounts; i++) {
        displayAccountDetails(accounts[i]);
    }
}

void depositFunds() {
    int accountNumber;
    float amount;
    printf("Enter account number to deposit into: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawFunds() {
    int accountNumber;
    float amount;
    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient funds! Current balance: %.2f\n", accounts[accountNumber - 1].balance);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayAccountDetails(Account account) {
    printf("Account Number: %d, Name: %s, Balance: %.2f\n", account.accountNumber, account.name, account.balance);
}

void saveAccounts() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error saving accounts.\n");
        return;
    }
    fwrite(accounts, sizeof(Account), totalAccounts, file);
    fclose(file);
}

void loadAccounts(int *accountCount) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No previous account records found.\n");
        return;
    }
    *accountCount = fread(accounts, sizeof(Account), MAX_ACCOUNTS, file);
    fclose(file);
}