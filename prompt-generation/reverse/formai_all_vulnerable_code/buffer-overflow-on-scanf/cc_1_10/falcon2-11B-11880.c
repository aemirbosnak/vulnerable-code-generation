//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNT_NUMBER 1000
#define MAX_BALANCE 999999999
#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float balance;
    char status[20];
} Account;

Account accounts[MAX_ACCOUNT_NUMBER];
int num_accounts = 0;

void create_account(Account *account) {
    if (num_accounts >= MAX_ACCOUNT_NUMBER) {
        printf("Account number limit reached. Please create a new account.\n");
        return;
    }
    account->account_number = num_accounts;
    strcpy(account->name, "Unknown");
    strcpy(account->address, "Unknown");
    account->balance = 0;
    strcpy(account->status, "Open");
    num_accounts++;
}

void display_account_menu() {
    printf("1. Create account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Balance inquiry\n");
    printf("5. Close account\n");
    printf("6. Exit\n");
}

void create_account_menu() {
    printf("Enter account number: ");
    int account_number;
    if (scanf("%d", &account_number)!= 1) {
        printf("Invalid input. Please try again.\n");
        return;
    }
    while (accounts[account_number].status[0]!= 'C') {
        printf("Account number %d already exists. Please choose another account number.\n", account_number);
        printf("Enter account number: ");
        scanf("%d", &account_number);
    }
    printf("Enter account name: ");
    char name[MAX_NAME_LENGTH];
    if (scanf("%s", name)!= 1) {
        printf("Invalid input. Please try again.\n");
        return;
    }
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Name too long. Please choose a shorter name.\n");
        return;
    }
    strcpy(accounts[account_number].name, name);
    printf("Enter account address: ");
    char address[MAX_ADDRESS_LENGTH];
    if (scanf("%s", address)!= 1) {
        printf("Invalid input. Please try again.\n");
        return;
    }
    if (strlen(address) > MAX_ADDRESS_LENGTH) {
        printf("Address too long. Please choose a shorter address.\n");
        return;
    }
    strcpy(accounts[account_number].address, address);
    printf("Enter initial balance: ");
    float balance;
    if (scanf("%f", &balance)!= 1) {
        printf("Invalid input. Please try again.\n");
        return;
    }
    if (balance < 0) {
        printf("Invalid input. Please enter a positive balance.\n");
        return;
    }
    accounts[account_number].balance = balance;
    strcpy(accounts[account_number].status, "Open");
    printf("Account created successfully.\n");
}

void deposit(Account *account) {
    if (account->status[0] == 'C') {
        printf("Account is closed. Please create a new account.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    float amount;
    if (scanf("%f", &amount)!= 1) {
        printf("Invalid input. Please try again.\n");
        return;
    }
    if (amount <= 0) {
        printf("Invalid input. Please enter a positive amount.\n");
        return;
    }
    account->balance += amount;
    printf("Deposit successful.\n");
}

void withdraw(Account *account) {
    if (account->status[0] == 'C') {
        printf("Account is closed. Please create a new account.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    float amount;
    if (scanf("%f", &amount)!= 1) {
        printf("Invalid input. Please try again.\n");
        return;
    }
    if (amount <= 0) {
        printf("Invalid input. Please enter a positive amount.\n");
        return;
    }
    if (account->balance < amount) {
        printf("Insufficient funds. Please deposit more funds.\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrawal successful.\n");
}

void balance_inquiry(Account *account) {
    if (account->status[0] == 'C') {
        printf("Account is closed. Please create a new account.\n");
        return;
    }
    printf("Current balance: %0.2f\n", account->balance);
}

void close_account(Account *account) {
    if (account->status[0]!= 'O') {
        printf("Account is already closed.\n");
        return;
    }
    account->status[0] = 'C';
    printf("Account closed successfully.\n");
}

int main() {
    int choice;
    Account account;
    while (1) {
        display_account_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_account_menu(); break;
            case 2: deposit(&account); break;
            case 3: withdraw(&account); break;
            case 4: balance_inquiry(&account); break;
            case 5: close_account(&account); break;
            case 6: exit(0);
        }
    }
    return 0;
}