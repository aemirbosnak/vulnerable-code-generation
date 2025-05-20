//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: synchronous
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
        printf("Maximum account limit reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
   
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
   
    newAccount.balance = 0.0;
    accounts[accountCount] = newAccount;
    accountCount++;
   
    printf("Account created successfully. Your account number is: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;
   
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
   
    if (accountNumber > accountCount || accountNumber < 1) {
        printf("Account not found.\n");
        return;
    }
   
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
   
    if (amount <= 0) {
        printf("Please enter a valid amount.\n");
        return;
    }
    
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n", amount, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > accountCount || accountNumber < 1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Please enter a valid amount.\n");
        return;
    }

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, accounts[accountNumber - 1].balance);
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > accountCount || accountNumber < 1) {
        printf("Account not found.\n");
        return;
    }

    printf("Account holder: %s, Balance: %.2f\n", accounts[accountNumber - 1].name, accounts[accountNumber - 1].balance);
}

void displayMenu() {
    printf("\n--- Bank Account Management System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Select an option: ");
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
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}