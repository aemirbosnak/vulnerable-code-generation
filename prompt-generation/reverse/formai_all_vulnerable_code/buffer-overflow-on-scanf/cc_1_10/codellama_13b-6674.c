//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: shocked
// Banking Record System in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for storing banking information
typedef struct {
  char name[50];
  char account_number[10];
  int balance;
} BankInfo;

// Function for adding a new account
void addAccount(BankInfo *accounts, int *numAccounts) {
  printf("Enter name: ");
  scanf("%s", &accounts[*numAccounts].name);
  printf("Enter account number: ");
  scanf("%s", &accounts[*numAccounts].account_number);
  printf("Enter initial balance: ");
  scanf("%d", &accounts[*numAccounts].balance);
  *numAccounts = *numAccounts + 1;
}

// Function for displaying all accounts
void displayAccounts(BankInfo *accounts, int numAccounts) {
  int i;
  printf("Name\t\tAccount Number\t\tBalance\n");
  for (i = 0; i < numAccounts; i++) {
    printf("%s\t\t%s\t\t%d\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
  }
}

// Function for withdrawing from an account
void withdraw(BankInfo *accounts, int numAccounts) {
  int i, accountNumber, amount;
  printf("Enter account number: ");
  scanf("%d", &accountNumber);
  printf("Enter amount to withdraw: ");
  scanf("%d", &amount);
  for (i = 0; i < numAccounts; i++) {
    if (accounts[i].account_number == accountNumber) {
      accounts[i].balance = accounts[i].balance - amount;
      printf("Successfully withdrew %d from account %d\n", amount, accountNumber);
      return;
    }
  }
  printf("Account not found\n");
}

// Function for depositing into an account
void deposit(BankInfo *accounts, int numAccounts) {
  int i, accountNumber, amount;
  printf("Enter account number: ");
  scanf("%d", &accountNumber);
  printf("Enter amount to deposit: ");
  scanf("%d", &amount);
  for (i = 0; i < numAccounts; i++) {
    if (accounts[i].account_number == accountNumber) {
      accounts[i].balance = accounts[i].balance + amount;
      printf("Successfully deposited %d into account %d\n", amount, accountNumber);
      return;
    }
  }
  printf("Account not found\n");
}

int main() {
  BankInfo accounts[100];
  int numAccounts = 0;
  int choice;
  while (1) {
    printf("Menu:\n1. Add Account\n2. Display Accounts\n3. Withdraw\n4. Deposit\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addAccount(&accounts, &numAccounts);
        break;
      case 2:
        displayAccounts(accounts, numAccounts);
        break;
      case 3:
        withdraw(accounts, numAccounts);
        break;
      case 4:
        deposit(accounts, numAccounts);
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}