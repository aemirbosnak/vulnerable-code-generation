//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: artistic
/*
 * Banking Record System
 *
 * A unique C program that allows users to view and manage their banking records.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a bank account
typedef struct {
  char name[50];
  char account_number[10];
  float balance;
} BankAccount;

// Function to create a new bank account
BankAccount* create_bank_account(char* name, char* account_number, float balance) {
  BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
  strcpy(account->name, name);
  strcpy(account->account_number, account_number);
  account->balance = balance;
  return account;
}

// Function to view a bank account's balance
void view_balance(BankAccount* account) {
  printf("Balance: %f\n", account->balance);
}

// Function to deposit money into a bank account
void deposit(BankAccount* account, float amount) {
  account->balance += amount;
  printf("Deposited %f. New balance: %f\n", amount, account->balance);
}

// Function to withdraw money from a bank account
void withdraw(BankAccount* account, float amount) {
  if (amount > account->balance) {
    printf("Insufficient funds\n");
  } else {
    account->balance -= amount;
    printf("Withdrawn %f. New balance: %f\n", amount, account->balance);
  }
}

int main() {
  // Create a bank account
  BankAccount* account = create_bank_account("John Doe", "123456789", 1000.00);

  // View the bank account's balance
  view_balance(account);

  // Deposit money into the bank account
  deposit(account, 500.00);

  // View the bank account's balance again
  view_balance(account);

  // Withdraw money from the bank account
  withdraw(account, 200.00);

  // View the bank account's balance again
  view_balance(account);

  // Free the bank account from memory
  free(account);

  return 0;
}