//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define ACCOUNT_NUMBER_LENGTH 8

typedef struct {
    int account_number;
    int balance;
    char first_name[30];
    char last_name[30];
} Account;

void print_account(Account account) {
    printf("Account number: %08d\n", account.account_number);
    printf("Name: %s %s\n", account.first_name, account.last_name);
    printf("Balance: $%d\n", account.balance);
}

int create_account(Account *accounts, int num_accounts) {
    int account_num, balance;
    char first_name[30], last_name[30];
    printf("Enter account number (8 digits max): ");
    scanf("%d", &account_num);
    getchar(); // to consume the \n left by scanf
    printf("Enter first name: ");
    gets(first_name);
    printf("Enter last name: ");
    gets(last_name);
    printf("Enter initial balance: $");
    scanf("%d", &balance);
    getchar(); // to consume the \n left by scanf
    
    // check if account number already exists
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_num) {
            printf("Error: An account with number %08d already exists\n", account_num);
            return num_accounts; // return original array size
        }
    }

    // add new account to array
    if (num_accounts < MAX_ACCOUNTS) {
        Account new_account = { account_num, balance, "", "" };
        strcpy(new_account.first_name, first_name);
        strcpy(new_account.last_name, last_name);
        accounts[num_accounts] = new_account;
        printf("Account %08d successfully created\n", account_num);
        num_accounts++;
    }
    else {
        printf("Error: Bank database is full\n");
    }
    return num_accounts;
}

void view_account(Account *accounts, int num_accounts) {
    int account_num;
    printf("Enter account number to view: ");
    scanf("%d", &account_num);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_num) {
            print_account(accounts[i]);
            return;
        }
    }
    printf("Error: Account with number %08d not found\n", account_num);
}

void deposit(Account *accounts, int num_accounts) {
    int account_num, deposit_amt;
    printf("Enter account number to deposit to: ");
    scanf("%d", &account_num);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_num) {
            printf("Enter amount to deposit: $");
            scanf("%d", &deposit_amt);
            accounts[i].balance += deposit_amt;
            printf("New balance: $%d\n", accounts[i].balance);
            return;
        }
    }
    printf("Error: Account with number %08d not found\n", account_num);
}

void withdraw(Account *accounts, int num_accounts) {
    int account_num, withdraw_amt;
    printf("Enter account number to withdraw from: ");
    scanf("%d", &account_num);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_num) {
            printf("Enter amount to withdraw: $");
            scanf("%d", &withdraw_amt);
            if (accounts[i].balance < withdraw_amt) {
                printf("Error: Not enough funds in account\n");
                return;
            }
            accounts[i].balance -= withdraw_amt;
            printf("New balance: $%d\n", accounts[i].balance);
            return;
        }
    }
    printf("Error: Account with number %08d not found\n", account_num);
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    char option;

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1) Create new account\n");
        printf("2) View existing account\n");
        printf("3) Deposit to account\n");
        printf("4) Withdraw from account\n");
        printf("5) Quit\n");

        scanf("%c", &option);
        getchar(); // to consume the \n left by scanf

        switch (option) {
        case '1':
            num_accounts = create_account(accounts, num_accounts);
            break;
        case '2':
            view_account(accounts, num_accounts);
            break;
        case '3':
            deposit(accounts, num_accounts);
            break;
        case '4':
            withdraw(accounts, num_accounts);
            break;
        case '5':
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid option. Please try again\n");
        }
    }

    return 0;
}