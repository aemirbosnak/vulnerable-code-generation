//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 30
#define MAX_BALANCE 10000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int balance;
} account;

account* newAccount(char* name) {
    account* acc = (account*)malloc(sizeof(account));
    strcpy(acc->name, name);
    acc->balance = 0;
    return acc;
}

void printAccount(account* acc) {
    printf("Account Name: %s\n", acc->name);
    printf("Balance: $%.2f\n", acc->balance);
}

void deposit(account* acc, int amount) {
    acc->balance += amount;
    printf("Deposited $%.2f\n", amount);
}

void withdraw(account* acc, int amount) {
    if (acc->balance < amount) {
        printf("Insufficient funds\n");
        return;
    }
    acc->balance -= amount;
    printf("Withdrew $%.2f\n", amount);
}

int main() {
    account* acc1 = newAccount("John Doe");
    account* acc2 = newAccount("Jane Doe");

    deposit(acc1, 1000);
    deposit(acc2, 500);

    withdraw(acc1, 200);
    withdraw(acc2, 100);

    printAccount(acc1);
    printAccount(acc2);

    free(acc1);
    free(acc2);

    return 0;
}