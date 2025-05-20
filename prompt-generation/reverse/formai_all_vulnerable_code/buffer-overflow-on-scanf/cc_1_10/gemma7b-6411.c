//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

struct Expense {
  char name[50];
  int amount;
  char category[50];
};

void main() {
  struct Expense expenses[MAX_EXPENSES];
  int numExpenses = 0;

  // Loop to get expenses
  while (1) {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%d", &expenses[numExpenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[numExpenses].category);

    numExpenses++;

    // Check if the user wants to continue
    char continue_or_not;
    printf("Do you want to add another expense? (Y/N): ");
    scanf(" %c", &continue_or_not);

    if (continue_or_not == 'n' || continue_or_not == 'N') {
      break;
    }
  }

  // Print the expenses
  printf("Here is a list of your expenses:\n");
  for (int i = 0; i < numExpenses; i++) {
    printf("Name: %s, Amount: %d, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
  }

  // Calculate the total expense
  int totalExpense = 0;
  for (int i = 0; i < numExpenses; i++) {
    totalExpense += expenses[i].amount;
  }

  // Print the total expense
  printf("Total expense: %d\n", totalExpense);

  return;
}