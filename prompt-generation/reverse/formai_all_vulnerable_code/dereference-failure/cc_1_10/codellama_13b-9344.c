//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: excited
/*
 * Expense Tracker
 *
 * This program allows you to track your expenses by
 * entering them into a database.
 *
 * Usage:
 *  - Enter the amount of your expense
 *  - Enter the category of your expense
 *  - Enter the description of your expense
 *
 * Example:
 *  - Enter amount: 20
 *  - Enter category: Groceries
 *  - Enter description: Bought milk, eggs, and bread
 *
 * Output:
 *  - Your expense has been recorded.
 *  - Total expenses: 20
 *  - Total groceries expenses: 20
 *  - Total milk expenses: 10
 *  - Total eggs expenses: 5
 *  - Total bread expenses: 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORY_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
  char category[MAX_CATEGORY_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  float amount;
} Expense;

void print_menu() {
  printf("Welcome to the Expense Tracker!\n");
  printf("Please select an option:\n");
  printf("1. Enter expense\n");
  printf("2. Print expenses\n");
  printf("3. Exit\n");
}

void enter_expense(Expense *expense) {
  printf("Enter the amount of your expense: ");
  scanf("%f", &expense->amount);
  printf("Enter the category of your expense: ");
  scanf("%s", expense->category, MAX_CATEGORY_LENGTH);
  printf("Enter the description of your expense: ");
  scanf("%s", expense->description, MAX_DESCRIPTION_LENGTH);
  printf("Your expense has been recorded.\n");
}

void print_expenses(Expense *expenses, int num_expenses) {
  printf("Total expenses: %f\n", expenses[num_expenses - 1].amount);
  float total_category_amount = 0;
  for (int i = 0; i < num_expenses; i++) {
    if (strcmp(expenses[i].category, "Groceries") == 0) {
      total_category_amount += expenses[i].amount;
    }
  }
  printf("Total groceries expenses: %f\n", total_category_amount);
}

int main() {
  int num_expenses = 0;
  Expense expenses[100];

  while (1) {
    print_menu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        enter_expense(&expenses[num_expenses++]);
        break;
      case 2:
        print_expenses(expenses, num_expenses);
        break;
      case 3:
        return 0;
    }
  }

  return 0;
}