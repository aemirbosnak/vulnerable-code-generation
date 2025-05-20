//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float balance;
    int account_number;
    int is_account_active;
} Account;

void initialize_accounts(Account accounts[], int *num_accounts);
void create_account(Account accounts[], int *num_accounts);
void deposit(Account accounts[], int num_accounts);
void withdraw(Account accounts[], int num_accounts);
void display_accounts(Account accounts[], int num_accounts);
void show_menu(void);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;

    initialize_accounts(accounts, &num_accounts);

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                display_accounts(accounts, num_accounts);
                break;
            case 5:
                printf("Thank you for visiting Fantasy Bank!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initialize_accounts(Account accounts[], int *num_accounts) {
    *num_accounts = 0;
}

void create_account(Account accounts[], int *num_accounts) {
    if (*num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached! Cannot create more accounts.\n");
        return;
    }

    Account new_account;
    printf("Enter your creature name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;
    new_account.account_number = *num_accounts + 1;
    new_account.is_account_active = 1;

    accounts[*num_accounts] = new_account;
    (*num_accounts)++;
    printf("Account created for %s with account number %d.\n", new_account.name, new_account.account_number);
}

void deposit(Account accounts[], int num_accounts) {
    int account_number;
    float amount;

    printf("Enter account number to deposit into: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > num_accounts || !accounts[account_number - 1].is_account_active) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited %.2f into %s's account.\n", amount, accounts[account_number - 1].name);
}

void withdraw(Account accounts[], int num_accounts) {
    int account_number;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > num_accounts || !accounts[account_number - 1].is_account_active) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }

    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient funds in account of %s.\n", accounts[account_number - 1].name);
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew %.2f from %s's account.\n", amount, accounts[account_number - 1].name);
}

void display_accounts(Account accounts[], int num_accounts) {
    printf("=== Account List ===\n");
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].is_account_active) {
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",
                   accounts[i].account_number, accounts[i].name, accounts[i].balance);
        }
    }
}

void show_menu(void) {
    printf("\n==== Fantasy Bank Menu ====\n");
    printf("1. Create an account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Display all accounts\n");
    printf("5. Exit\n");
}