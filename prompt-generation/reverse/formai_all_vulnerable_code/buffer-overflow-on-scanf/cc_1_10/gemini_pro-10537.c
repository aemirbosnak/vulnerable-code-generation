//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char description[50];
  float amount;
  int category;
} Expense;

// Define the categories of expenses
enum category {
  FOOD = 1,
  DRINK,
  ENTERTAINMENT,
  OTHER
};

// Get the user input for an expense
Expense getExpense() {
  Expense expense;
  printf("Enter the expense description: ");
  scanf("%s", expense.description);
  printf("Enter the expense amount: ");
  scanf("%f", &expense.amount);
  printf("Enter the expense category (1 for FOOD, 2 for DRINK, 3 for ENTERTAINMENT, 4 for OTHER): ");
  scanf("%d", &expense.category);
  return expense;
}

// Print the expense
void printExpense(Expense expense) {
  printf("Description: %s\n", expense.description);
  printf("Amount: %f\n", expense.amount);
  switch (expense.category) {
    case FOOD:
      printf("Category: FOOD\n");
      break;
    case DRINK:
      printf("Category: DRINK\n");
      break;
    case ENTERTAINMENT:
      printf("Category: ENTERTAINMENT\n");
      break;
    case OTHER:
      printf("Category: OTHER\n");
      break;
  }
}

// Get the total amount of expenses
float getTotalAmount(Expense expenses[], int numExpenses) {
  float totalAmount = 0;
  for (int i = 0; i < numExpenses; i++) {
    totalAmount += expenses[i].amount;
  }
  return totalAmount;
}

// Get the average amount of expenses
float getAverageAmount(Expense expenses[], int numExpenses) {
  float totalAmount = getTotalAmount(expenses, numExpenses);
  return totalAmount / numExpenses;
}

// Get the most expensive expense
Expense getMostExpensiveExpense(Expense expenses[], int numExpenses) {
  Expense mostExpensiveExpense = expenses[0];
  for (int i = 1; i < numExpenses; i++) {
    if (expenses[i].amount > mostExpensiveExpense.amount) {
      mostExpensiveExpense = expenses[i];
    }
  }
  return mostExpensiveExpense;
}

// Get the least expensive expense
Expense getLeastExpensiveExpense(Expense expenses[], int numExpenses) {
  Expense leastExpensiveExpense = expenses[0];
  for (int i = 1; i < numExpenses; i++) {
    if (expenses[i].amount < leastExpensiveExpense.amount) {
      leastExpensiveExpense = expenses[i];
    }
  }
  return leastExpensiveExpense;
}

// Print the expenses
void printExpenses(Expense expenses[], int numExpenses) {
  for (int i = 0; i < numExpenses; i++) {
    printExpense(expenses[i]);
    printf("\n");
  }
}

// Main function
int main() {
  // Get the user input for the number of expenses
  int numExpenses;
  printf("Enter the number of expenses: ");
  scanf("%d", &numExpenses);

  // Get the user input for each expense
  Expense expenses[MAX_EXPENSES];
  for (int i = 0; i < numExpenses; i++) {
    expenses[i] = getExpense();
  }

  // Print the expenses
  printf("Expenses:\n");
  printExpenses(expenses, numExpenses);

  // Get the total amount of expenses
  float totalAmount = getTotalAmount(expenses, numExpenses);
  printf("Total amount: %f\n", totalAmount);

  // Get the average amount of expenses
  float averageAmount = getAverageAmount(expenses, numExpenses);
  printf("Average amount: %f\n", averageAmount);

  // Get the most expensive expense
  Expense mostExpensiveExpense = getMostExpensiveExpense(expenses, numExpenses);
  printf("Most expensive expense:\n");
  printExpense(mostExpensiveExpense);

  // Get the least expensive expense
  Expense leastExpensiveExpense = getLeastExpensiveExpense(expenses, numExpenses);
  printf("Least expensive expense:\n");
  printExpense(leastExpensiveExpense);

  return 0;
}