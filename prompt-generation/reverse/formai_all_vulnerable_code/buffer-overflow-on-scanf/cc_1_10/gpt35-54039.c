//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_NAME_LENGTH 50

struct Account {
  int account_number;
  char name[MAX_NAME_LENGTH];
  float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account(int account_number, char *name, float balance) {
  if (num_accounts >= MAX_ACCOUNTS) {
    printf("Error: Maximum number of accounts reached!\n");
    return;
  }
  accounts[num_accounts].account_number = account_number;
  strcpy(accounts[num_accounts].name, name);
  accounts[num_accounts].balance = balance;
  num_accounts++;
  printf("Account created successfully\n");
}

void display_account(int account_number) {
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Account Number: %d | Name: %s | Balance: %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
      return;
    }
  }
  printf("Account not found!\n");
}

void deposit(int account_number, float amount) {
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      accounts[i].balance += amount;
      printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
      return;
    }
  }
  printf("Account not found!\n");
}

void withdraw(int account_number, float amount) {
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      if (accounts[i].balance < amount) {
        printf("Error: Insufficient balance!\n");
        return;
      }
      accounts[i].balance -= amount;
      printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
      return;
    }
  }
  printf("Account not found!\n");
}

int main() {
  int choice = 0, account_number;
  char name[MAX_NAME_LENGTH];
  float balance, amount;

  do {
    printf("Welcome to the C Banking Record System!\n");
    printf("Choose an action:\n");
    printf("1. Create Account\n");
    printf("2. Display Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter balance: ");
        scanf("%f", &balance);
        add_account(account_number, name, balance);
        break;
      case 2:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        display_account(account_number);
        break;
      case 3:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        deposit(account_number, amount);
        break;
      case 4:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        withdraw(account_number, amount);
        break;
      case 5:
        printf("Thank you for using the C Banking Record System!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 5);

  return 0;
}