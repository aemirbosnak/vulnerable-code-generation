//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *name;
  char *account_number;
  double balance;
} account_t;

int main(int argc, char **argv)
{
  // Create an array of accounts.
  account_t accounts[] = {
    { .name = "Alice", .account_number = "1234567890", .balance = 1000.0 },
    { .name = "Bob", .account_number = "0987654321", .balance = 2000.0 },
    { .name = "Carol", .account_number = "1122334455", .balance = 3000.0 },
  };

  // Get the account number from the user.
  char *account_number = malloc(20);
  printf("Enter your account number: ");
  scanf("%s", account_number);

  // Find the account with the matching account number.
  account_t *account = NULL;
  for (int i = 0; i < sizeof(accounts) / sizeof(account_t); i++) {
    if (strcmp(accounts[i].account_number, account_number) == 0) {
      account = &accounts[i];
      break;
    }
  }

  // If the account was not found, print an error message.
  if (account == NULL) {
    printf("Account not found.\n");
    return 1;
  }

  // Get the transaction type from the user.
  char *transaction_type = malloc(20);
  printf("Enter the transaction type (deposit, withdraw, or balance): ");
  scanf("%s", transaction_type);

  // Perform the transaction.
  if (strcmp(transaction_type, "deposit") == 0) {
    // Get the amount to deposit.
    double amount;
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    // Deposit the amount.
    account->balance += amount;
  } else if (strcmp(transaction_type, "withdraw") == 0) {
    // Get the amount to withdraw.
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    // Withdraw the amount.
    account->balance -= amount;
  } else if (strcmp(transaction_type, "balance") == 0) {
    // Print the balance.
    printf("Your balance is: %lf\n", account->balance);
  } else {
    printf("Invalid transaction type.\n");
    return 1;
  }

  // Free the memory that was allocated.
  free(account_number);
  free(transaction_type);

  return 0;
}