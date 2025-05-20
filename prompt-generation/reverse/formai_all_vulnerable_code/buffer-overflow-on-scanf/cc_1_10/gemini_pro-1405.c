//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Well, f*ck me sideways!
const char * CATEGORIES[] = {
  "Food",
  "Booze",
  "Rent",
  "Utilities",
  "Transportation",
  "Entertainment",
  "Shopping",
  "Other",
};

// Holds a single expense
struct expense {
  char * category;
  float amount;
};

// Holds an array of expenses
struct expense_list {
  int num_expenses;
  struct expense * expenses;
};

// Creates a new expense
struct expense * new_expense(char * category, float amount) {
  struct expense * exp = malloc(sizeof(struct expense));
  exp->category = strdup(category);
  exp->amount = amount;
  return exp;
}

// Creates a new expense list
struct expense_list * new_expense_list() {
  struct expense_list * list = malloc(sizeof(struct expense_list));
  list->num_expenses = 0;
  list->expenses = NULL;
  return list;
}

// Adds an expense to a list
void add_expense(struct expense_list * list, struct expense * exp) {
  list->num_expenses++;
  list->expenses = realloc(list->expenses, list->num_expenses * sizeof(struct expense));
  list->expenses[list->num_expenses - 1] = *exp;
}

// Prints a list of expenses
void print_expenses(struct expense_list * list) {
  for (int i = 0; i < list->num_expenses; i++) {
    printf("%s: $%.2f\n", list->expenses[i].category, list->expenses[i].amount);
  }
}

// Frees an expense list
void free_expense_list(struct expense_list * list) {
  for (int i = 0; i < list->num_expenses; i++) {
    free(list->expenses[i].category);
  }
  free(list->expenses);
  free(list);
}

// Main program
int main() {
  // Create an expense list
  struct expense_list * list = new_expense_list();

  // Get a bunch of expense data
  char * input;
  while (1) {
    printf("Enter an expense (category and amount, separated by a space): ");
    input = malloc(100);
    scanf("%s", input);
    if (!strcmp(input, "quit")) {
      break;
    }
    char * category = strtok(input, " ");
    char * amount = strtok(NULL, " ");
    add_expense(list, new_expense(category, atof(amount)));
  }
  free(input);

  // Print the list of expenses
  printf("\nExpenses:\n");
  print_expenses(list);

  // Free the expense list
  free_expense_list(list);

  return 0;
}