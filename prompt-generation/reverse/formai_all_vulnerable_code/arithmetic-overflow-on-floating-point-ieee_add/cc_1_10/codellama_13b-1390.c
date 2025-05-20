//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: configurable
/*
 * Banking Record System
 *
 * This program demonstrates a basic banking record system in C.
 * It allows users to create, view, and edit bank accounts.
 *
 * Usage:
 *  1. Compile the program with a C compiler.
 *  2. Run the program with the desired input.
 *
 * Example:
 *  $ ./banking_record_system
 *  Welcome to the Banking Record System!
 *  Enter a command:
 *  1. Create a new account
 *  2. View all accounts
 *  3. Edit an account
 *  4. Delete an account
 *  5. Quit
 *  Enter a command: 1
 *  Enter the account name: John Doe
 *  Enter the account balance: 1000
 *  Account created successfully!
 *  Enter a command: 2
 *  Account Name: John Doe
 *  Account Balance: 1000
 *  Enter a command: 3
 *  Enter the account name: John Doe
 *  Enter the amount to add: 500
 *  Account updated successfully!
 *  Enter a command: 4
 *  Enter the account name: John Doe
 *  Enter the amount to delete: 200
 *  Account updated successfully!
 *  Enter a command: 5
 *  Quitting the Banking Record System...
 *  Goodbye!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store bank account information
typedef struct {
  char name[256];
  float balance;
} Account;

// Function to create a new bank account
void create_account(Account *account, char *name, float balance) {
  strcpy(account->name, name);
  account->balance = balance;
}

// Function to view all bank accounts
void view_accounts(Account *accounts, int num_accounts) {
  for (int i = 0; i < num_accounts; i++) {
    printf("Account Name: %s\n", accounts[i].name);
    printf("Account Balance: %f\n", accounts[i].balance);
  }
}

// Function to edit a bank account
void edit_account(Account *account, float amount) {
  account->balance += amount;
}

// Function to delete a bank account
void delete_account(Account *account) {
  strcpy(account->name, "");
  account->balance = 0.0;
}

int main() {
  // Initialize an array of bank accounts
  Account accounts[10];
  int num_accounts = 0;

  // Prompt the user to enter a command
  printf("Welcome to the Banking Record System!\n");
  printf("Enter a command: \n");
  printf("1. Create a new account\n");
  printf("2. View all accounts\n");
  printf("3. Edit an account\n");
  printf("4. Delete an account\n");
  printf("5. Quit\n");
  int command;
  scanf("%d", &command);

  // Process the user's command
  switch (command) {
    case 1: {
      // Create a new bank account
      char name[256];
      float balance;
      printf("Enter the account name: ");
      scanf("%s", name);
      printf("Enter the account balance: ");
      scanf("%f", &balance);
      create_account(&accounts[num_accounts], name, balance);
      num_accounts++;
      printf("Account created successfully!\n");
      break;
    }
    case 2: {
      // View all bank accounts
      view_accounts(accounts, num_accounts);
      break;
    }
    case 3: {
      // Edit a bank account
      char name[256];
      float amount;
      printf("Enter the account name: ");
      scanf("%s", name);
      printf("Enter the amount to add: ");
      scanf("%f", &amount);
      edit_account(&accounts[num_accounts], amount);
      printf("Account updated successfully!\n");
      break;
    }
    case 4: {
      // Delete a bank account
      char name[256];
      printf("Enter the account name: ");
      scanf("%s", name);
      delete_account(&accounts[num_accounts]);
      printf("Account deleted successfully!\n");
      break;
    }
    case 5: {
      // Quit the program
      printf("Quitting the Banking Record System...\n");
      printf("Goodbye!\n");
      return 0;
    }
    default: {
      printf("Invalid command!\n");
      break;
    }
  }

  return 0;
}