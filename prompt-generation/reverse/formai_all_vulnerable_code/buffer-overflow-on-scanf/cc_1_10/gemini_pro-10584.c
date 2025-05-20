//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  int account_number;
  char account_holder_name[50];
  double balance;
};

struct account accounts[100];
int num_accounts = 0;

void create_account() {
  struct account account;

  printf("Enter account number: ");
  scanf("%d", &account.account_number);

  printf("Enter account holder name: ");
  scanf("%s", account.account_holder_name);

  printf("Enter initial balance: ");
  scanf("%lf", &account.balance);

  accounts[num_accounts++] = account;
}

void deposit_money() {
  int account_number;
  double amount;

  printf("Enter account number: ");
  scanf("%d", &account_number);

  int index = find_account_index(account_number);
  if (index == -1) {
    printf("Account not found.\n");
    return;
  }

  printf("Enter amount to deposit: ");
  scanf("%lf", &amount);

  accounts[index].balance += amount;

  printf("Amount deposited successfully.\n");
}

void withdraw_money() {
  int account_number;
  double amount;

  printf("Enter account number: ");
  scanf("%d", &account_number);

  int index = find_account_index(account_number);
  if (index == -1) {
    printf("Account not found.\n");
    return;
  }

  printf("Enter amount to withdraw: ");
  scanf("%lf", &amount);

  if (amount > accounts[index].balance) {
    printf("Insufficient funds.\n");
    return;
  }

  accounts[index].balance -= amount;

  printf("Amount withdrawn successfully.\n");
}

void transfer_money() {
  int from_account_number;
  int to_account_number;
  double amount;

  printf("Enter account number to transfer from: ");
  scanf("%d", &from_account_number);

  int from_index = find_account_index(from_account_number);
  if (from_index == -1) {
    printf("Account not found.\n");
    return;
  }

  printf("Enter account number to transfer to: ");
  scanf("%d", &to_account_number);

  int to_index = find_account_index(to_account_number);
  if (to_index == -1) {
    printf("Account not found.\n");
    return;
  }

  printf("Enter amount to transfer: ");
  scanf("%lf", &amount);

  if (amount > accounts[from_index].balance) {
    printf("Insufficient funds.\n");
    return;
  }

  accounts[from_index].balance -= amount;
  accounts[to_index].balance += amount;

  printf("Amount transferred successfully.\n");
}

void print_balance() {
  int account_number;

  printf("Enter account number: ");
  scanf("%d", &account_number);

  int index = find_account_index(account_number);
  if (index == -1) {
    printf("Account not found.\n");
    return;
  }

  printf("Account balance: %.2lf\n", accounts[index].balance);
}

int find_account_index(int account_number) {
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      return i;
    }
  }

  return -1;
}

int main() {
  int choice;

  while (1) {
    printf("1. Create account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Transfer money\n");
    printf("5. Print balance\n");
    printf("6. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        create_account();
        break;
      case 2:
        deposit_money();
        break;
      case 3:
        withdraw_money();
        break;
      case 4:
        transfer_money();
        break;
      case 5:
        print_balance();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}