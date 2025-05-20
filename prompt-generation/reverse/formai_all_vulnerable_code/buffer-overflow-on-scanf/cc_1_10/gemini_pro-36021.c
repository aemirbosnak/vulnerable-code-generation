//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_LENGTH 100

typedef struct {
  char description[MAX_LENGTH];
  float amount;
  char category[MAX_LENGTH];
  char date[MAX_LENGTH];
} Expense;

int main() {
  // Create an array of expenses
  Expense expenses[MAX_EXPENSES];

  // Initialize the array of expenses
  for (int i = 0; i < MAX_EXPENSES; i++) {
    expenses[i].description[0] = '\0';
    expenses[i].amount = 0.0;
    expenses[i].category[0] = '\0';
    expenses[i].date[0] = '\0';
  }

  // Get the number of expenses from the user
  int num_expenses;
  printf("Enter the number of expenses: ");
  scanf("%d", &num_expenses);

  // Get the details of each expense from the user
  for (int i = 0; i < num_expenses; i++) {
    printf("Enter the description of expense %d: ", i + 1);
    scanf(" %[^\n]", expenses[i].description);

    printf("Enter the amount of expense %d: ", i + 1);
    scanf(" %f", &expenses[i].amount);

    printf("Enter the category of expense %d: ", i + 1);
    scanf(" %[^\n]", expenses[i].category);

    printf("Enter the date of expense %d: ", i + 1);
    scanf(" %[^\n]", expenses[i].date);
  }

  // Print the expenses
  printf("\nHere are the expenses you entered:\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("%s %f %s %s\n", expenses[i].description, expenses[i].amount, expenses[i].category, expenses[i].date);
  }

  return 0;
}