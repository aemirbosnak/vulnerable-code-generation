//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 16
#define NAME_LENGTH 50
#define TRANSACTION_HISTORY_LENGTH 100

typedef enum { DEPOSIT, WITHDRAWAL } TransactionType;

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char accountHolderName[NAME_LENGTH];
    double balance;
    char transactionHistory[TRANSACTION_HISTORY_LENGTH][100];
    int transactionCount;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu() {
    printf("\n--- Galactic Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Show Transaction History\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    BankAccount newAccount;
    printf("Enter Account Number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", newAccount.accountHolderName);
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void viewAccount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter Account Number to view: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("\nAccount Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].accountHolderName);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            sprintf(accounts[i].transactionHistory[accounts[i].transactionCount++], "Deposited: $%.2f", amount);
            printf("Deposit successful! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
                return;
            }
            accounts[i].balance -= amount;
            sprintf(accounts[i].transactionHistory[accounts[i].transactionCount++], "Withdrew: $%.2f", amount);
            printf("Withdrawal successful! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void showTransactionHistory() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("\nTransaction History for Account Number %s:\n", accounts[i].accountNumber);
            for (int j = 0; j < accounts[i].transactionCount; j++) {
                printf("%s\n", accounts[i].transactionHistory[j]);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                showTransactionHistory();
                break;
            case 6:
                printf("Exiting... Thank you for using the Galactic Banking Record System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}