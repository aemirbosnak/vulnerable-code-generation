//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: puzzling
// Banking Record System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Structure for storing bank account information
struct BankAccount {
  char name[50];
  int account_no;
  float balance;
};

// Function to add a new bank account
void addAccount(struct BankAccount* accounts, int* num_accounts) {
  // Prompt user for account information
  printf("Enter account name: ");
  scanf("%s", accounts[*num_accounts].name);
  printf("Enter account number: ");
  scanf("%d", &accounts[*num_accounts].account_no);
  printf("Enter initial balance: ");
  scanf("%f", &accounts[*num_accounts].balance);
  // Increment number of accounts
  *num_accounts += 1;
}

// Function to display all bank accounts
void displayAccounts(struct BankAccount* accounts, int num_accounts) {
  // Print header
  printf("%-20s%-15s%-15s\n", "Name", "Account Number", "Balance");
  // Print each account
  for (int i = 0; i < num_accounts; i++) {
    printf("%-20s%-15d%-15.2f\n", accounts[i].name, accounts[i].account_no, accounts[i].balance);
  }
}

// Function to deposit money into an account
void deposit(struct BankAccount* accounts, int num_accounts) {
  // Prompt user for account number and amount to deposit
  int account_no;
  float amount;
  printf("Enter account number: ");
  scanf("%d", &account_no);
  printf("Enter amount to deposit: ");
  scanf("%f", &amount);
  // Find the account with the given number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_no == account_no) {
      // Add the amount to the account balance
      accounts[i].balance += amount;
      break;
    }
  }
}

// Function to withdraw money from an account
void withdraw(struct BankAccount* accounts, int num_accounts) {
  // Prompt user for account number and amount to withdraw
  int account_no;
  float amount;
  printf("Enter account number: ");
  scanf("%d", &account_no);
  printf("Enter amount to withdraw: ");
  scanf("%f", &amount);
  // Find the account with the given number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_no == account_no) {
      // Check if the account has enough balance
      if (accounts[i].balance < amount) {
        printf("Insufficient balance\n");
        return;
      }
      // Subtract the amount from the account balance
      accounts[i].balance -= amount;
      break;
    }
  }
}

// Function to transfer money between accounts
void transfer(struct BankAccount* accounts, int num_accounts) {
  // Prompt user for source and destination account numbers and amount to transfer
  int src_account_no, dest_account_no;
  float amount;
  printf("Enter source account number: ");
  scanf("%d", &src_account_no);
  printf("Enter destination account number: ");
  scanf("%d", &dest_account_no);
  printf("Enter amount to transfer: ");
  scanf("%f", &amount);
  // Find the source account with the given number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_no == src_account_no) {
      // Check if the source account has enough balance
      if (accounts[i].balance < amount) {
        printf("Insufficient balance\n");
        return;
      }
      // Subtract the amount from the source account balance
      accounts[i].balance -= amount;
      break;
    }
  }
  // Find the destination account with the given number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_no == dest_account_no) {
      // Add the amount to the destination account balance
      accounts[i].balance += amount;
      break;
    }
  }
}

int main() {
  // Initialize the bank account array
  struct BankAccount accounts[100];
  int num_accounts = 0;
  // Add a new account
  addAccount(accounts, &num_accounts);
  // Display all accounts
  displayAccounts(accounts, num_accounts);
  // Deposit money into an account
  deposit(accounts, num_accounts);
  // Withdraw money from an account
  withdraw(accounts, num_accounts);
  // Transfer money between accounts
  transfer(accounts, num_accounts);
  // Display all accounts again
  displayAccounts(accounts, num_accounts);
  return 0;
}