//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int account_number;
    char name[50];
    char email[50];
    float balance;
};

struct Account* createAccount(int account_number, char* name, char* email, float balance) {
    struct Account* new_account = malloc(sizeof(struct Account));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    strcpy(new_account->email, email);
    new_account->balance = balance;
    return new_account;
}

void deposit(struct Account* account, float amount) {
    account->balance += amount;
}

void withdraw(struct Account* account, float amount) {
    account->balance -= amount;
}

void displayAccountInfo(struct Account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Email: %s\n", account->email);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
    struct Account* account1 = createAccount(1234, "John Doe", "johndoe@example.com", 1000.00);
    struct Account* account2 = createAccount(5678, "Jane Doe", "janedoe@example.com", 2000.00);

    deposit(account1, 500.00);
    withdraw(account2, 1000.00);

    displayAccountInfo(account1);
    displayAccountInfo(account2);

    free(account1);
    free(account2);

    return 0;
}