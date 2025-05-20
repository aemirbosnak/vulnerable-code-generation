//FormAI DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of expenses
#define MAX_EXPENSES 100

// Define structure for expenses
typedef struct {
  char category[20];
  float amount;
} Expense;

// Define function to add expense
int addExpense(Expense expenses[], int size) {
  // Check if maximum number of expenses reached
  if (size == MAX_EXPENSES) {
    printf("Cannot add more expenses. Maximum number of expenses reached.\n");
    return size;
  }

  // Get input for expense category and amount
  char category[20];
  float amount;
  printf("Enter category: ");
  scanf("%s", category);
  printf("Enter amount: ");
  scanf("%f", &amount);

  // Create expense and add to expenses array
  Expense expense;
  strcpy(expense.category, category);
  expense.amount = amount;
  expenses[size] = expense;

  // Return new size of expenses array
  return size + 1;
}

// Define function to display expenses by category
void displayExpensesByCategory(Expense expenses[], int size) {
  // Create array to hold categories
  char categories[MAX_EXPENSES][20];
  int numCategories = 0;

  // Loop through expenses and add unique categories to categories array
  for (int i = 0; i < size; i++) {
    // Check if category already exists in categories array
    int j;
    for (j = 0; j < numCategories; j++) {
      if (strcmp(expenses[i].category, categories[j]) == 0) {
        break;
      }
    }

    // If category does not exist in categories array, add it
    if (j == numCategories) {
      strcpy(categories[numCategories], expenses[i].category);
      numCategories++;
    }
  }

  // Loop through categories array and display expenses for each category
  for (int i = 0; i < numCategories; i++) {
    printf("%s expenses:\n", categories[i]);
    for (int j = 0; j < size; j++) {
      if (strcmp(expenses[j].category, categories[i]) == 0) {
        printf("$%.2f\n", expenses[j].amount);
      }
    }
    printf("\n");
  }
}

// Define main function
int main() {
  // Create empty expenses array
  Expense expenses[MAX_EXPENSES];
  int size = 0;

  // Display menu and get user input
  int choice;
  do {
    printf("Expense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses by Category\n");
    printf("3. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    // Process user choice
    switch (choice) {
      case 1:
        size = addExpense(expenses, size);
        break;
      case 2:
        displayExpensesByCategory(expenses, size);
        break;
      case 3:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 3);

  // Exit program
  return 0;
}