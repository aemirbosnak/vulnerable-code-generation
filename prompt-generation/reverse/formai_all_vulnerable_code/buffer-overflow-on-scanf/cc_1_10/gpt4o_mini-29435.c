//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float balance;
} Account;

Account* accounts[MAX_ACCOUNTS];
int accountCount = 0;

void printMenu() {
    printf("\n--- Banking System Menu ---\n");
    printf("1. Create an Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create new account. Maximum accounts reached.\n");
        return;
    }

    Account *newAccount = (Account *)malloc(sizeof(Account));

    if (newAccount == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newAccount->id = accountCount + 1; // ID starts from 1
    printf("Enter account holder's name: ");
    scanf("%s", newAccount->name);
    newAccount->balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Account ID: %d\n", newAccount->id);
}

void depositMoney() {
    int id;
    float amount;

    printf("Enter your Account ID: ");
    scanf("%d", &id);

    if (id < 1 || id > accountCount) {
        printf("Invalid Account ID!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! It must be greater than 0.\n");
        return;
    }

    accounts[id - 1]->balance += amount;
    printf("Deposited %.2f to account ID %d. New balance: %.2f\n",
           amount, id, accounts[id - 1]->balance);
}

void withdrawMoney() {
    int id;
    float amount;

    printf("Enter your Account ID: ");
    scanf("%d", &id);

    if (id < 1 || id > accountCount) {
        printf("Invalid Account ID!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! It must be greater than 0.\n");
        return;
    }

    if (amount > accounts[id - 1]->balance) {
        printf("Insufficient funds! Current balance: %.2f\n",
               accounts[id - 1]->balance);
        return;
    }

    accounts[id - 1]->balance -= amount;
    printf("Withdrew %.2f from account ID %d. New balance: %.2f\n",
           amount, id, accounts[id - 1]->balance);
}

void checkBalance() {
    int id;

    printf("Enter your Account ID: ");
    scanf("%d", &id);

    if (id < 1 || id > accountCount) {
        printf("Invalid Account ID!\n");
        return;
    }

    printf("Current balance for account ID %d (%s): %.2f\n",
           id, accounts[id - 1]->name, accounts[id - 1]->balance);
}

void freeAccounts() {
    for (int i = 0; i < accountCount; i++) {
        free(accounts[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Select an option: ");
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
                freeAccounts();
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}