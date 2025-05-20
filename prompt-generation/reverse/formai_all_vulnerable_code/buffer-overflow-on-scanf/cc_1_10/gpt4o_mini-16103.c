//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: peaceful
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
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }
    
    Account new_account;
    new_account.account_number = account_count + 1;
    
    printf("Enter your name: ");
    fgets(new_account.name, NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline

    new_account.balance = 0.0;
    
    accounts[account_count] = new_account;
    account_count++;
    
    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
}

void deposit_funds() {
    int account_number;
    float amount;
    
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // To consume the newline character after scanf
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    getchar(); // To consume the newline character after scanf

    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }
    
    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited $%.2f to account number %d.\n", amount, account_number);
}

void withdraw_funds() {
    int account_number;
    float amount;
    
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // To consume the newline character after scanf

    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    getchar(); // To consume the newline character after scanf

    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }
    
    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from account number %d.\n", amount, account_number);
}

void view_account() {
    int account_number;
    
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // To consume the newline character after scanf
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    Account acc = accounts[account_number - 1];
    printf("Account Number: %d\n", acc.account_number);
    printf("Name: %s\n", acc.name);
    printf("Balance: $%.2f\n", acc.balance);
}

void display_all_accounts() {
    printf("Displaying all accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: $%.2f\n\n", accounts[i].balance);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nWelcome to the Banking Record System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. View Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf
        
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_funds();
                break;
            case 3:
                withdraw_funds();
                break;
            case 4:
                view_account();
                break;
            case 5:
                display_all_accounts();
                break;
            case 6:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}