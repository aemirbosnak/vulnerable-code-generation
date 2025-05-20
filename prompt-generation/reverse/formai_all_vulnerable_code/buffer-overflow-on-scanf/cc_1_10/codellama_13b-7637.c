//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: artistic
// Expense Tracker Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for expense items
struct expense {
  char category[32];
  double amount;
};

// Define array for expense items
struct expense expenses[10];

int main() {
  // Initialize variables
  int i, n_expenses = 0;
  char input[128];

  // Print welcome message
  printf("Welcome to the Expense Tracker\n");

  // Loop until user exits
  while (1) {
    // Get user input
    printf("Enter expense category (q to quit): ");
    fgets(input, sizeof(input), stdin);

    // Check if user wants to quit
    if (input[0] == 'q') {
      break;
    }

    // Add expense to array
    strcpy(expenses[n_expenses].category, input);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[n_expenses].amount);
    n_expenses++;
  }

  // Print total expenses
  double total = 0;
  for (i = 0; i < n_expenses; i++) {
    total += expenses[i].amount;
  }
  printf("Total expenses: $%.2f\n", total);

  // Print expense breakdown
  for (i = 0; i < n_expenses; i++) {
    printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
  }

  return 0;
}