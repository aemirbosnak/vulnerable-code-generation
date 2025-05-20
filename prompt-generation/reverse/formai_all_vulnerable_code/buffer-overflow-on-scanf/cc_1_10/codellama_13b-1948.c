//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: surprised
/*
 * Unique C Banking Record System example program in a surprised style
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 30

struct Transaction {
    char name[MAX_NAME_LENGTH];
    int amount;
    int balance;
};

void print_menu(void) {
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Balance\n");
    printf("4. Exit\n");
}

int get_transaction_type(void) {
    int type;
    printf("Enter transaction type: ");
    scanf("%d", &type);
    return type;
}

int get_transaction_amount(void) {
    int amount;
    printf("Enter transaction amount: ");
    scanf("%d", &amount);
    return amount;
}

void deposit(struct Transaction *transaction) {
    transaction->balance += get_transaction_amount();
}

void withdraw(struct Transaction *transaction) {
    transaction->balance -= get_transaction_amount();
}

void print_balance(struct Transaction *transaction) {
    printf("Balance: %d\n", transaction->balance);
}

int main(void) {
    struct Transaction transaction;
    int type;

    printf("Welcome to the Banking Record System!\n");
    print_menu();

    while ((type = get_transaction_type()) != 4) {
        switch (type) {
            case 1:
                deposit(&transaction);
                break;
            case 2:
                withdraw(&transaction);
                break;
            case 3:
                print_balance(&transaction);
                break;
            default:
                printf("Invalid transaction type\n");
                break;
        }
        print_menu();
    }

    return 0;
}