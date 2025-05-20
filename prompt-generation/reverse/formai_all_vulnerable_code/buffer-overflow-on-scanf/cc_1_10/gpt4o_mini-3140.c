//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char account_number[ACCOUNT_NUMBER_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached. Cannot add more accounts.\n");
        return;
    }
    
    Account new_account;
    printf("Enter account holder name: ");
    fgets(new_account.name, NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline character

    printf("Enter account number: ");
    fgets(new_account.account_number, ACCOUNT_NUMBER_LENGTH, stdin);
    new_account.account_number[strcspn(new_account.account_number, "\n")] = 0; // Remove newline character

    new_account.balance = 0.0f; // initial balance
    
    accounts[account_count] = new_account;
    account_count++;
    printf("Account created successfully!\n");
}

void deposit() {
    char account_number[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number: ");
    fgets(account_number, ACCOUNT_NUMBER_LENGTH, stdin);
    account_number[strcspn(account_number, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            getchar(); // Clear newline character from buffer
            accounts[i].balance += amount;
            printf("Deposited %.2f to account %s. New balance: %.2f\n", amount, accounts[i].account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    char account_number[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number: ");
    fgets(account_number, ACCOUNT_NUMBER_LENGTH, stdin);
    account_number[strcspn(account_number, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            getchar(); // Clear newline character from buffer
            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawn %.2f from account %s. New balance: %.2f\n", amount, accounts[i].account_number, accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void check_balance() {
    char account_number[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number: ");
    fgets(account_number, ACCOUNT_NUMBER_LENGTH, stdin);
    account_number[strcspn(account_number, "\n")] = 0; // Remove newline character

    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("The balance for account %s is %.2f\n", accounts[i].account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void display_accounts() {
    if (account_count == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("Current Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Holder: %s, Account Number: %s, Balance: %.2f\n",
            accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Add Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                display_accounts();
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}