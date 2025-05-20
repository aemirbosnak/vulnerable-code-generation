//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: future-proof
// Banking Record System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Define the structure for a bank account
struct bank_account {
  char account_number[20];
  char name[50];
  double balance;
  time_t date_opened;
};

// Function to create a new bank account
struct bank_account* create_account(char* account_number, char* name) {
  struct bank_account* account = (struct bank_account*)malloc(sizeof(struct bank_account));
  strcpy(account->account_number, account_number);
  strcpy(account->name, name);
  account->balance = 0.0;
  account->date_opened = time(NULL);
  return account;
}

// Function to deposit money into an account
void deposit_money(struct bank_account* account, double amount) {
  account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(struct bank_account* account, double amount) {
  account->balance -= amount;
}

// Function to display the balance of an account
void display_balance(struct bank_account* account) {
  printf("Balance: $%.2lf\n", account->balance);
}

// Function to display the date of the account's creation
void display_creation_date(struct bank_account* account) {
  printf("Account created on: %s\n", ctime(&account->date_opened));
}

// Function to display the account holder's name
void display_name(struct bank_account* account) {
  printf("Account holder's name: %s\n", account->name);
}

// Function to display the account number
void display_account_number(struct bank_account* account) {
  printf("Account number: %s\n", account->account_number);
}

// Main function
int main() {
  // Create a new bank account
  struct bank_account* account = create_account("1234567890", "John Doe");

  // Deposit $100 into the account
  deposit_money(account, 100.0);

  // Withdraw $50 from the account
  withdraw_money(account, 50.0);

  // Display the balance of the account
  display_balance(account);

  // Display the date of the account's creation
  display_creation_date(account);

  // Display the account holder's name
  display_name(account);

  // Display the account number
  display_account_number(account);

  // Free the memory allocated to the account
  free(account);

  return 0;
}