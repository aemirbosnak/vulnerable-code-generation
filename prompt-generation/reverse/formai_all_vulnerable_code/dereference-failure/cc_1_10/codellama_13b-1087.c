//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for bank account
struct account {
  char name[30];
  char email[50];
  float balance;
};

// Function to create a new account
struct account* create_account(char* name, char* email, float balance) {
  struct account* new_account = (struct account*)malloc(sizeof(struct account));
  strcpy(new_account->name, name);
  strcpy(new_account->email, email);
  new_account->balance = balance;
  return new_account;
}

// Function to deposit money into an account
void deposit(struct account* account, float amount) {
  account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct account* account, float amount) {
  if (account->balance < amount) {
    printf("Insufficient funds.\n");
    return;
  }
  account->balance -= amount;
}

// Function to transfer money between accounts
void transfer(struct account* source, struct account* destination, float amount) {
  if (source->balance < amount) {
    printf("Insufficient funds.\n");
    return;
  }
  source->balance -= amount;
  destination->balance += amount;
}

// Function to print the balance of an account
void print_balance(struct account* account) {
  printf("Balance: $%.2f\n", account->balance);
}

int main() {
  // Create two accounts
  struct account* account1 = create_account("John", "john@example.com", 500.00);
  struct account* account2 = create_account("Jane", "jane@example.com", 1000.00);

  // Deposit money into account1
  deposit(account1, 200.00);

  // Withdraw money from account1
  withdraw(account1, 100.00);

  // Transfer money between accounts
  transfer(account1, account2, 500.00);

  // Print the balance of account1
  print_balance(account1);

  // Print the balance of account2
  print_balance(account2);

  return 0;
}