//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount();
void depositMoney();
void withdrawMoney();
void viewAccount();
void showMenu();

int main() {
    int choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: viewAccount(); break;
            case 5: printf("Thank you for using the Banking Record System!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void showMenu() {
    printf("\n=== Banking Record System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = totalAccounts + 1;
    printf("Enter your name: ");
    getchar(); // to consume newline leftover
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // remove newline
    newAccount.balance = 0.0;

    accounts[totalAccounts] = newAccount;
    totalAccounts++;
    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNum;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &accountNum);
    if (accountNum < 1 || accountNum > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    accounts[accountNum - 1].balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n", amount, accounts[accountNum - 1].balance);
}

void withdrawMoney() {
    int accountNum;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &accountNum);
    if (accountNum < 1 || accountNum > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[accountNum - 1].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }
    accounts[accountNum - 1].balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, accounts[accountNum - 1].balance);
}

void viewAccount() {
    int accountNum;
    printf("Enter your account number: ");
    scanf("%d", &accountNum);
    if (accountNum < 1 || accountNum > totalAccounts) {
        printf("Invalid account number!\n");
        return;
    }
    Account acc = accounts[accountNum - 1];
    printf("\n=== Account Details ===\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder Name: %s\n", acc.name);
    printf("Current Balance: %.2f\n", acc.balance);
}