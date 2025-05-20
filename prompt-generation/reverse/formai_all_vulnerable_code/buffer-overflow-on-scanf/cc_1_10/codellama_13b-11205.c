//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: satisfied
/*
 * Banking Record System
 *
 * This program allows users to manage their banking records.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to store bank account information
typedef struct {
  char name[50];
  int account_number;
  float balance;
} Account;

// Function to create a new account
void create_account(Account *account) {
  // Prompt user for account information
  printf("Enter your name: ");
  scanf("%s", account->name);
  printf("Enter your account number: ");
  scanf("%d", &account->account_number);
  printf("Enter your initial balance: ");
  scanf("%f", &account->balance);
}

// Function to deposit money into an account
void deposit_money(Account *account, float amount) {
  account->balance += amount;
  printf("Your new balance is: %f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(Account *account, float amount) {
  if (account->balance >= amount) {
    account->balance -= amount;
    printf("Your new balance is: %f\n", account->balance);
  } else {
    printf("Insufficient funds\n");
  }
}

// Function to print the account information
void print_account(Account *account) {
  printf("Name: %s\n", account->name);
  printf("Account number: %d\n", account->account_number);
  printf("Balance: %f\n", account->balance);
}

int main() {
  // Create an account
  Account account;
  create_account(&account);

  // Deposit money into the account
  deposit_money(&account, 100.00);

  // Withdraw money from the account
  withdraw_money(&account, 50.00);

  // Print the account information
  print_account(&account);

  return 0;
}