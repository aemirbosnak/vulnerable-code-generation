//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

Account *create_account(int account_number, char *name, float balance) {
    Account *account = (Account *)malloc(sizeof(Account));
    account->account_number = account_number;
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

void deposit(Account *account, float amount) {
    account->balance += amount;
}

int withdraw(Account *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        return 1;
    } else {
        return 0;
    }
}

void print_account(Account *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
    Account *account1 = create_account(12345, "John Doe", 1000);
    Account *account2 = create_account(67890, "Jane Doe", 500);

    deposit(account1, 200);
    deposit(account2, 100);

    print_account(account1);
    print_account(account2);

    withdraw(account1, 50);
    withdraw(account1, 1000);
    withdraw(account2, 200);

    print_account(account1);
    print_account(account2);

    return 0;
}