//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: retro
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

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayMenu();
int findAccount(int accountNumber);

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                checkBalance();
                break;
            case 5:
                printf("Exiting... Thank you for using the Banking System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n====================\n");
    printf("  Banking Menu\n");
    printf("====================\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached. Cannot create more.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposit successful! New balance is: %.2f\n", accounts[index].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient funds! Current balance is: %.2f\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawal successful! New balance is: %.2f\n", accounts[index].balance);
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Account holder: %s\n", accounts[index].name);
    printf("Current balance: %.2f\n", accounts[index].balance);
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1; // account not found
}