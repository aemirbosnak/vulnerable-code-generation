//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define an array to store expense items
char expense_items[10][20];

// Define an array to store expense amounts
int expense_amounts[10];

// Function to add an expense item
void add_expense() {
  // Get the expense item name
  printf("Enter expense item name: ");
  scanf("%s", expense_items[0]);

  // Get the expense amount
  printf("Enter expense amount: ");
  scanf("%d", expense_amounts[0]);
}

// Function to display expenses
void display_expenses() {
  // Print the expense items
  printf("Expense items:\n");
  for (int i = 0; i < 10; i++) {
    if (expense_items[i][0] != '\0') {
      printf("%s\n", expense_items[i]);
    }
  }

  // Print the expense amounts
  printf("Expense amounts:\n");
  for (int i = 0; i < 10; i++) {
    if (expense_items[i][0] != '\0') {
      printf("%d\n", expense_amounts[i]);
    }
  }
}

int main() {
  // Add an expense item
  add_expense();

  // Add another expense item
  add_expense();

  // Display the expenses
  display_expenses();

  return 0;
}