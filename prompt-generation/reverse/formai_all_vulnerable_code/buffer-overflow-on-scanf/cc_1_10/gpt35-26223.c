//FormAI DATASET v1.0 Category: Banking Record System ; Style: thoughtful
// C Banking Record System Example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACC 50 // Define maximum number of bank accounts

// Define the structure for the bank account
struct BankAccount {
  int accountNumber;
  char holderName[20];
  float balance;
};

// Declare and initialize the bank accounts array
struct BankAccount bankAccounts[MAX_ACC] = {{1, "Alice", 5000.0}, {2, "Bob", 10000.0}, {3, "Charlie", 15000.0}};
int numAccounts = 3; // Initialize the number of accounts to 3

// Function to add a new account
void addAccount(int accountNumber, char holderName[], float balance) {
  if (numAccounts == MAX_ACC) {
    printf("Maximum number of bank accounts reached.\n");
    return;
  }
  for (int i = 0; i < numAccounts; i++) {
    if (bankAccounts[i].accountNumber == accountNumber) {
      printf("Account number already exists.\n");
      return;
    }
  }
  struct BankAccount newAccount = {accountNumber, holderName, balance};
  bankAccounts[numAccounts] = newAccount;
  numAccounts++;
  printf("Account added successfully.\n");
}

// Function to print all accounts
void printAccounts() {
  printf("Account Number\tHolder Name\tBalance\n");
  for (int i = 0; i < numAccounts; i++) {
    printf("%d\t\t%s\t\t%.2f\n", bankAccounts[i].accountNumber, bankAccounts[i].holderName, bankAccounts[i].balance);
  }
}

// Function to find an account by account number
struct BankAccount* findAccount(int accountNumber) {
  for (int i = 0; i < numAccounts; i++) {
    if (bankAccounts[i].accountNumber == accountNumber) {
      return &bankAccounts[i];
    }
  }
  return NULL;
}

// Function to deposit money to an account
void deposit(int accountNumber, float amount) {
  struct BankAccount* account = findAccount(accountNumber);
  if (account != NULL) {
    account->balance += amount;
    printf("%.2f deposited to account number %d.\n", amount, accountNumber);
  } else {
    printf("Account not found.\n");
  }
}

// Function to withdraw money from an account
void withdraw(int accountNumber, float amount) {
  struct BankAccount* account = findAccount(accountNumber);
  if (account != NULL) {
    if (account->balance >= amount) {
      account->balance -= amount;
      printf("%.2f withdrawn from account number %d.\n", amount, accountNumber);
    } else {
      printf("Insufficient balance.\n");
    }
  } else {
    printf("Account not found.\n");
  }
}

// Main function to run the banking record system
int main() {
  int choice, accountNumber;
  float amount;
  char holderName[20];

  printf("Welcome to the Banking Record System.\n");

  while (1) {
    printf("\n\n");
    printf("1. Add an Account\n");
    printf("2. Print all Accounts\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);
        printf("Enter holder name: ");
        scanf("%s", holderName);
        printf("Enter balance: ");
        scanf("%f", &amount);
        addAccount(accountNumber, holderName, amount);
        break;
      case 2:
        printAccounts();
        break;
      case 3:
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        deposit(accountNumber, amount);
        break;
      case 4:
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        withdraw(accountNumber, amount);
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }

  return 0;
}