//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense data
struct Expense {
  char name[50];
  double amount;
  char category[30];
  char date[11];
};

// Functions to display and add expenses
void display_expenses(struct Expense expenses[], int num_expenses) {
  printf("\nExpense List\n");
  printf("-------------\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("Name: %s\n", expenses[i].name);
    printf("Amount: $%.2lf\n", expenses[i].amount);
    printf("Category: %s\n", expenses[i].category);
    printf("Date: %s\n", expenses[i].date);
    printf("\n");
  }
}

void add_expense(struct Expense expenses[], int *num_expenses) {
  printf("\nAdd Expense\n");
  printf("-----------\n");
  printf("Enter name: ");
  scanf(" %[^\n]", expenses[*num_expenses].name);
  printf("Enter amount: ");
  scanf("%lf", &expenses[*num_expenses].amount);
  printf("Enter category: ");
  scanf(" %[^\n]", expenses[*num_expenses].category);
  printf("Enter date (YYYY-MM-DD): ");
  scanf(" %[^\n]", expenses[*num_expenses].date);
  (*num_expenses)++;
}

int main() {
  int num_expenses = 0;
  struct Expense expenses[100];

  // Main menu
  int choice;
  while (1) {
    printf("\nExpense Tracker\n");
    printf("---------------\n");
    printf("1. Display Expenses\n");
    printf("2. Add Expense\n");
    printf("3. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        display_expenses(expenses, num_expenses);
        break;
      case 2:
        add_expense(expenses, &num_expenses);
        break;
      case 3:
        printf("\nGoodbye!\n");
        exit(0);
      default:
        printf("\nInvalid choice\n");
    }
  }

  return 0;
}