//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts limit reached!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    
    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;

    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited $%.2f into account #%d.\n", amount, accountNumber);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid amount or insufficient funds!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from account #%d.\n", amount, accountNumber);
}

void viewAccountDetails() {
    int accountNumber;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder Name: %s\n", acc.name);
    printf("Account Balance: $%.2f\n", acc.balance);
}

void listAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("List of all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    do {
        printf("\n-- Banking Record System --\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                viewAccountDetails();
                break;
            case 5:
                listAllAccounts();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}