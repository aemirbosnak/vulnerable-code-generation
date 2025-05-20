//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense details
typedef struct {
  char category[50];
  double amount;
} expense_t;

// Function to add an expense
void add_expense(expense_t* expense) {
  printf("Enter category: ");
  scanf("%s", expense->category);
  printf("Enter amount: ");
  scanf("%lf", &expense->amount);
}

// Function to display all expenses
void display_expenses(expense_t* expenses, int num_expenses) {
  int i;
  printf("Expenses:\n");
  for (i = 0; i < num_expenses; i++) {
    printf("Category: %s\n", expenses[i].category);
    printf("Amount: %.2f\n", expenses[i].amount);
  }
}

// Function to calculate total expenses
double calculate_total(expense_t* expenses, int num_expenses) {
  double total = 0.0;
  int i;
  for (i = 0; i < num_expenses; i++) {
    total += expenses[i].amount;
  }
  return total;
}

int main() {
  expense_t expenses[5];
  int num_expenses = 0;
  int i;

  // Add expenses
  for (i = 0; i < 5; i++) {
    add_expense(&expenses[i]);
    num_expenses++;
  }

  // Display expenses
  display_expenses(expenses, num_expenses);

  // Calculate total expenses
  double total = calculate_total(expenses, num_expenses);
  printf("Total expenses: %.2f\n", total);

  return 0;
}