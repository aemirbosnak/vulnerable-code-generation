//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char account_type[20];
    int balance;
} BankAccount;

void create_bank_account(BankAccount *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account type: ");
    scanf("%s", account->account_type);
    printf("Enter your initial balance: ");
    scanf("%d", &account->balance);
}

void deposit_money(BankAccount *account) {
    int amount;
    printf("Enter the amount to deposit: ");
    scanf("%d", &amount);
    account->balance += amount;
    printf("Your new balance is %d.\n", account->balance);
}

void withdraw_money(BankAccount *account) {
    int amount;
    printf("Enter the amount to withdraw: ");
    scanf("%d", &amount);
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Your new balance is %d.\n", account->balance);
    } else {
        printf("Insufficient balance.\n");
    }
}

void print_account_details(BankAccount *account) {
    printf("Name: %s\n", account->name);
    printf("Account type: %s\n", account->account_type);
    printf("Balance: %d\n", account->balance);
}

int main() {
    BankAccount account;
    create_bank_account(&account);
    deposit_money(&account);
    withdraw_money(&account);
    print_account_details(&account);
    return 0;
}