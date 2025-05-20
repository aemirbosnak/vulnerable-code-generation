//FormAI DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char account_holder[MAX_NAME_SIZE];
    double balance;
} bank_account;

void deposit(bank_account *account, double amount);
void withdraw(bank_account *account, double amount);
void print_balance(bank_account account);

int main() {
    bank_account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice, account_num;
    double amount;
    char name[MAX_NAME_SIZE];

    do {
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Print Balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (num_accounts >= MAX_ACCOUNTS) {
                    printf("Cannot create more accounts.\n");
                    break;
                }
                printf("Enter account holder name: ");
                scanf("%s", name);
                accounts[num_accounts].account_number = num_accounts + 1;
                strcpy(accounts[num_accounts].account_holder, name);
                accounts[num_accounts].balance = 0.0;
                num_accounts++;
                printf("Account created successfully.\n");
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_num);
                if (account_num <= 0 || account_num > num_accounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                printf("Enter amount to deposit: $");
                scanf("%lf", &amount);
                deposit(&accounts[account_num - 1], amount);
                printf("$%.2lf deposited successfully.\n", amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_num);
                if (account_num <= 0 || account_num > num_accounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                printf("Enter amount to withdraw: $");
                scanf("%lf", &amount);
                withdraw(&accounts[account_num - 1], amount);
                printf("$%.2lf withdrawn successfully.\n", amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_num);
                if (account_num <= 0 || account_num > num_accounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                printf("Account holder: %s\n", accounts[account_num - 1].account_holder);
                printf("Account balance: $%.2lf\n", accounts[account_num - 1].balance);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void deposit(bank_account *account, double amount) {
    account->balance += amount;
}

void withdraw(bank_account *account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient balance.\n");
        return;
    }
    account->balance -= amount;
}

void print_balance(bank_account account) {
    printf("Account holder: %s\n", account.account_holder);
    printf("Account balance: $%.2lf\n", account.balance);
}