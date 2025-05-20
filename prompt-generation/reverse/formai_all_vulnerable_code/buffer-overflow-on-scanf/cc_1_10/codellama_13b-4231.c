//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: funny
/*
 * Unique C Expense Tracker Example Program
 * In a funny style
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare variables
const char* USER_NAME;
float total_expenses = 0.0;

// Declare functions
void print_greeting();
void get_user_name();
void print_expenses(float);

int main() {
  print_greeting();
  get_user_name();

  float expenses[5] = {100.0, 200.0, 300.0, 400.0, 500.0};
  for (int i = 0; i < 5; i++) {
    total_expenses += expenses[i];
    print_expenses(expenses[i]);
  }

  printf("Total expenses: %f\n", total_expenses);

  return 0;
}

// Function definitions
void print_greeting() {
  printf("Welcome to the Expense Tracker, %s!\n", USER_NAME);
}

void get_user_name() {
  printf("What is your name? ");
  scanf("%s", USER_NAME);
}

void print_expenses(float expense) {
  printf("You spent %f on... wait for it... ", expense);
  if (expense == 100.0) {
    printf("buying a pizza!\n");
  } else if (expense == 200.0) {
    printf("buying a new shirt!\n");
  } else if (expense == 300.0) {
    printf("buying a new book!\n");
  } else if (expense == 400.0) {
    printf("buying a new game!\n");
  } else if (expense == 500.0) {
    printf("buying a new movie!\n");
  } else {
    printf("buying something else! But I don't know what...\n");
  }
}