//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int balance;
} Account;

void createAccount(Account *account) {
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter initial balance: ");
    scanf("%d", &account->balance);
    printf("Account created for %s with an initial balance of $%d\n", account->name, account->balance);
}

void deposit(Account *account, int amount) {
    account->balance += amount;
    printf("Deposited $%d\n", amount);
}

void withdraw(Account *account, int amount) {
    if (amount > account->balance) {
        printf("Insufficient funds\n");
    } else {
        account->balance -= amount;
        printf("Withdrew $%d\n", amount);
    }
}

void printAccount(Account account) {
    printf("Name: %s\n", account.name);
    printf("Balance: $%d\n", account.balance);
}

int main() {
    Account account1, account2, account3;

    createAccount(&account1);
    deposit(&account1, 1000);
    printAccount(account1);

    createAccount(&account2);
    withdraw(&account2, 500);
    printAccount(account2);

    createAccount(&account3);
    deposit(&account3, 2000);
    printAccount(account3);

    return 0;
}