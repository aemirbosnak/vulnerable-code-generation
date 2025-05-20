//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// List of categories for expenses
char *categories[] = {"Housing", "Food", "Transportation", "Utilities", "Entertainment", "Personal Care", "Other"};

// Function to get user input
double get_input(char *prompt) {
  double input;
  printf("%s: ", prompt);
  scanf("%lf", &input);
  return input;
}

// Function to print a table of expenses
void print_table(double expenses[], int num_categories) {
  printf("+----------------+----------+\n");
  printf("| Category       | Amount   |\n");
  printf("+----------------+----------+\n");
  for (int i = 0; i < num_categories; i++) {
    printf("| %-15s | $%-8.2f |\n", categories[i], expenses[i]);
  }
  printf("+----------------+----------+\n");
}

// Function to calculate the total expenses
double calculate_total(double expenses[], int num_categories) {
  double total = 0;
  for (int i = 0; i < num_categories; i++) {
    total += expenses[i];
  }
  return total;
}

// Function to print a summary of expenses
void print_summary(double expenses[], int num_categories) {
  double total = calculate_total(expenses, num_categories);
  printf("\nSummary:\n");
  printf("Total Expenses: $%.2f\n", total);
  printf("Average Expense: $%.2f\n", total / num_categories);
  printf("Thank you for using the Personal Finance Planner! :)\n");
}

int main() {
  // Get user input for expenses
  double expenses[7];
  for (int i = 0; i < 7; i++) {
    expenses[i] = get_input(categories[i]);
  }

  // Print a table of expenses
  print_table(expenses, 7);

  // Print a summary of expenses
  print_summary(expenses, 7);

  return 0;
}