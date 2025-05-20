//FormAI DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_EXPENSES 20

typedef struct {
  float amount;
  char description[MAX_DESCRIPTION_LENGTH];
} Expense;

void printDivider() {
  printf("---------------------------------------------\n");
}

void printHeader() {
  printf("       EXPENSE TRACKER\n\n");
  printf("---------------------------------------------\n");
}

void printExpense(Expense expense) {
  printf("$%.2f\t%s\n", expense.amount, expense.description);
}

void printExpenses(Expense expenses[], int expenseCount) {
  float total = 0;
  printf("Expenses:\n\n");
  for (int i = 0; i < expenseCount; i++) {
    printExpense(expenses[i]);
    total += expenses[i].amount;
  }
  printDivider();
  printf("Total: $%.2f\n", total);
}

Expense addExpense() {
  Expense expense;
  printf("Enter expense amount: $");
  scanf("%f", &expense.amount);

  printf("Enter expense description: ");
  while ((getchar()) != '\n'); //clear input buffer
  fgets(expense.description, MAX_DESCRIPTION_LENGTH, stdin);
  expense.description[strlen(expense.description) - 1] = '\0'; //remove trailing newline character

  return expense;
}

int main() {
  Expense expenses[MAX_EXPENSES];
  int expenseCount = 0;
  bool quitting = false;

  while (!quitting) {
    printHeader();
    printExpenses(expenses, expenseCount);
    printf("\nWhat would you like to do?\n");
    printf("1. Add an expense\n");
    printf("2. Quit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (expenseCount >= MAX_EXPENSES) {
          printf("\nError: Maximum number of expenses reached.\n");
        } else {
          expenses[expenseCount] = addExpense();
          expenseCount++;
        }
        break;

      case 2:
        quitting = true;
        break;

      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
    printf("\n");
  }
  printf("Thank you for using the Expense Tracker!\n");
  return 0;
}