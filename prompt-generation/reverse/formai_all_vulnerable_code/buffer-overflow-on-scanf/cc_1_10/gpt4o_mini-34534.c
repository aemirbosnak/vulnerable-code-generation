//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int account_id;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts, limit reached!\n");
        return;
    }
    Account new_account;
    new_account.account_id = account_count + 1;  // Incremental ID
    printf("Enter name for the account: ");
    scanf(" %[^\n]", new_account.name);
    new_account.balance = 0.0;
    accounts[account_count++] = new_account;
    printf("Account created successfully! Your account ID is %d.\n", new_account.account_id);
}

void view_account(int account_id) {
    if (account_id < 1 || account_id > account_count) {
        printf("Account not found!\n");
        return;
    }
    Account acc = accounts[account_id - 1];
    printf("Account ID: %d\n", acc.account_id);
    printf("Name: %s\n", acc.name);
    printf("Balance: $%.2f\n", acc.balance);
}

void deposit(int account_id, float amount) {
    if (account_id < 1 || account_id > account_count) {
        printf("Account not found!\n");
        return;
    }
    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }
    accounts[account_id - 1].balance += amount;
    printf("Successfully deposited $%.2f to account %d.\n", amount, account_id);
}

void withdraw(int account_id, float amount) {
    if (account_id < 1 || account_id > account_count) {
        printf("Account not found!\n");
        return;
    }
    if (amount <= 0) {
        printf("Withdrawal amount must be positive!\n");
        return;
    }
    if (accounts[account_id - 1].balance < amount) {
        printf("Insufficient funds!\n");
        return;
    }
    accounts[account_id - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from account %d.\n", amount, account_id);
}

void show_menu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice, account_id;
    float amount;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                printf("Enter account ID to view: ");
                scanf("%d", &account_id);
                view_account(account_id);
                break;
            case 3:
                printf("Enter account ID to deposit into: ");
                scanf("%d", &account_id);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_id, amount);
                break;
            case 4:
                printf("Enter account ID to withdraw from: ");
                scanf("%d", &account_id);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_id, amount);
                break;
            case 5:
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}