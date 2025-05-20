//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
// Personal Finance Planner

#include <stdio.h>
#include <stdlib.h>

// Define the struct for each month
struct month {
  int year;
  int month;
  float income;
  float expenses;
  float savings;
};

// Define the struct for each transaction
struct transaction {
  char type; // 'I' for income, 'E' for expense
  float amount;
  char* description;
  struct month* month;
};

// Define the struct for the personal finance planner
struct planner {
  struct month months[12];
  struct transaction* transactions;
  int num_transactions;
};

// Initialize the personal finance planner
void init_planner(struct planner* planner) {
  // Initialize the months
  for (int i = 0; i < 12; i++) {
    planner->months[i].year = 0;
    planner->months[i].month = 0;
    planner->months[i].income = 0;
    planner->months[i].expenses = 0;
    planner->months[i].savings = 0;
  }
  // Initialize the transactions
  planner->transactions = NULL;
  planner->num_transactions = 0;
}

// Add a transaction to the planner
void add_transaction(struct planner* planner, char type, float amount, char* description, struct month* month) {
  // Create a new transaction
  struct transaction* transaction = malloc(sizeof(struct transaction));
  transaction->type = type;
  transaction->amount = amount;
  transaction->description = description;
  transaction->month = month;
  // Add the transaction to the planner
  planner->transactions = realloc(planner->transactions, sizeof(struct transaction) * (planner->num_transactions + 1));
  planner->transactions[planner->num_transactions] = *transaction;
  planner->num_transactions++;
}

// Calculate the income and expenses for a month
void calculate_income_and_expenses(struct planner* planner, struct month* month) {
  // Initialize the income and expenses
  month->income = 0;
  month->expenses = 0;
  // Loop through the transactions and calculate the income and expenses
  for (int i = 0; i < planner->num_transactions; i++) {
    struct transaction* transaction = &planner->transactions[i];
    if (transaction->month == month) {
      if (transaction->type == 'I') {
        month->income += transaction->amount;
      } else {
        month->expenses += transaction->amount;
      }
    }
  }
}

// Calculate the savings for a month
void calculate_savings(struct planner* planner, struct month* month) {
  // Initialize the savings
  month->savings = 0;
  // Loop through the transactions and calculate the savings
  for (int i = 0; i < planner->num_transactions; i++) {
    struct transaction* transaction = &planner->transactions[i];
    if (transaction->month == month) {
      if (transaction->type == 'I') {
        month->savings += transaction->amount;
      }
    }
  }
}

// Print the personal finance planner
void print_planner(struct planner* planner) {
  // Print the months
  for (int i = 0; i < 12; i++) {
    struct month* month = &planner->months[i];
    printf("%s %d\n", month->year, month->month);
    calculate_income_and_expenses(planner, month);
    calculate_savings(planner, month);
    printf("Income: $%.2f\n", month->income);
    printf("Expenses: $%.2f\n", month->expenses);
    printf("Savings: $%.2f\n", month->savings);
  }
}

// Main function
int main() {
  // Initialize the personal finance planner
  struct planner* planner = malloc(sizeof(struct planner));
  init_planner(planner);
  // Add transactions
  add_transaction(planner, 'I', 2000, "Salary", &planner->months[0]);
  add_transaction(planner, 'I', 1000, "Savings", &planner->months[1]);
  add_transaction(planner, 'E', 500, "Rent", &planner->months[2]);
  add_transaction(planner, 'E', 200, "Groceries", &planner->months[3]);
  add_transaction(planner, 'I', 1000, "Savings", &planner->months[4]);
  // Print the personal finance planner
  print_planner(planner);
  // Free the memory
  free(planner);
  return 0;
}