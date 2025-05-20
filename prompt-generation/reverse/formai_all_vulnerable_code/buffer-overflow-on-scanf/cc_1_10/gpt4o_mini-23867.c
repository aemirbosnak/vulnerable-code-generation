//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: satisfied
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
        printf("Account limit reached. Cannot create new account.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1;
    printf("Enter your name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;

    accounts[account_count] = new_account;
    account_count++;

    printf("Account created successfully! Your account number is: %d\n", new_account.account_number);
}

void deposit_money() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number <= 0 || account_number > account_count) {
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
    printf("Successfully deposited %.2f.\n", amount);
    printf("New balance: %.2f\n", accounts[account_number - 1].balance);
}

void withdraw_money() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number <= 0 || account_number > account_count) {
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
        printf("Insufficient funds. Current balance: %.2f\n", accounts[account_number - 1].balance);
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew %.2f.\n", amount);
    printf("New balance: %.2f\n", accounts[account_number - 1].balance);
}

void view_balance() {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Account Holder: %s\n", accounts[account_number - 1].name);
    printf("Account Balance: %.2f\n", accounts[account_number - 1].balance);
}

void display_all_accounts() {
    printf("\nList of Accounts:\n");
    printf("Account Number\tName\t\tBalance\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < account_count; i++) {
        printf("%d\t\t%s\t\t%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                view_balance();
                break;
            case 5:
                display_all_accounts();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}