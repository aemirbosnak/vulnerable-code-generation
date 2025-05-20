//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NAME_LENGTH 50

typedef struct {
    int account_number;
    char account_holder_name[ACCOUNT_NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1; // Simple incremental account number
    printf("Enter account holder name: ");
    scanf(" %[^\n]", new_account.account_holder_name); // Read string with spaces
    new_account.balance = 0.0; // Initialize balance to 0
    accounts[account_count] = new_account;
    account_count++;

    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
}

void view_account_details() {
    int account_number;
    printf("Enter your account number: ");
    scanf("%d", &account_number);

    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    Account account = accounts[account_number - 1]; // Adjust for 0-based index
    printf("Account Number: %d\n", account.account_number);
    printf("Account Holder Name: %s\n", account.account_holder_name);
    printf("Account Balance: %.2f\n", account.balance);
}

void deposit_money() {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }

    accounts[account_number - 1].balance += amount; // Update balance
    printf("Successfully deposited %.2f to account number %d.\n", amount, account_number);
}

void withdraw_money() {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }

    if (accounts[account_number - 1].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount; // Update balance
    printf("Successfully withdrew %.2f from account number %d.\n", amount, account_number);
}

void display_menu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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
                view_account_details();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                printf("Exiting the Banking Record System. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    return 0;
}