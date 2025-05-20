//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: statistical
// C Expense Tracker
#include <stdio.h>
#include <stdlib.h>

// Structure to store expense details
struct Expense {
  char description[100];
  float amount;
};

// Function to add an expense
void addExpense(struct Expense *expenses, int *num_expenses, char *description, float amount) {
  struct Expense expense;
  strcpy(expense.description, description);
  expense.amount = amount;
  expenses[*num_expenses] = expense;
  *num_expenses = *num_expenses + 1;
}

// Function to calculate total expenses
float calculateTotal(struct Expense *expenses, int num_expenses) {
  float total = 0;
  for (int i = 0; i < num_expenses; i++) {
    total += expenses[i].amount;
  }
  return total;
}

// Function to calculate average expense
float calculateAverage(struct Expense *expenses, int num_expenses) {
  return calculateTotal(expenses, num_expenses) / num_expenses;
}

// Function to print expenses
void printExpenses(struct Expense *expenses, int num_expenses) {
  for (int i = 0; i < num_expenses; i++) {
    printf("Description: %s\n", expenses[i].description);
    printf("Amount: $%.2f\n", expenses[i].amount);
    printf("\n");
  }
}

int main() {
  struct Expense expenses[10];
  int num_expenses = 0;

  addExpense(expenses, &num_expenses, "Grocery shopping", 50.0);
  addExpense(expenses, &num_expenses, "Dinner", 25.0);
  addExpense(expenses, &num_expenses, "Entertainment", 15.0);

  float total = calculateTotal(expenses, num_expenses);
  float average = calculateAverage(expenses, num_expenses);

  printf("Total expenses: $%.2f\n", total);
  printf("Average expense: $%.2f\n", average);
  printf("\n");

  printExpenses(expenses, num_expenses);

  return 0;
}