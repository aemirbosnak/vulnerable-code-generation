//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: invasive
// Expense Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
  char description[100];
  float amount;
} Expense;

void addExpense(Expense *expenses, int *num_expenses) {
  if (*num_expenses < MAX_EXPENSES) {
    printf("Enter the description of the expense: ");
    scanf("%s", expenses[*num_expenses].description);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[*num_expenses].amount);
    (*num_expenses)++;
  } else {
    printf("Maximum number of expenses reached\n");
  }
}

void printExpenses(Expense *expenses, int num_expenses) {
  printf("Total expenses: %d\n", num_expenses);
  for (int i = 0; i < num_expenses; i++) {
    printf("  %s: %.2f\n", expenses[i].description, expenses[i].amount);
  }
}

int main() {
  Expense expenses[MAX_EXPENSES];
  int num_expenses = 0;

  while (1) {
    char command;
    printf("(A)dd an expense, (P)rint expenses, (Q)uit: ");
    scanf(" %c", &command);

    switch (command) {
      case 'A':
        addExpense(expenses, &num_expenses);
        break;
      case 'P':
        printExpenses(expenses, num_expenses);
        break;
      case 'Q':
        return 0;
        break;
      default:
        printf("Invalid command\n");
        break;
    }
  }
}