//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_FILE "accounts.dat"

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void loadAccounts();
void saveAccounts();
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayMenu();

int main() {
    loadAccounts();
    int choice;
    do {
        displayMenu();
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
                checkBalance();
                break;
            case 5:
                saveAccounts();
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void loadAccounts() {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file) {
        fread(&accountCount, sizeof(int), 1, file);
        fread(accounts, sizeof(Account), accountCount, file);
        fclose(file);
    }
}

void saveAccounts() {
    FILE *file = fopen(ACCOUNT_FILE, "wb");
    if (file) {
        fwrite(&accountCount, sizeof(int), 1, file);
        fwrite(accounts, sizeof(Account), accountCount, file);
        fclose(file);
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;  // Simple account numbering
    printf("Enter the account holder's name: ");
    scanf(" %[^\n]", newAccount.name);  // Read string including spaces
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully with account number %d.\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Must be greater than 0.\n");
        return;
    }
    
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f into account number %d.\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid amount. Cannot withdraw more than the balance.\n");
        return;
    }
    
    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d.\n", amount, accountNumber);
}

void checkBalance() {
    int accountNumber;
    
    printf("Enter account number to check balance: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Current balance for account number %d is %.2f.\n", accountNumber, accounts[accountNumber - 1].balance);
}

void displayMenu() {
    printf("\n--- Banking System Menu ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}