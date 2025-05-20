//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Expense {
  char description[100];
  double amount;
};

struct ExpenseTracker {
  int num_expenses;
  struct Expense* expenses;
};

void print_expense_tracker(struct ExpenseTracker* tracker) {
  int i;
  for (i = 0; i < tracker->num_expenses; i++) {
    printf("%s: $%.2lf\n", tracker->expenses[i].description, tracker->expenses[i].amount);
  }
}

int main() {
  struct ExpenseTracker tracker;
  tracker.num_expenses = 0;
  tracker.expenses = NULL;

  char description[100];
  double amount;
  while (1) {
    printf("Enter an expense description: ");
    scanf("%s", description);
    if (strcmp(description, "quit") == 0) {
      break;
    }

    printf("Enter the amount: ");
    scanf("%lf", &amount);

    struct Expense* new_expense = malloc(sizeof(struct Expense));
    strcpy(new_expense->description, description);
    new_expense->amount = amount;

    tracker.expenses = realloc(tracker.expenses, (tracker.num_expenses + 1) * sizeof(struct Expense));
    tracker.expenses[tracker.num_expenses] = *new_expense;
    tracker.num_expenses++;
  }

  print_expense_tracker(&tracker);

  return 0;
}