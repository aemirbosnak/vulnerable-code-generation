//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: introspective
/*
 * Expense Tracker
 *
 * A simple program to track expenses.
 */

#include <stdio.h>

int main() {
  // Declare variables
  float balance = 1000.00;
  float expense = 0.00;
  char category[20];
  int choice;

  // Welcome message
  printf("Welcome to the Expense Tracker!\n");
  printf("Your current balance is $%.2f.\n", balance);

  // Menu
  printf("Please choose an option:\n");
  printf("1. Add an expense\n");
  printf("2. View expenses\n");
  printf("3. Quit\n");

  // Get user input
  scanf("%d", &choice);

  // Add expense
  if (choice == 1) {
    printf("Enter the amount of the expense: ");
    scanf("%f", &expense);
    printf("Enter the category of the expense: ");
    scanf("%s", &category);
    balance -= expense;
    printf("You have added an expense of $%.2f to the %s category.\n", expense, category);
    printf("Your new balance is $%.2f.\n", balance);
  }

  // View expenses
  else if (choice == 2) {
    printf("Here is your expense history:\n");
    printf("Expense\t\tCategory\n");
    printf("$%.2f\t%s\n", expense, category);
  }

  // Quit
  else if (choice == 3) {
    printf("Thank you for using the Expense Tracker!\n");
    return 0;
  }

  // Invalid input
  else {
    printf("Invalid input. Please try again.\n");
  }

  // End program
  return 0;
}