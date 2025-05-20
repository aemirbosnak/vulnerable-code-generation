//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char account_number[ACCOUNT_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int current_account_count = 0;

void display_menu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account Details\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

void create_account() {
    if (current_account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached, cannot create more accounts.\n");
        return;
    }

    Account new_account;
    printf("Enter account holder's name: ");
    getchar(); // Consume previous newline
    fgets(new_account.name, NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline

    printf("Enter account number: ");
    fgets(new_account.account_number, ACCOUNT_LENGTH, stdin);
    new_account.account_number[strcspn(new_account.account_number, "\n")] = 0; // Remove newline

    new_account.balance = 0.0; // Initial balance

    accounts[current_account_count++] = new_account;
    printf("Account created successfully for %s with account number %s.\n", new_account.name, new_account.account_number);
}

void deposit_money() {
    char account_number[ACCOUNT_LENGTH];
    float amount;
    printf("Enter account number to deposit into: ");
    getchar(); // Consume previous newline
    fgets(account_number, ACCOUNT_LENGTH, stdin);
    account_number[strcspn(account_number, "\n")] = 0; // Remove newline

    for (int i = 0; i < current_account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposited %.2f to account number %s. New balance: %.2f.\n", amount, accounts[i].account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw_money() {
    char account_number[ACCOUNT_LENGTH];
    float amount;
    printf("Enter account number to withdraw from: ");
    getchar(); // Consume previous newline
    fgets(account_number, ACCOUNT_LENGTH, stdin);
    account_number[strcspn(account_number, "\n")] = 0; // Remove newline

    for (int i = 0; i < current_account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance. Current balance: %.2f.\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f from account number %s. New balance: %.2f.\n", amount, accounts[i].account_number, accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void display_account_details() {
    char account_number[ACCOUNT_LENGTH];
    printf("Enter account number to display details: ");
    getchar(); // Consume previous newline
    fgets(account_number, ACCOUNT_LENGTH, stdin);
    account_number[strcspn(account_number, "\n")] = 0; // Remove newline

    for (int i = 0; i < current_account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Number: %s\n", accounts[i].account_number);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                display_account_details();
                break;
            case 5:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}