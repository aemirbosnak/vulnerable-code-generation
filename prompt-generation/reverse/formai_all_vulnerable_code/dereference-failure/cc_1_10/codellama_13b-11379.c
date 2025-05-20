//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: light-weight
/*
 * expense_tracker.c
 *
 * A simple expense tracker program in C.
 *
 * Usage:
 *    ./expense_tracker <category> <amount>
 *
 * Example:
 *    ./expense_tracker groceries 50.50
 *
 * Output:
 *    Added 50.50 to groceries category.
 *
 * Author:
 *    David R. G.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_AMOUNT 100

struct expense {
  char category[MAX_CATEGORIES];
  float amount;
};

struct expense_tracker {
  struct expense expenses[MAX_CATEGORIES];
  int num_expenses;
};

void add_expense(struct expense_tracker *tracker, char *category, float amount) {
  struct expense *expense = &tracker->expenses[tracker->num_expenses++];
  strncpy(expense->category, category, MAX_CATEGORIES - 1);
  expense->amount = amount;
}

void print_expenses(struct expense_tracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    printf("Category: %s, Amount: %.2f\n", tracker->expenses[i].category, tracker->expenses[i].amount);
  }
}

int main(int argc, char *argv[]) {
  struct expense_tracker tracker;
  tracker.num_expenses = 0;

  if (argc != 3) {
    printf("Usage: %s <category> <amount>\n", argv[0]);
    return 1;
  }

  add_expense(&tracker, argv[1], atof(argv[2]));
  print_expenses(&tracker);

  return 0;
}