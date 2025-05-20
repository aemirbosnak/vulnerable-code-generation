//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Budget {
  char name[20];
  int income;
  int expenses[MAX];
  int numExpenses;
} Budget;

void createBudget(Budget *budget) {
  printf("Enter budget name: ");
  scanf("%s", budget->name);

  printf("Enter income: ");
  scanf("%d", &budget->income);

  budget->numExpenses = 0;
}

void addExpense(Budget *budget) {
  if (budget->numExpenses == MAX) {
    printf("Error: Maximum number of expenses reached.\n");
    return;
  }

  printf("Enter expense amount: ");
  scanf("%d", &budget->expenses[budget->numExpenses]);
  budget->numExpenses++;
}

void displayBudget(Budget *budget) {
  printf("Budget Name: %s\n", budget->name);
  printf("Income: %d\n", budget->income);
  printf("Expenses:\n");
  for (int i = 0; i < budget->numExpenses; i++) {
    printf("  %d\n", budget->expenses[i]);
  }
  printf("Total Expenses: %d\n", budget->numExpenses * budget->expenses[0]);
  printf("Remaining Balance: %d\n", budget->income - budget->numExpenses * budget->expenses[0]);
}

int main() {
  Budget myBudget;
  createBudget(&myBudget);
  addExpense(&myBudget);
  addExpense(&myBudget);
  displayBudget(&myBudget);

  return 0;
}