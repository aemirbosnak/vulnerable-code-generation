//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME 30
#define MAX_TRANS 100

typedef struct {
    char name[MAX_NAME];
    int accountNumber;
    float balance;
    char transactions[MAX_TRANS][50];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void initAccount(Account *acc, const char *name, int accNum) {
    strncpy(acc->name, name, MAX_NAME);
    acc->accountNumber = accNum;
    acc->balance = 0.0;
    acc->transactionCount = 0;
    strcpy(acc->transactions[acc->transactionCount++], "Account created.");
    printf("Surprise! Account for %s has been created with account number %d!\n", name, accNum);
}

void displayAccount(const Account *acc) {
    printf("\nAccount Holder: %s", acc->name);
    printf("\nAccount Number: %d", acc->accountNumber);
    printf("\nCurrent Balance: %.2f", acc->balance);
    printf("\nTransactions:\n");
    for (int i = 0; i < acc->transactionCount; i++) {
        printf("  %s\n", acc->transactions[i]);
    }
}

int findAccount(int accNum) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i;
        }
    }
    return -1;
}

void deposit(int accNum, float amount) {
    int index = findAccount(accNum);
    if (index != -1) {
        accounts[index].balance += amount;
        sprintf(accounts[index].transactions[accounts[index].transactionCount++], "Deposited: %.2f", amount);
        printf("Surprise! You have successfully deposited %.2f into account %d.\n", amount, accNum);
    } else {
        printf("Oops! Account number %d not found.\n", accNum);
    }
}

void withdraw(int accNum, float amount) {
    int index = findAccount(accNum);
    if (index != -1) {
        if (amount > accounts[index].balance) {
            printf("Woah! Insufficient funds for withdrawal from account %d.\n", accNum);
        } else {
            accounts[index].balance -= amount;
            sprintf(accounts[index].transactions[accounts[index].transactionCount++], "Withdrew: %.2f", amount);
            printf("Surprise! You have successfully withdrawn %.2f from account %d.\n", amount, accNum);
        }
    } else {
        printf("Oops! Account number %d not found.\n", accNum);
    }
}

void printMenu() {
    printf("\nWelcome to the Banking Record System! Choose an option:\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account Details\n");
    printf("5. Quit\n");
}

int main() {
    int choice, accNum;
    char name[MAX_NAME];
    float amount;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (accountCount < MAX_ACCOUNTS) {
                    printf("Enter your name: ");
                    scanf("%s", name);
                    initAccount(&accounts[accountCount], name, accountCount + 1);
                    accountCount++;
                } else {
                    printf("Wow! We've hit the maximum account limit!\n");
                }
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accNum);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accNum, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accNum);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accNum, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accNum);
                int index = findAccount(accNum);
                if (index != -1) {
                    displayAccount(&accounts[index]);
                } else {
                    printf("Oops! Account number %d not found.\n", accNum);
                }
                break;
            case 5:
                printf("Thanks for using our Banking System! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Oops! Invalid choice. Please try again.\n");
        }
    }
    return 0;
}