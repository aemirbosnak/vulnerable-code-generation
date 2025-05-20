//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: authentic
// Expense Tracker in C
#include <stdio.h>

// Structure to store expenses
struct Expense {
  char category[50];
  double amount;
};

// Function to add an expense
void add_expense(struct Expense *expense) {
  // Ask for the category and amount
  printf("Enter the category: ");
  scanf("%s", expense->category);
  printf("Enter the amount: ");
  scanf("%lf", &expense->amount);
}

// Function to display all expenses
void display_expenses(struct Expense *expenses, int num_expenses) {
  // Display the expenses
  for (int i = 0; i < num_expenses; i++) {
    printf("%s: $%.2lf\n", expenses[i].category, expenses[i].amount);
  }
}

// Function to calculate the total expenses
double calculate_total_expenses(struct Expense *expenses, int num_expenses) {
  double total = 0.0;
  // Calculate the total expenses
  for (int i = 0; i < num_expenses; i++) {
    total += expenses[i].amount;
  }
  return total;
}

int main() {
  // Declare an array to store expenses
  struct Expense expenses[10];
  int num_expenses = 0;

  // Add expenses
  while (num_expenses < 10) {
    add_expense(&expenses[num_expenses]);
    num_expenses++;
  }

  // Display expenses
  display_expenses(expenses, num_expenses);

  // Calculate total expenses
  double total = calculate_total_expenses(expenses, num_expenses);
  printf("Total expenses: $%.2lf\n", total);

  return 0;
}