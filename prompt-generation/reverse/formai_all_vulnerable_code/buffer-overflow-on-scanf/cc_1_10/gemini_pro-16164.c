//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int account_number;
  double balance;
} Account;

int main() {
  // Initialize the bank database with some sample accounts
  Account accounts[] = {
    {"Alice", 123456789, 1000.00},
    {"Bob", 987654321, 2000.00},
    {"Carol", 112233445, 3000.00}
  };
  int num_accounts = sizeof(accounts) / sizeof(Account);

  // Print a welcome message
  printf("Welcome to the Happy Bank!\n");

  // Get the account number from the user
  int account_number;
  printf("Please enter your account number: ");
  scanf("%d", &account_number);

  // Find the account in the database
  Account *account = NULL;
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      account = &accounts[i];
      break;
    }
  }

  // If the account was not found, print an error message
  if (account == NULL) {
    printf("Invalid account number.\n");
    return 1;
  }

  // Print the account information
  printf("Account holder: %s\n", account->name);
  printf("Account number: %d\n", account->account_number);
  printf("Balance: $%.2f\n", account->balance);

  // Get the transaction type from the user
  int transaction_type;
  printf("Please enter the transaction type (1 for deposit, 2 for withdrawal): ");
  scanf("%d", &transaction_type);

  // Process the transaction
  double amount;
  switch (transaction_type) {
    case 1:
      printf("Please enter the deposit amount: ");
      scanf("%lf", &amount);
      account->balance += amount;
      printf("Deposit successful.\n");
      break;
    case 2:
      printf("Please enter the withdrawal amount: ");
      scanf("%lf", &amount);
      if (amount > account->balance) {
        printf("Insufficient funds.\n");
      } else {
        account->balance -= amount;
        printf("Withdrawal successful.\n");
      }
      break;
    default:
      printf("Invalid transaction type.\n");
  }

  // Print the updated account information
  printf("Account holder: %s\n", account->name);
  printf("Account number: %d\n", account->account_number);
  printf("Balance: $%.2f\n", account->balance);

  // Print a goodbye message
  printf("Thank you for banking with us! Have a happy day!\n");

  return 0;
}