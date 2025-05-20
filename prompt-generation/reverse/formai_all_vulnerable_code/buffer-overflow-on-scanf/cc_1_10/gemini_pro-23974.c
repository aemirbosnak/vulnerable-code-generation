//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct account {
  char name[50];
  int account_number;
  double balance;
};

void create_account(struct account *accounts, int *num_accounts) {
  printf("Enter your name: ");
  scanf(" %s", accounts[*num_accounts].name);
  printf("Enter your account number: ");
  scanf(" %d", &accounts[*num_accounts].account_number);
  printf("Enter your initial deposit: ");
  scanf(" %lf", &accounts[*num_accounts].balance);
  (*num_accounts)++;
}

void deposit(struct account *accounts, int num_accounts) {
  int account_number;
  double amount;
  printf("Enter your account number: ");
  scanf(" %d", &account_number);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Enter the amount to deposit: ");
      scanf(" %lf", &amount);
      accounts[i].balance += amount;
      printf("Deposit successful! Your new balance is: %.2lf\n", accounts[i].balance);
      return;
    }
  }
  printf("Account not found.\n");
}

void withdraw(struct account *accounts, int num_accounts) {
  int account_number;
  double amount;
  printf("Enter your account number: ");
  scanf(" %d", &account_number);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Enter the amount to withdraw: ");
      scanf(" %lf", &amount);
      if (amount > accounts[i].balance) {
        printf("Insufficient funds.\n");
        return;
      }
      accounts[i].balance -= amount;
      printf("Withdrawal successful! Your new balance is: %.2lf\n", accounts[i].balance);
      return;
    }
  }
  printf("Account not found.\n");
}

void display_accounts(struct account *accounts, int num_accounts) {
  printf("Here are the account details:\n");
  for (int i = 0; i < num_accounts; i++) {
    printf("%s - %d - %.2lf\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
  }
}

int main() {
  int num_accounts = 0;
  struct account accounts[100];  // Assuming a maximum of 100 accounts
  int choice;

  while (1) {
    printf("\n1. Create an account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Display account details\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf(" %d", &choice);

    switch (choice) {
      case 1:
        create_account(accounts, &num_accounts);
        break;
      case 2:
        deposit(accounts, num_accounts);
        break;
      case 3:
        withdraw(accounts, num_accounts);
        break;
      case 4:
        display_accounts(accounts, num_accounts);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}