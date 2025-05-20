//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: rigorous
// Banking Record System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_BANK_ACCOUNT_NUMBER_LENGTH 16

// Structure to store bank account information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char bank_account_number[MAX_BANK_ACCOUNT_NUMBER_LENGTH];
    double balance;
} BankAccount;

// Function to print bank account information
void print_bank_account(BankAccount *bank_account) {
    printf("Name: %s\n", bank_account->name);
    printf("Bank Account Number: %s\n", bank_account->bank_account_number);
    printf("Balance: %f\n", bank_account->balance);
}

// Function to create a new bank account
void create_bank_account(BankAccount *bank_account) {
    printf("Enter name: ");
    fgets(bank_account->name, MAX_NAME_LENGTH, stdin);
    printf("Enter bank account number: ");
    fgets(bank_account->bank_account_number, MAX_BANK_ACCOUNT_NUMBER_LENGTH, stdin);
    printf("Enter balance: ");
    scanf("%lf", &bank_account->balance);
}

// Function to deposit money into a bank account
void deposit_money(BankAccount *bank_account, double amount) {
    bank_account->balance += amount;
}

// Function to withdraw money from a bank account
void withdraw_money(BankAccount *bank_account, double amount) {
    bank_account->balance -= amount;
}

int main() {
    BankAccount account;
    create_bank_account(&account);
    print_bank_account(&account);
    deposit_money(&account, 100.00);
    print_bank_account(&account);
    withdraw_money(&account, 50.00);
    print_bank_account(&account);
    return 0;
}