//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction structure
typedef struct {
  char description[100];
  double amount;
  int type; // 0 = income, 1 = expense
} transaction;

// Define the function to add a transaction
void add_transaction(transaction *transactions, int *num_transactions, char *description, double amount, int type) {
  // Check if the number of transactions has reached the maximum
  if (*num_transactions >= MAX_TRANSACTIONS) {
    printf("Error: Maximum number of transactions reached.\n");
    return;
  }

  // Add the transaction to the array
  strcpy(transactions[*num_transactions].description, description);
  transactions[*num_transactions].amount = amount;
  transactions[*num_transactions].type = type;

  // Increment the number of transactions
  (*num_transactions)++;
}

// Define the function to print the transactions
void print_transactions(transaction *transactions, int num_transactions) {
  // Print the header
  printf("Transactions:\n");
  printf("Description\tAmount\tType\n");

  // Print each transaction
  for (int i = 0; i < num_transactions; i++) {
    printf("%s\t%.2f\t%s\n", transactions[i].description, transactions[i].amount, transactions[i].type == 0 ? "Income" : "Expense");
  }

  // Print the footer
  printf("\n");
}

// Define the function to calculate the total income and expenses
void calculate_totals(transaction *transactions, int num_transactions, double *total_income, double *total_expenses) {
  // Initialize the totals
  *total_income = 0;
  *total_expenses = 0;

  // Calculate the totals
  for (int i = 0; i < num_transactions; i++) {
    if (transactions[i].type == 0) {
      *total_income += transactions[i].amount;
    } else {
      *total_expenses += transactions[i].amount;
    }
  }
}

// Define the function to print the totals
void print_totals(double total_income, double total_expenses) {
  // Print the totals
  printf("Totals:\n");
  printf("Income:\t%.2f\n", total_income);
  printf("Expenses:\t%.2f\n", total_expenses);

  // Print the net income
  printf("Net Income:\t%.2f\n", total_income - total_expenses);

  // Print the footer
  printf("\n");
}

// Define the function to get user input
void get_user_input(transaction *transactions, int *num_transactions) {
  // Get the number of transactions
  printf("Enter the number of transactions: ");
  scanf("%d", num_transactions);

  // Get the transactions
  for (int i = 0; i < *num_transactions; i++) {
    // Get the description
    printf("Enter the description for transaction %d: ", i + 1);
    scanf(" %[^\n]s", transactions[i].description);

    // Get the amount
    printf("Enter the amount for transaction %d: ", i + 1);
    scanf("%lf", &transactions[i].amount);

    // Get the type
    printf("Enter the type for transaction %d (0 = income, 1 = expense): ", i + 1);
    scanf("%d", &transactions[i].type);
  }
}

// Define the main function
int main() {
  // Declare the variables
  transaction transactions[MAX_TRANSACTIONS];
  int num_transactions = 0;
  double total_income, total_expenses;

  // Get user input
  get_user_input(transactions, &num_transactions);

  // Print the transactions
  print_transactions(transactions, num_transactions);

  // Calculate the totals
  calculate_totals(transactions, num_transactions, &total_income, &total_expenses);

  // Print the totals
  print_totals(total_income, total_expenses);

  return 0;
}