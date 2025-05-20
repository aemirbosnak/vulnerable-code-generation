//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  double balance;
} account;

int main() {
  // Welcome the user
  printf("Welcome to your personal finance planner, where we'll help you keep track of your hard-earned dough!\n");

  // Create an array of accounts
  account accounts[10];

  // Get the number of accounts the user has
  int num_accounts;
  printf("How many accounts do you have? ");
  scanf("%d", &num_accounts);

  // Get the details of each account
  for (int i = 0; i < num_accounts; i++) {
    printf("Account %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", accounts[i].name);
    printf("Balance: ");
    scanf("%lf", &accounts[i].balance);
  }

  // Calculate the total balance
  double total_balance = 0;
  for (int i = 0; i < num_accounts; i++) {
    total_balance += accounts[i].balance;
  }

  // Print the total balance
  printf("Your total balance is: %lf\n", total_balance);

  // Give the user some financial advice
  if (total_balance > 1000000) {
    printf("Congratulations! You're a millionaire!\n");
  } else if (total_balance > 100000) {
    printf("You're on your way to becoming a millionaire!\n");
  } else if (total_balance > 10000) {
    printf("Keep saving and you'll be a millionaire in no time!\n");
  } else {
    printf("Don't worry, you're not alone. Most people don't have a million dollars.\n");
  }

  // Thank the user
  printf("Thanks for using our personal finance planner! We hope you found it helpful.\n");

  return 0;
}