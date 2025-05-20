//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }

    BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account numbering
    printf("Enter Account Holder's Name: ");
    scanf(" %[^\n]", newAccount.accountHolder);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Your Account Number is %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[accountNumber - 1].balance += amount;
    printf("Deposited %.2f to account number %d\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrawn %.2f from account number %d\n", amount, accountNumber);
}

void displayAccount() {
    int accountNumber;

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    BankAccount account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Balance: %.2f\n", account.balance);
}

void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts available!\n");
        return;
    }

    printf("List of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

void menu() {
    int choice = 0;

    while (choice != 6) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. List All Accounts\n");
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
                displayAccount();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}