//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for storing data
typedef struct {
  char* name;
  double amount;
} BudgetItem;

typedef struct {
  char* name;
  double income;
  double expenses;
  BudgetItem* items;
  int num_items;
} Budget;

// Function for printing a budget
void print_budget(Budget* budget) {
  printf("Budget for %s:\n", budget->name);
  printf("Income: %.2f\n", budget->income);
  printf("Expenses:\n");
  for (int i = 0; i < budget->num_items; i++) {
    printf("  %s: %.2f\n", budget->items[i].name, budget->items[i].amount);
  }
}

// Function for calculating the total expenses
double calculate_total_expenses(Budget* budget) {
  double total = 0;
  for (int i = 0; i < budget->num_items; i++) {
    total += budget->items[i].amount;
  }
  return total;
}

// Function for adding a new budget item
void add_budget_item(Budget* budget, char* name, double amount) {
  budget->items = realloc(budget->items, (budget->num_items + 1) * sizeof(BudgetItem));
  budget->items[budget->num_items].name = strdup(name);
  budget->items[budget->num_items].amount = amount;
  budget->num_items++;
}

int main() {
  // Create a budget for John
  Budget john_budget;
  john_budget.name = "John";
  john_budget.income = 10000;
  john_budget.expenses = 0;
  john_budget.items = NULL;
  john_budget.num_items = 0;

  // Add some budget items to John's budget
  add_budget_item(&john_budget, "Rent", 1000);
  add_budget_item(&john_budget, "Groceries", 500);
  add_budget_item(&john_budget, "Utilities", 150);

  // Print John's budget
  print_budget(&john_budget);

  // Calculate John's total expenses
  double total_expenses = calculate_total_expenses(&john_budget);
  printf("Total expenses: %.2f\n", total_expenses);

  // Free memory allocated for budget items
  for (int i = 0; i < john_budget.num_items; i++) {
    free(john_budget.items[i].name);
  }
  free(john_budget.items);

  return 0;
}