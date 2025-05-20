//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define BUFFER_SIZE 1024

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LEN];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void displayMenu() {
    printf("\n=========================\n");
    printf(" Welcome to Our Bank!\n");
    printf("=========================\n");
    printf("1. Create Account\n");
    printf("2. View All Accounts\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("=========================\n");
    printf("Choose an option: ");
}

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Account limit reached! Unable to create new account.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = totalAccounts + 1; // Simple account number logic
    newAccount.balance = 0.0;

    printf("Enter account holder's name: ");
    fgets(newAccount.accountHolder, NAME_LEN, stdin);
    newAccount.accountHolder[strcspn(newAccount.accountHolder, "\n")] = 0; // Remove newline

    accounts[totalAccounts++] = newAccount;
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void viewAccounts() {
    if (totalAccounts == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\nList of Accounts:\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("Account Number: %d, Holder: %s, Balance: $%.2f\n", 
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

void depositMoney() {
    int accountNum;
    double amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accountNum);
    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);
    while ((getchar()) != '\n'); // Clear input buffer

    if (accountNum < 1 || accountNum > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    accounts[accountNum - 1].balance += amount;
    printf("Successfully deposited $%.2f into account number %d.\n", amount, accountNum);
}

void withdrawMoney() {
    int accountNum;
    double amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNum);
    printf("Enter amount to withdraw: $");
    scanf("%lf", &amount);
    while ((getchar()) != '\n'); // Clear input buffer

    if (accountNum < 1 || accountNum > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    if (amount > accounts[accountNum - 1].balance) {
        printf("Insufficient balance to withdraw that amount!\n");
        return;
    }

    accounts[accountNum - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from account number %d.\n", amount, accountNum);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while ((getchar()) != '\n'); // Clear input buffer
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Thank you for using our banking system! Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}