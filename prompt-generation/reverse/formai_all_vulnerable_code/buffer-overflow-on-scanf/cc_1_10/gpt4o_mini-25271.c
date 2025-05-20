//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct Account {
    int accountId;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit();
void withdraw();
void viewAccounts();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n=========================\n");
        printf("  Welcome to Bank App!  \n");
        printf("=========================\n");
        printf("1. Create Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. View Accounts\n");
        printf("5. Exit\n");
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);
        clearBuffer();

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
                viewAccounts();
                break;
            case 5:
                printf("Thank you for using the Bank App. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Sorry! Account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    newAccount.accountId = accountCount + 1;  // ID starts from 1
    printf("Enter name for the new account: ");
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // remove newline
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account ID: %d\n", newAccount.accountId);
}

void deposit() {
    int id;
    float amount;
    printf("Enter Account ID to deposit into: ");
    scanf("%d", &id);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (id < 1 || id > accountCount || amount < 0) {
        printf("Invalid account ID or deposit amount.\n");
        return;
    }

    accounts[id - 1].balance += amount;
    printf("Successfully deposited %.2f to account ID %d.\n", amount, id);
}

void withdraw() {
    int id;
    float amount;
    printf("Enter Account ID to withdraw from: ");
    scanf("%d", &id);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (id < 1 || id > accountCount || amount < 0) {
        printf("Invalid account ID or withdrawal amount.\n");
        return;
    }

    if (accounts[id - 1].balance < amount) {
        printf("Insufficient balance in account ID %d.\n", id);
    } else {
        accounts[id - 1].balance -= amount;
        printf("Successfully withdrew %.2f from account ID %d.\n", amount, id);
    }
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n--- Account Listing ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account ID: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountId, accounts[i].name, accounts[i].balance);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // clear the input buffer
}