//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACC_NUMBER_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACC_NUMBER_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Funds\n");
    printf("4. Withdraw Funds\n");
    printf("5. List All Accounts\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }

    Account newAccount;
    printf("Enter account holder's name: ");
    fgets(newAccount.name, NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline character

    printf("Enter account number: ");
    fgets(newAccount.accountNumber, ACC_NUMBER_LENGTH, stdin);
    newAccount.accountNumber[strcspn(newAccount.accountNumber, "\n")] = 0;

    newAccount.balance = 0.0; // Initial balance is zero
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void viewAccount() {
    char accNumber[ACC_NUMBER_LENGTH];
    printf("Enter account number to view: ");
    fgets(accNumber, ACC_NUMBER_LENGTH, stdin);
    accNumber[strcspn(accNumber, "\n")] = 0;

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accNumber) == 0) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositFunds() {
    char accNumber[ACC_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for deposit: ");
    fgets(accNumber, ACC_NUMBER_LENGTH, stdin);
    accNumber[strcspn(accNumber, "\n")] = 0;

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            getchar(); // Consume the newline character after number input
            if (amount < 0) {
                printf("Please enter a valid amount.\n");
                return;
            }
            accounts[i].balance += amount;
            printf("Amount deposited successfully! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawFunds() {
    char accNumber[ACC_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for withdrawal: ");
    fgets(accNumber, ACC_NUMBER_LENGTH, stdin);
    accNumber[strcspn(accNumber, "\n")] = 0;

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            getchar(); // Consume the newline character after number input
            if (amount < 0) {
                printf("Please enter a valid amount.\n");
                return;
            }
            if (amount > accounts[i].balance) {
                printf("Insufficient funds. Current balance: $%.2f\n", accounts[i].balance);
                return;
            }
            accounts[i].balance -= amount;
            printf("Amount withdrawn successfully! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void listAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    printf("\n--- List of All Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Holder: %s, Account Number: %s, Balance: $%.2f\n",
               accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after number input

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                depositFunds();
                break;
            case 4:
                withdrawFunds();
                break;
            case 5:
                listAllAccounts();
                break;
            case 6:
                printf("Exiting the Banking Record System. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}