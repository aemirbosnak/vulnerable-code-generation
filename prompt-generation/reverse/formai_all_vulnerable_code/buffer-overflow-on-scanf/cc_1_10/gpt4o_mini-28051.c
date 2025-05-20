//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account();
void deposit();
void withdraw();
void display_accounts();
void transaction_history(int account_number, char *action, float amount);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n=== Banking Record System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                display_accounts();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }
    
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account number already exists!\n");
            return;
        }
    }

    BankAccount new_account;
    new_account.account_number = account_number;
    printf("Enter account holder name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;

    accounts[account_count++] = new_account;
    printf("Account created successfully!\n");
}

void deposit() {
    int account_number;
    float amount;
    printf("Enter account number to deposit into: ");
    scanf("%d", &account_number);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                transaction_history(account_number, "Deposit", amount);
                printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Invalid deposit amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number to withdraw from: ");
    scanf("%d", &account_number);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                transaction_history(account_number, "Withdraw", amount);
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Invalid withdrawal amount or insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void display_accounts() {
    printf("\n=== List of All Accounts ===\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("---------------------------\n");
    }
}

void transaction_history(int account_number, char *action, float amount) {
    printf("Transaction: %s\nAccount Number: %d\nAmount: %.2f\n", action, account_number, amount);
}