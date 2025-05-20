//FormAI DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Defining a structure which represents a single expense entry
struct expense {
  char category[20];
  float amount;
  char date[11];
};

// Global variable to keep track of total expenses so far
float totalExpenses = 0.0;

// Function to print the main menu and get the user choice
int printMenuAndGetChoice() {
  printf("\n\nExpense Tracker\n\n");
  printf("1. Add New Expense\n");
  printf("2. View All Expenses\n");
  printf("3. View Expenses by Category\n");
  printf("4. View Total Expenses\n");
  printf("5. Exit\n\n");

  int choice;
  printf("Please enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Function to add a new expense entry
void addExpense(struct expense* expenses, int* numExpenses) {
  printf("\nAdd New Expense\n\n");
  printf("Enter Category: ");
  scanf("%s", expenses[*numExpenses].category);

  printf("Enter Amount: ");
  scanf("%f", &expenses[*numExpenses].amount);
  totalExpenses += expenses[*numExpenses].amount;

  printf("Enter Date (DD-MM-YYYY): ");
  scanf("%s", expenses[*numExpenses].date);

  (*numExpenses)++;
}

// Function to view all expenses
void viewAllExpenses(struct expense* expenses, int numExpenses) {
  if (numExpenses == 0) {
    printf("\nNo expenses yet!\n");
    return;
  }
  printf("\nView All Expenses\n\n");
  for (int i = 0; i < numExpenses; i++) {
    printf("%s\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
  }
}

// Function to view expenses by category
void viewExpensesByCategory(struct expense* expenses, int numExpenses) {
  if (numExpenses == 0) {
    printf("\nNo expenses yet!\n");
    return;
  }

  char category[20];
  printf("\nView Expenses by Category\n\n");
  printf("Enter Category: ");
  scanf("%s", category);

  float totalCategoryExpenses = 0.0;
  printf("\n%s Expenses:\n\n", category);
  for (int i = 0; i < numExpenses; i++) {
    if (strcmp(expenses[i].category, category) == 0) {
      printf("%s\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
      totalCategoryExpenses += expenses[i].amount;
    }
  }
  if (totalCategoryExpenses == 0.0) {
    printf("\nNo expenses found for category: %s\n", category);
  } else {
    printf("\nTotal Expenses for Category %s = %.2f\n", category, totalCategoryExpenses);
  }
}

// Function to view total expenses
void viewTotalExpenses() {
  printf("\nView Total Expenses\n\n");
  printf("Total Expenses so far = %.2f\n", totalExpenses);
}

int main() {
  struct expense expenses[100];
  int numExpenses = 0;
  int choice = 0;

  while (choice != 5) {
    choice = printMenuAndGetChoice();

    switch (choice) {
      case 1:
        addExpense(expenses, &numExpenses);
        break;
      case 2:
        viewAllExpenses(expenses, numExpenses);
        break;
      case 3:
        viewExpensesByCategory(expenses, numExpenses);
        break;
      case 4:
        viewTotalExpenses();
        break;
      case 5:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}