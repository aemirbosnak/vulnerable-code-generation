//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit();
void withdraw();
void displayAccountInfo();
void displayAllAccounts();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n*** Banking System Menu ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Information\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
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
                displayAccountInfo();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    newAccount.balance = 0.0f;

    printf("Enter account holder name: ");
    scanf(" %[^\n]", newAccount.accountHolder);
    
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f to account number %d.\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d.\n", amount, accountNumber);
}

void displayAccountInfo() {
    int accountNumber;

    printf("Enter account number to display: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    Account account = accounts[accountNumber - 1];
    printf("\nAccount Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Account Balance: %.2f\n", account.balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\n*** All Accounts ***\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, 
               accounts[i].accountHolder, 
               accounts[i].balance);
    }
}