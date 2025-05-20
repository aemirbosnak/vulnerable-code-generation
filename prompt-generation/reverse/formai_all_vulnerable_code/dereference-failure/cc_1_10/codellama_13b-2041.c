//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
/*
 * Expense Tracker
 *
 * A program that allows users to track their expenses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Structure to store expense information
typedef struct {
  char name[MAX_NAME_LENGTH];
  float amount;
} Expense;

// Function to add an expense
void addExpense(Expense* expenses, int* num_expenses) {
  // Ask for the name of the expense
  printf("Enter the name of the expense: ");
  fgets(expenses[*num_expenses].name, MAX_NAME_LENGTH, stdin);
  expenses[*num_expenses].name[strlen(expenses[*num_expenses].name) - 1] = '\0';

  // Ask for the amount of the expense
  printf("Enter the amount of the expense: ");
  scanf("%f", &expenses[*num_expenses].amount);

  // Increment the number of expenses
  (*num_expenses)++;
}

// Function to print all expenses
void printExpenses(Expense* expenses, int num_expenses) {
  // Print the header
  printf("---------------------------------\n");
  printf("Expense Tracker\n");
  printf("---------------------------------\n");

  // Print each expense
  for (int i = 0; i < num_expenses; i++) {
    printf("%d. %s: $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
  }

  // Print the total expenses
  float total = 0;
  for (int i = 0; i < num_expenses; i++) {
    total += expenses[i].amount;
  }
  printf("Total expenses: $%.2f\n", total);
}

int main() {
  // Initialize the expenses array
  Expense expenses[MAX_ITEMS];
  int num_expenses = 0;

  // Add expenses until the user quits
  char input;
  do {
    addExpense(expenses, &num_expenses);
    printf("Add another expense? (y/n): ");
    fgets(&input, 1, stdin);
  } while (input != 'n');

  // Print the expenses
  printExpenses(expenses, num_expenses);

  return 0;
}