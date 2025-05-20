//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: funny
/*
 * Banking Record System in a Funny Style
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 50
#define MAX_ACCOUNT 10

typedef struct {
  char name[MAX_NAME];
  int account_num;
  float balance;
} Account;

void add_account(Account *acc) {
  printf("Enter your name: ");
  scanf("%s", acc->name);
  printf("Enter your account number: ");
  scanf("%d", &acc->account_num);
  printf("Enter your initial balance: ");
  scanf("%f", &acc->balance);
}

void show_account(Account *acc) {
  printf("Name: %s\n", acc->name);
  printf("Account number: %d\n", acc->account_num);
  printf("Balance: %f\n", acc->balance);
}

void deposit(Account *acc, float amount) {
  acc->balance += amount;
}

void withdraw(Account *acc, float amount) {
  if (acc->balance >= amount) {
    acc->balance -= amount;
  } else {
    printf("Insufficient balance\n");
  }
}

void transfer(Account *acc1, Account *acc2, float amount) {
  if (acc1->balance >= amount) {
    acc1->balance -= amount;
    acc2->balance += amount;
  } else {
    printf("Insufficient balance\n");
  }
}

int main() {
  Account accounts[MAX_ACCOUNT];
  int i, n;

  printf("Enter the number of accounts: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    add_account(&accounts[i]);
  }

  show_account(&accounts[0]);
  deposit(&accounts[0], 100.00);
  withdraw(&accounts[0], 50.00);
  transfer(&accounts[0], &accounts[1], 25.00);

  return 0;
}