//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char account_holder_name[50];
    double balance;
} account;

typedef struct {
    int transaction_id;
    int account_number;
    char transaction_type[20];
    double amount;
} transaction;

account accounts[100];
transaction transactions[1000];
int num_accounts = 0;
int num_transactions = 0;

void create_account(int account_number, char *account_holder_name, double balance) {
    accounts[num_accounts].account_number = account_number;
    strcpy(accounts[num_accounts].account_holder_name, account_holder_name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

void deposit(int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            break;
        }
    }
}

void withdraw(int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
            } else {
                printf("Insufficient funds\n");
            }
            break;
        }
    }
}

void transfer(int from_account_number, int to_account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == from_account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                for (int j = 0; j < num_accounts; j++) {
                    if (accounts[j].account_number == to_account_number) {
                        accounts[j].balance += amount;
                        break;
                    }
                }
            } else {
                printf("Insufficient funds\n");
            }
            break;
        }
    }
}

void print_account_statement(int account_number) {
    printf("Account Statement\n");
    printf("Account Number: %d\n", account_number);
    printf("Account Holder Name: %s\n", accounts[account_number].account_holder_name);
    printf("Balance: %f\n", accounts[account_number].balance);
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].account_number == account_number) {
            printf("%d %s %f\n", transactions[i].transaction_id, transactions[i].transaction_type, transactions[i].amount);
        }
    }
}

int main() {
    create_account(12345, "John Doe", 1000.00);
    create_account(67890, "Jane Doe", 2000.00);

    deposit(12345, 500.00);
    withdraw(67890, 300.00);
    transfer(12345, 67890, 200.00);

    print_account_statement(12345);
    print_account_statement(67890);

    return 0;
}