//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem {
  char name[50];
  int amount;
  char category[50];
} ExpenseItem;

int main() {
  ExpenseItem items[MAX_EXPENSE_ITEMS];
  int numItems = 0;
  char input[100];

  printf("Welcome to the Expense Tracker!\n");

  // Loop until the user enters "quit"
  while (1) {
    printf("Enter the name of the expense: ");
    scanf("%s", items[numItems].name);

    printf("Enter the amount of the expense: ");
    scanf("%d", &items[numItems].amount);

    printf("Enter the category of the expense: ");
    scanf("%s", items[numItems].category);

    numItems++;

    printf("Do you want to enter another expense? (y/n): ");
    scanf("%s", input);

    if (strcmp(input, "y") == 0) {
      continue;
    } else if (strcmp(input, "n") == 0) {
      break;
    } else {
      printf("Invalid input.\n");
    }
  }

  // Print a summary of the expenses
  printf("Here is a summary of your expenses:\n");
  for (int i = 0; i < numItems; i++) {
    printf("Name: %s, Amount: %d, Category: %s\n", items[i].name, items[i].amount, items[i].category);
  }

  // Calculate the total expense
  int totalExpense = 0;
  for (int i = 0; i < numItems; i++) {
    totalExpense += items[i].amount;
  }

  // Print the total expense
  printf("Total expense: %d\n", totalExpense);

  return 0;
}