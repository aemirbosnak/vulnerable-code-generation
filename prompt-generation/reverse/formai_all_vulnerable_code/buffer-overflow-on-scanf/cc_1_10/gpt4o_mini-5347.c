//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1;

    printf("Enter your name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;

    accounts[account_count] = new_account;
    account_count++;

    printf("Account created successfully! Your account number is %d\n", new_account.account_number);
}

void deposit_money() {
    int account_number;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[account_number - 1].balance += amount;
    printf("Amount deposited successfully! New balance: %.2f\n", accounts[account_number - 1].balance);
}

void withdraw_money() {
    int account_number;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient funds. Current balance: %.2f\n", accounts[account_number - 1].balance);
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[account_number - 1].balance);
}

void check_balance() {
    int account_number;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Current balance: %.2f\n", accounts[account_number - 1].balance);
}

void display_accounts() {
    printf("\nList of Accounts:\n");
    printf("Account Number | Name              | Balance\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < account_count; i++) {
        printf("%-15d | %-17s | %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nSimple Banking System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
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
                check_balance();
                break;
            case 5:
                display_accounts();
                break;
            case 6:
                printf("Thank you for using our banking system!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}