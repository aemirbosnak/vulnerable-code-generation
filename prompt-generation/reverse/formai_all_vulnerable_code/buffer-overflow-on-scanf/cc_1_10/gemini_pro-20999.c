//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int account_number;
  double balance;
} account;

int main() {
  // Initialize the bank with a few accounts
  account bank[] = {
    {"Alice", 12345, 1000.00},
    {"Bob", 67890, 2000.00},
    {"Carol", 11111, 3000.00}
  };
  int num_accounts = sizeof(bank) / sizeof(account);

  // Get the user's input
  char name[100];
  printf("Enter your name: ");
  scanf("%s", name);

  int account_number;
  printf("Enter your account number: ");
  scanf("%d", &account_number);

  // Find the account
  int account_index = -1;
  for (int i = 0; i < num_accounts; i++) {
    if (strcmp(bank[i].name, name) == 0 && bank[i].account_number == account_number) {
      account_index = i;
      break;
    }
  }

  // If the account was not found, print an error message
  if (account_index == -1) {
    printf("Account not found.\n");
    return 1;
  }

  // Get the user's input
  char transaction_type;
  printf("Enter transaction type (d for deposit, w for withdrawal): ");
  scanf(" %c", &transaction_type);

  double amount;
  printf("Enter amount: ");
  scanf("%lf", &amount);

  // Perform the transaction
  switch (transaction_type) {
    case 'd':
      bank[account_index].balance += amount;
      break;
    case 'w':
      if (amount <= bank[account_index].balance) {
        bank[account_index].balance -= amount;
      } else {
        printf("Insufficient funds.\n");
      }
      break;
    default:
      printf("Invalid transaction type.\n");
      break;
  }

  // Print the account balance
  printf("Your new balance is: %.2f\n", bank[account_index].balance);

  return 0;
}