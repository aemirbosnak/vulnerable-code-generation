//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int day;
  char *description;
  int amount;
} Expense;

int main() {
  // Initialize the array of expenses
  Expense expenses[100];
  int num_expenses = 0;

  // Get the user's input
  printf("Welcome to the Medieval Expense Tracker!\n");
  printf("Enter your expenses below, one per line.\n");
  printf("Format: day description amount\n");
  printf("Example: 1 Bought a new sword 100\n");

  while (1) {
    // Get the next expense
    int day;
    char description[100];
    int amount;
    scanf("%d %s %d", &day, description, &amount);

    // Check if the user has finished entering expenses
    if (day == 0 && strcmp(description, "quit") == 0 && amount == 0) {
      break;
    }

    // Add the expense to the array
    expenses[num_expenses].day = day;
    expenses[num_expenses].description = malloc(strlen(description) + 1);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    num_expenses++;
  }

  // Print the expenses
  printf("\nYour expenses:\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("%d %s %d\n", expenses[i].day, expenses[i].description, expenses[i].amount);
  }

  // Calculate the total expenses
  int total_expenses = 0;
  for (int i = 0; i < num_expenses; i++) {
    total_expenses += expenses[i].amount;
  }

  // Print the total expenses
  printf("\nTotal expenses: %d\n", total_expenses);

  // Free the memory allocated for the descriptions
  for (int i = 0; i < num_expenses; i++) {
    free(expenses[i].description);
  }

  return 0;
}