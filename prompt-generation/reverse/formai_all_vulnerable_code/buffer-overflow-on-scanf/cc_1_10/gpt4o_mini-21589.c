//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int acc_number;
    char name[NAME_LEN];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int total_accounts = 0;

void createAccount() {
    if (total_accounts >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }
    Account new_account;
    new_account.acc_number = total_accounts + 1;
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", new_account.name);
    new_account.balance = 0.0f;
    accounts[total_accounts++] = new_account;
    printf("Account created successfully! Account number: %d\n", new_account.acc_number);
}

void deposit() {
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    if (acc_num < 1 || acc_num > total_accounts) {
        printf("Invalid account number!\n");
        return;
    }
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    accounts[acc_num - 1].balance += amount;
    printf("Deposited %.2f to account %d. New balance: %.2f\n", amount, acc_num, accounts[acc_num - 1].balance);
}

void withdraw() {
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    if (acc_num < 1 || acc_num > total_accounts) {
        printf("Invalid account number!\n");
        return;
    }
    printf("Enter withdraw amount: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[acc_num - 1].balance) {
        printf("Invalid withdraw amount!\n");
        return;
    }
    accounts[acc_num - 1].balance -= amount;
    printf("Withdrew %.2f from account %d. New balance: %.2f\n", amount, acc_num, accounts[acc_num - 1].balance);
}

void displayAccounts() {
    printf("\n--- Account List ---\n");
    for (int i = 0; i < total_accounts; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].acc_number, accounts[i].name, accounts[i].balance);
    }
    printf("--------------------\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Accounts\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccounts(); break;
            case 0: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}