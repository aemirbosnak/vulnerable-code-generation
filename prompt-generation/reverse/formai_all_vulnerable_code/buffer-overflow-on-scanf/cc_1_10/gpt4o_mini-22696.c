//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Error: Maximum accounts reached.\n");
        return;
    }
    
    Account new_account;

    printf("Enter name: ");
    scanf("%s", new_account.name);
    new_account.account_number = account_count + 1; // Simple incremental account number
    new_account.balance = 0.0;

    accounts[account_count] = new_account;
    account_count++;
    printf("Account created! Your account number is %d\n", new_account.account_number);
}

void view_account(int account_number) {
    if (account_number <= 0 || account_number > account_count) {
        printf("Error: Invalid account number.\n");
        return;
    }
    
    Account acc = accounts[account_number - 1];
    printf("Account Number: %d\n", acc.account_number);
    printf("Holder Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

void deposit(int account_number, float amount) {
    if (account_number <= 0 || account_number > account_count || amount <= 0) {
        printf("Error: Invalid transaction.\n");
        return;
    }
    
    accounts[account_number - 1].balance += amount;
    printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, account_number, accounts[account_number - 1].balance);
}

void withdraw(int account_number, float amount) {
    if (account_number <= 0 || account_number > account_count || amount <= 0) {
        printf("Error: Invalid transaction.\n");
        return;
    }

    if (accounts[account_number - 1].balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n", amount, account_number, accounts[account_number - 1].balance);
}

void display_all_accounts() {
    if (account_count == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("All Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("---------------------\n");
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Holder Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
    }
    printf("---------------------\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2: {
                int account_number;
                printf("Enter account number: ");
                scanf("%d", &account_number);
                view_account(account_number);
                break;
            }
            case 3: {
                int account_number;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            }
            case 4: {
                int account_number;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            }
            case 5:
                display_all_accounts();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Error: Invalid choice. Please try again.\n");
        }
    }

    return 0;
}