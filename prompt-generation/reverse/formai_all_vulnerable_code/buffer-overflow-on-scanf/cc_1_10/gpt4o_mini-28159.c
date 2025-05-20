//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

struct Account {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    struct Account newAccount;
    newAccount.accountNumber = accountCount + 1; // simple numbering starting from 1
    
    printf("Enter your name: ");
    scanf(" %[^\n]", newAccount.name);
    
    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount; 
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    double amount;
    
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) {
        printf("Please enter a valid amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f to account number %d. New balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Please enter a valid amount.\n");
        return;
    }
    
    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance! Current Balance: %.2f\n",
               accounts[accountNumber - 1].balance);
    } else {
        accounts[accountNumber - 1].balance -= amount;
        printf("Successfully withdrew %.2f from account number %d. Remaining balance: %.2f\n",
               amount, accountNumber, accounts[accountNumber - 1].balance);
    }
}

void viewAccountDetails() {
    int accountNumber;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    struct Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder Name: %s\n", account.name);
    printf("Account Balance: %.2f\n", account.balance);
}

void showMenu() {
    printf("\n-- Banking Record System --\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Curious Banking Record System!\n");

    while (1) {
        showMenu();
        printf("Enter your choice: ");
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
                printf("Thank you for using the Curious Banking Record System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    
    return 0;
}