//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of expenses
#define MAX_EXPENSES 100

// Define a structure for each expense
struct Expense {
  char category[20];
  float amount;
  char date[10];
};

// Define a function to add a new expense
void addExpense(struct Expense expenses[], int *numExpenses) {
  // Check if maximum number of expenses has been reached
  if (*numExpenses == MAX_EXPENSES) {
    printf("Maximum number of expenses has been reached.\n");
    return;
  }

  // Prompt user to enter expense details
  printf("Enter expense category: ");
  scanf("%s", &expenses[*numExpenses].category);

  printf("Enter expense amount: ");
  scanf("%f", &expenses[*numExpenses].amount);

  printf("Enter expense date (DD/MM/YYYY): ");
  scanf("%s", &expenses[*numExpenses].date);

  // Increment number of expenses
  (*numExpenses)++;
}

// Define a function to print all expenses
void printExpenses(struct Expense expenses[], int numExpenses) {
  // Check if there are no expenses
  if (numExpenses == 0) {
    printf("There are no expenses.\n");
    return;
  }

  // Print header
  printf("Category\tAmount\t\tDate\n");

  // Loop through all expenses
  for (int i = 0; i < numExpenses; i++) {
    // Print expense details
    printf("%s\t\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
  }
}

// Define a function to calculate total expenses
float calculateTotalExpenses(struct Expense expenses[], int numExpenses) {
  // Initialize total to 0
  float total = 0;

  // Loop through all expenses and add each amount to the total
  for (int i = 0; i < numExpenses; i++) {
    total += expenses[i].amount;
  }

  return total;
}

int main() {
  // Initialize an empty array of expenses
  struct Expense expenses[MAX_EXPENSES];

  // Initialize number of expenses to 0
  int numExpenses = 0;

  // Loop until user chooses to exit
  while (1) {
    printf("Expense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View All Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");

    // Prompt user to enter choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addExpense(expenses, &numExpenses);
        break;

      case 2:
        printExpenses(expenses, numExpenses);
        break;

      case 3:
        printf("Total expenses: %.2f\n", calculateTotalExpenses(expenses, numExpenses));
        break;

      case 4:
        exit(0);

      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }

  return 0;
}