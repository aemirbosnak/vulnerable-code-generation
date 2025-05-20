//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char *description;
  double amount;
  double tax;
  double total;
} expense;

// Define the function to create a new expense
expense *new_expense(char *description, double amount, double tax) {
  // Allocate memory for the new expense
  expense *e = malloc(sizeof(expense));

  // Set the description, amount, and tax of the new expense
  e->description = description;
  e->amount = amount;
  e->tax = tax;

  // Calculate the total cost of the new expense
  e->total = amount * (1 + tax);

  // Return the new expense
  return e;
}

// Define the function to print an expense
void print_expense(expense *e) {
  // Print the description, amount, tax, and total cost of the expense
  printf("%s\t%.2f\t%.2f\t%.2f\n", e->description, e->amount, e->tax, e->total);
}

// Define the function to get the total cost of all expenses
double get_total_cost(expense **expenses, int num_expenses) {
  // Initialize the total cost to 0
  double total_cost = 0;

  // Iterate over all expenses and add their total cost to the total cost
  for (int i = 0; i < num_expenses; i++) {
    total_cost += expenses[i]->total;
  }

  // Return the total cost
  return total_cost;
}

// Define the function to print the total cost of all expenses
void print_total_cost(double total_cost) {
  // Print the total cost
  printf("Total cost: %.2f\n", total_cost);
}

// Define the main function
int main() {
  // Create an array of expenses
  expense *expenses[MAX_EXPENSES];

  // Initialize the number of expenses to 0
  int num_expenses = 0;

  // Get the input from the user
  char *description;
  double amount;
  double tax;
  while (scanf("%s %lf %lf", &description, &amount, &tax) == 3) {
    // Create a new expense
    expense *e = new_expense(description, amount, tax);

    // Add the new expense to the array of expenses
    expenses[num_expenses++] = e;
  }

  // Print the expenses
  printf("Description\tAmount\tTax\tTotal\n");
  for (int i = 0; i < num_expenses; i++) {
    print_expense(expenses[i]);
  }

  // Get the total cost of all expenses
  double total_cost = get_total_cost(expenses, num_expenses);

  // Print the total cost of all expenses
  print_total_cost(total_cost);

  // Free the memory allocated for the expenses
  for (int i = 0; i < num_expenses; i++) {
    free(expenses[i]);
  }

  // Return 0
  return 0;
}