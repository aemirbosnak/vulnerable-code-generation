//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int account_number;
  double balance;
} account_t;

account_t *accounts;
int num_accounts = 0;

void create_account(char *name, int account_number, double balance) {
  accounts = realloc(accounts, (num_accounts + 1) * sizeof(account_t));
  accounts[num_accounts].name = name;
  accounts[num_accounts].account_number = account_number;
  accounts[num_accounts].balance = balance;
  num_accounts++;
}

account_t *find_account(int account_number) {
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      return &accounts[i];
    }
  }
  return NULL;
}

void deposit(int account_number, double amount) {
  account_t *account = find_account(account_number);
  if (account == NULL) {
    printf("Account not found.\n");
    return;
  }
  account->balance += amount;
}

void withdraw(int account_number, double amount) {
  account_t *account = find_account(account_number);
  if (account == NULL) {
    printf("Account not found.\n");
    return;
  }
  if (account->balance < amount) {
    printf("Insufficient funds.\n");
    return;
  }
  account->balance -= amount;
}

void transfer(int from_account_number, int to_account_number, double amount) {
  account_t *from_account = find_account(from_account_number);
  if (from_account == NULL) {
    printf("From account not found.\n");
    return;
  }
  if (from_account->balance < amount) {
    printf("Insufficient funds.\n");
    return;
  }
  account_t *to_account = find_account(to_account_number);
  if (to_account == NULL) {
    printf("To account not found.\n");
    return;
  }
  from_account->balance -= amount;
  to_account->balance += amount;
}

void print_accounts() {
  for (int i = 0; i < num_accounts; i++) {
    printf("%s %d %f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
  }
}

int main() {
  create_account("Alice", 123456, 1000.0);
  create_account("Bob", 654321, 2000.0);
  deposit(123456, 500.0);
  withdraw(654321, 300.0);
  transfer(123456, 654321, 200.0);
  print_accounts();
  return 0;
}