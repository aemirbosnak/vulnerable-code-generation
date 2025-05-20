//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
        printf("Cannot create more accounts.\n");
        return;
    }
    
    Account new_account;
    new_account.account_number = account_count + 1; // Simple account number
    printf("Enter account holder's name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;
    
    accounts[account_count] = new_account;
    account_count++;
    printf("Account created successfully! Your account number is %d\n", new_account.account_number);
}

void deposit() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }
    
    accounts[account_number - 1].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[account_number - 1].balance);
}

void withdraw() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid withdraw amount.\n");
        return;
    }
    
    if (accounts[account_number - 1].balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[account_number - 1].balance);
}

void display_accounts() {
    printf("\n--- Account Information ---\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Account Balance: %.2f\n", accounts[i].balance);
        printf("===========================\n");
    }
}

void account_statistics() {
    float total_balance = 0;
    int total_accounts = account_count;
    float average_balance = 0;
    
    for (int i = 0; i < account_count; i++) {
        total_balance += accounts[i].balance;
    }

    if (total_accounts > 0) {
        average_balance = total_balance / total_accounts;
    }
    
    printf("\n--- Account Statistics ---\n");
    printf("Total Accounts: %d\n", total_accounts);
    printf("Total Balance: %.2f\n", total_balance);
    printf("Average Balance: %.2f\n", average_balance);
    printf("===========================\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Accounts\n");
        printf("5. Account Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                account_statistics();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}