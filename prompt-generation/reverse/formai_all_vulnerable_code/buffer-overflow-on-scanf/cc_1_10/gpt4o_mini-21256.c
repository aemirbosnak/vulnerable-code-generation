//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_SIZE 50
#define ID_SIZE 20

typedef struct {
    char accountID[ID_SIZE];
    char accountHolder[NAME_SIZE];
    double balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void createAccount();
void viewAccounts();
void deposit();
void withdraw();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Banking Record System ===\n");
    printf("1. Create Account\n");
    printf("2. View Accounts\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }

    BankAccount newAccount;
    printf("Enter Account ID: ");
    scanf("%s", newAccount.accountID);
    printf("Enter Account Holder Name: ");
    scanf("%s", newAccount.accountHolder);
    newAccount.balance = 0.0; // Initialize balance to zero

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\n=== List of Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account ID: %s\n", accounts[i].accountID);
        printf("Account Holder: %s\n", accounts[i].accountHolder);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("------------------------\n");
    }
}

void deposit() {
    char accountID[ID_SIZE];
    double amount;
    int found = 0;

    printf("Enter Account ID for deposit: ");
    scanf("%s", accountID);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountID, accountID) == 0) {
            accounts[i].balance += amount;
            found = 1;
            printf("Successfully deposited %.2f to account ID: %s\n", amount, accountID);
            break;
        }
    }

    if (!found) {
        printf("Account ID not found!\n");
    }
}

void withdraw() {
    char accountID[ID_SIZE];
    double amount;
    int found = 0;

    printf("Enter Account ID for withdrawal: ");
    scanf("%s", accountID);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountID, accountID) == 0) {
            if (amount > accounts[i].balance) {
                printf("Insufficient funds! Current balance: %.2f\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount;
                found = 1;
                printf("Successfully withdrew %.2f from account ID: %s\n", amount, accountID);
            }
            break;
        }
    }

    if (!found) {
        printf("Account ID not found!\n");
    }
}