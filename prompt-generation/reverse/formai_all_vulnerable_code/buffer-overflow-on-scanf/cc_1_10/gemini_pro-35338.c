//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
  char name[50];
  float amount;
  char category[50];
  char date[20];
} Expense;

int main() {
  // Declare an array of expenses
  Expense expenses[MAX_EXPENSES];

  // Get the number of expenses from the user
  int numExpenses;
  printf("How many expenses do you want to track? ");
  scanf("%d", &numExpenses);

  // Get the details of each expense
  for (int i = 0; i < numExpenses; i++) {
    printf("Enter the name of the expense: ");
    scanf("%s", expenses[i].name);

    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[i].amount);

    printf("Enter the category of the expense: ");
    scanf("%s", expenses[i].category);

    printf("Enter the date of the expense (YYYY-MM-DD): ");
    scanf("%s", expenses[i].date);

    printf("\n");
  }

  // Print a summary of the expenses
  printf("Your expenses are:\n");
  for (int i = 0; i < numExpenses; i++) {
    printf("%s: $%.2f (%s) - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
  }

  // Calculate the total amount of expenses
  float totalAmount = 0;
  for (int i = 0; i < numExpenses; i++) {
    totalAmount += expenses[i].amount;
  }

  // Print the total amount of expenses
  printf("\nTotal amount spent: $%.2f\n", totalAmount);

  return 0;
}