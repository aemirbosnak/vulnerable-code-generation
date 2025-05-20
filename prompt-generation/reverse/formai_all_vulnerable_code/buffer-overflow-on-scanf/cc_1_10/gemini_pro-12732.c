//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char *description;
  float amount;
  char *date;
} Expense;

// Create an array of expenses
Expense expenses[MAX_EXPENSES];

// Get the number of expenses from the user
int get_num_expenses() {
  int num_expenses;
  printf("Enter the number of expenses: ");
  scanf("%d", &num_expenses);
  return num_expenses;
}

// Get the details of an expense from the user
Expense get_expense(int index) {
  Expense expense;
  char buffer[100];

  // Get the description of the expense
  printf("Enter the description of expense %d: ", index + 1);
  scanf(" %[^\n]s", buffer);
  expense.description = strdup(buffer);

  // Get the amount of the expense
  printf("Enter the amount of expense %d: ", index + 1);
  scanf("%f", &expense.amount);

  // Get the date of the expense
  printf("Enter the date of expense %d (dd/mm/yyyy): ", index + 1);
  scanf(" %[^\n]s", buffer);
  expense.date = strdup(buffer);

  return expense;
}

// Print the details of an expense
void print_expense(Expense expense) {
  printf("Description: %s\n", expense.description);
  printf("Amount: %.2f\n", expense.amount);
  printf("Date: %s\n", expense.date);
}

// Print the total amount of expenses
void print_total_amount(int num_expenses) {
  float total_amount = 0;
  for (int i = 0; i < num_expenses; i++) {
    total_amount += expenses[i].amount;
  }
  printf("Total amount: %.2f\n", total_amount);
}

// Free the memory allocated for the expenses
void free_expenses(int num_expenses) {
  for (int i = 0; i < num_expenses; i++) {
    free(expenses[i].description);
    free(expenses[i].date);
  }
}

// Main function
int main() {
  int num_expenses;

  // Get the number of expenses from the user
  num_expenses = get_num_expenses();

  // Get the details of each expense from the user
  for (int i = 0; i < num_expenses; i++) {
    expenses[i] = get_expense(i);
  }

  // Print the details of each expense
  for (int i = 0; i < num_expenses; i++) {
    print_expense(expenses[i]);
  }

  // Print the total amount of expenses
  print_total_amount(num_expenses);

  // Free the memory allocated for the expenses
  free_expenses(num_expenses);

  return 0;
}