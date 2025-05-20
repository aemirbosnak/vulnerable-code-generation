//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define INITIAL_BALANCE 1000.00

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
} Account;

Account bankAccounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void viewAccount();
void deposit();
void withdraw();
void listAccounts();
void showMenu();

int main() {
    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                viewAccount();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting the Banking System. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void showMenu() {
    printf("\n=== Welcome to the Simple Banking System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Information\n");
    printf("5. List All Accounts\n");
    printf("6. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Assigning a unique account number
    printf("Enter account holder's name: ");
    getchar(); // Consume the newline left by scanf
    fgets(newAccount.name, NAME_LEN, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline
    newAccount.balance = INITIAL_BALANCE; // Starting balance

    bankAccounts[accountCount++] = newAccount; // Store the new account
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccount() {
    int accountNumber;
    printf("Enter account number to view: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }

    Account acc = bankAccounts[accountNumber - 1];
    printf("\n=== Account Information ===\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Current Balance: $%.2f\n", acc.balance);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Error: Deposit amount must be positive.\n");
        return;
    }

    bankAccounts[accountNumber - 1].balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", bankAccounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive.\n");
        return;
    }
    if (amount > bankAccounts[accountNumber - 1].balance) {
        printf("Error: Insufficient funds for withdrawal.\n");
        return;
    }

    bankAccounts[accountNumber - 1].balance -= amount;
    printf("Withdrawal successful! New balance: $%.2f\n", bankAccounts[accountNumber - 1].balance);
}

void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n=== List of Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", 
               bankAccounts[i].accountNumber, bankAccounts[i].name, bankAccounts[i].balance);
    }
}