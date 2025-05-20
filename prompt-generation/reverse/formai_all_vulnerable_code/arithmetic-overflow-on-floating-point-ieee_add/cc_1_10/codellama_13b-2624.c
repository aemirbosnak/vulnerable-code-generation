//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: peaceful
// banking_record_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ACCOUNT_LENGTH 10
#define MAX_BALANCE 100000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char account[MAX_ACCOUNT_LENGTH];
    double balance;
} Account;

void create_account(Account *account, char *name, char *account_number, double initial_balance) {
    strcpy(account->name, name);
    strcpy(account->account, account_number);
    account->balance = initial_balance;
}

void deposit(Account *account, double amount) {
    account->balance += amount;
}

void withdraw(Account *account, double amount) {
    account->balance -= amount;
}

void print_balance(Account *account) {
    printf("Balance: %f\n", account->balance);
}

int main() {
    Account account;
    char name[MAX_NAME_LENGTH];
    char account_number[MAX_ACCOUNT_LENGTH];
    double initial_balance;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter account number: ");
    scanf("%s", account_number);
    printf("Enter initial balance: ");
    scanf("%lf", &initial_balance);

    create_account(&account, name, account_number, initial_balance);

    printf("Account created successfully!\n");
    printf("Name: %s\n", account.name);
    printf("Account number: %s\n", account.account);
    printf("Initial balance: %f\n", account.balance);

    printf("Enter deposit amount: ");
    double deposit_amount;
    scanf("%lf", &deposit_amount);
    deposit(&account, deposit_amount);
    printf("Deposited %f to account %s\n", deposit_amount, account.account);

    printf("Enter withdrawal amount: ");
    double withdrawal_amount;
    scanf("%lf", &withdrawal_amount);
    withdraw(&account, withdrawal_amount);
    printf("Withdrew %f from account %s\n", withdrawal_amount, account.account);

    print_balance(&account);

    return 0;
}