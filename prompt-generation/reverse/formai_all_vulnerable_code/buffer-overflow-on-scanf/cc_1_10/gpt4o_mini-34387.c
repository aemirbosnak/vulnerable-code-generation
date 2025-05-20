//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int account_number;
    char name[NAME_LEN];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void clear_buffer() {
    while (getchar() != '\n');
}

void create_account() {
    if(account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }
    
    Account new_account;
    new_account.account_number = account_count + 1; // Start account_number from 1
    
    printf("Enter name for account holder: ");
    fgets(new_account.name, NAME_LEN, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline
    
    new_account.balance = 0.0;
    accounts[account_count] = new_account;
    account_count++;
    
    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
}

void deposit() {
    int account_number;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if(account_number < 1 || account_number > account_count) {
        printf("Invalid account number!\n");
        clear_buffer();
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    clear_buffer();
    
    if(amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Deposited %.2f successfully! New balance: %.2f\n", amount, accounts[account_number - 1].balance);
}

void withdraw() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if(account_number < 1 || account_number > account_count) {
        printf("Invalid account number!\n");
        clear_buffer();
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    clear_buffer();

    if(amount <= 0) {
        printf("Withdrawal amount must be positive!\n");
        return;
    }

    if(accounts[account_number - 1].balance < amount) {
        printf("Insufficient funds! Current balance: %.2f\n", accounts[account_number - 1].balance);
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Withdrew %.2f successfully! New balance: %.2f\n", amount, accounts[account_number - 1].balance);
}

void view_balance() {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if(account_number < 1 || account_number > account_count) {
        printf("Invalid account number!\n");
        clear_buffer();
        return;
    }
    
    printf("Account Name: %s\nAccount Number: %d\nCurrent Balance: %.2f\n",
           accounts[account_number - 1].name,
           accounts[account_number - 1].account_number,
           accounts[account_number - 1].balance);
}

void display_menu() {
    printf("\n--- Bank Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Balance\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        clear_buffer();

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
                view_balance();
                break;
            case 5:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}