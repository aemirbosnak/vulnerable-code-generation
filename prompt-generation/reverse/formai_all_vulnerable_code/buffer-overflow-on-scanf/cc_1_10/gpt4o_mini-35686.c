//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define BUFFER_SIZE 100

typedef struct {
    int account_number;
    char account_holder[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int total_accounts = 0;

void create_account() {
    if (total_accounts >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create a new account.\n");
        return;
    }
    
    Account new_account;
    new_account.account_number = total_accounts + 1; // simple increment account number
    printf("Enter account holder's name: ");
    fgets(new_account.account_holder, NAME_LENGTH, stdin);
    new_account.account_holder[strcspn(new_account.account_holder, "\n")] = '\0'; // Remove newline
    new_account.balance = 0.0;

    accounts[total_accounts] = new_account;
    total_accounts++;
    printf("Account created successfully! Your account number is: %d\n", new_account.account_number);
}

void deposit() {
    int account_number;
    float amount;
    
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // to consume the leftover newline

    if (account_number < 1 || account_number > total_accounts) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    getchar(); // to consume the leftover newline
    
    if (amount < 0) {
        printf("Amount cannot be negative!\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited %.2f to account %d. New balance: %.2f\n",
           amount, account_number, accounts[account_number - 1].balance);
}

void withdraw() {
    int account_number;
    float amount;
    
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // to consume the leftover newline

    if (account_number < 1 || account_number > total_accounts) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    getchar(); // to consume the leftover newline

    if (amount < 0) {
        printf("Amount cannot be negative!\n");
        return;
    }

    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient balance for withdrawal!\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account %d. New balance: %.2f\n",
           amount, account_number, accounts[account_number - 1].balance);
}

void account_info() {
    int account_number;

    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // to consume the leftover newline

    if (account_number < 1 || account_number > total_accounts) {
        printf("Account not found!\n");
        return;
    }

    Account acc = accounts[account_number - 1];
    printf("Account Information:\n");
    printf("Account Number: %d\n", acc.account_number);
    printf("Account Holder: %s\n", acc.account_holder);
    printf("Balance: %.2f\n", acc.balance);
}

void display_menu() {
    printf("\n---- Banking Record System ----\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Account Information\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // to consume the leftover newline

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                account_info();
                break;
            case 5:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}