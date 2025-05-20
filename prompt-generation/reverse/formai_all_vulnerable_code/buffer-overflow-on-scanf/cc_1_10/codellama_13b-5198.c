//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: realistic
// Banking Record System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for account information
struct Account {
  char name[50];
  char account_type[50];
  int account_number;
  float balance;
};

// Function to create a new account
void create_account(struct Account *account) {
  printf("Enter name: ");
  scanf("%s", account->name);
  printf("Enter account type (Savings/Checking): ");
  scanf("%s", account->account_type);
  printf("Enter account number: ");
  scanf("%d", &account->account_number);
  printf("Enter initial balance: ");
  scanf("%f", &account->balance);
}

// Function to deposit money into an account
void deposit_money(struct Account *account, float amount) {
  account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(struct Account *account, float amount) {
  if (amount > account->balance) {
    printf("Insufficient balance.\n");
  } else {
    account->balance -= amount;
  }
}

// Function to display account information
void display_account(struct Account *account) {
  printf("Name: %s\n", account->name);
  printf("Account Type: %s\n", account->account_type);
  printf("Account Number: %d\n", account->account_number);
  printf("Balance: $%.2f\n", account->balance);
}

int main() {
  struct Account account;

  // Create a new account
  create_account(&account);

  // Deposit money into the account
  deposit_money(&account, 500.00);

  // Withdraw money from the account
  withdraw_money(&account, 250.00);

  // Display account information
  display_account(&account);

  return 0;
}