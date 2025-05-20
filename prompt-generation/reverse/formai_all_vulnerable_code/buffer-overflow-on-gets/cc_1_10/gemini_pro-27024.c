//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions.
#define MAX_TRANSACTIONS 100

// Define the transaction types.
enum TransactionType {
  INCOME,
  EXPENSE
};

// Define the transaction struct.
struct Transaction {
  char* description;
  double amount;
  enum TransactionType type;
};

// Create an array of transactions.
struct Transaction transactions[MAX_TRANSACTIONS];

// Initialize the number of transactions to 0.
int num_transactions = 0;

// Get the user's input.
void get_input() {
  char input[100];
  double amount;
  enum TransactionType type;

  while (1) {
    printf("Enter a transaction (description, amount, type): ");
    gets(input);

    // Parse the input.
    char* description = strtok(input, ",");
    amount = atof(strtok(NULL, ","));
    type = (enum TransactionType)atoi(strtok(NULL, ","));

    // Create a new transaction.
    struct Transaction transaction;
    transaction.description = strdup(description);
    transaction.amount = amount;
    transaction.type = type;

    // Add the transaction to the array.
    transactions[num_transactions++] = transaction;

    // Check if the user is finished entering transactions.
    if (strcmp(description, "quit") == 0) {
      break;
    }
  }
}

// Print the transactions.
void print_transactions() {
  for (int i = 0; i < num_transactions; i++) {
    printf("%s, %f, %d\n", transactions[i].description, transactions[i].amount, transactions[i].type);
  }
}

// Calculate the total income and expenses.
void calculate_totals() {
  double total_income = 0;
  double total_expenses = 0;

  for (int i = 0; i < num_transactions; i++) {
    if (transactions[i].type == INCOME) {
      total_income += transactions[i].amount;
    } else {
      total_expenses += transactions[i].amount;
    }
  }

  printf("Total income: %f\n", total_income);
  printf("Total expenses: %f\n", total_expenses);
}

// Main function.
int main() {
  // Get the user's input.
  get_input();

  // Print the transactions.
  print_transactions();

  // Calculate the total income and expenses.
  calculate_totals();

  return 0;
}