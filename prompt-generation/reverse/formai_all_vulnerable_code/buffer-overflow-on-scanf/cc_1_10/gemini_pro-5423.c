//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
enum transaction_type {
  INCOME,
  EXPENSE
};

// Define the transaction struct
struct transaction {
  char description[50];
  double amount;
  enum transaction_type type;
};

// Create an array of transactions
struct transaction transactions[MAX_TRANSACTIONS];

// Get the user's input
void get_user_input() {
  int num_transactions;
  printf("How many transactions do you have? ");
  scanf("%d", &num_transactions);

  for (int i = 0; i < num_transactions; i++) {
    printf("Enter the description of transaction %d: ", i + 1);
    scanf("%s", transactions[i].description);

    printf("Enter the amount of transaction %d: ", i + 1);
    scanf("%lf", &transactions[i].amount);

    printf("Enter the type of transaction %d (1 for income, 2 for expense): ", i + 1);
    scanf("%d", &transactions[i].type);
  }
}

// Calculate the total income and expenses
void calculate_totals() {
  double total_income = 0;
  double total_expenses = 0;

  for (int i = 0; i < MAX_TRANSACTIONS; i++) {
    if (transactions[i].type == INCOME) {
      total_income += transactions[i].amount;
    } else if (transactions[i].type == EXPENSE) {
      total_expenses += transactions[i].amount;
    }
  }

  printf("Total income: $%.2f\n", total_income);
  printf("Total expenses: $%.2f\n", total_expenses);
}

// Print the transactions
void print_transactions() {
  printf("Transactions:\n");
  for (int i = 0; i < MAX_TRANSACTIONS; i++) {
    printf("%s $%.2f %s\n", transactions[i].description, transactions[i].amount, transactions[i].type == INCOME ? "Income" : "Expense");
  }
}

// Main function
int main() {
  get_user_input();
  calculate_totals();
  print_transactions();

  return 0;
}