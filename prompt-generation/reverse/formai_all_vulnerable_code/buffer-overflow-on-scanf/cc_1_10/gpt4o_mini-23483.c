//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LEN];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Oops! Maximum account limit reached. Can't create more accounts!\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Start account numbers from 1
    printf("Enter account holder's name: ");
    getchar();
    fgets(newAccount.name, MAX_NAME_LEN, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Yay! Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accNo;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &accNo);

    if (accNo < 1 || accNo > accountCount) {
        printf("Oh no! Account number %d does not exist!\n", accNo);
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive number to deposit.\n");
        return;
    }

    accounts[accNo - 1].balance += amount;
    printf("Hooray! You've successfully deposited $%.2f into account number %d.\n", amount, accNo);
}

void withdrawMoney() {
    int accNo;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &accNo);

    if (accNo < 1 || accNo > accountCount) {
        printf("Oh no! Account number %d does not exist!\n", accNo);
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive number to withdraw.\n");
        return;
    }

    if (accounts[accNo - 1].balance < amount) {
        printf("Oops! Insufficient funds in account number %d. You have $%.2f. \n", accNo, accounts[accNo - 1].balance);
        return;
    }

    accounts[accNo - 1].balance -= amount;
    printf("Woohoo! You've successfully withdrawn $%.2f from account number %d.\n", amount, accNo);
}

void checkBalance() {
    int accNo;
    printf("Enter your account number: ");
    scanf("%d", &accNo);

    if (accNo < 1 || accNo > accountCount) {
        printf("Oh no! Account number %d does not exist!\n", accNo);
        return;
    }

    printf("Your current balance in account number %d is $%.2f. Keep smiling!\n", accNo, accounts[accNo - 1].balance);
}

void displayMenu() {
    printf("\n\n=== Welcome to The Happy Banking System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("=============================================\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Please choose an option (1-5): ");
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
                printf("Thank you for using The Happy Banking System! Have a fantastic day!\n");
                break;
            default:
                printf("Oops! Invalid selection. Please choose again!\n");
        }
    } while (choice != 5);

    return 0;
}