//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 50 // Maximum length of user input string
#define MAX_EXPENSES 100 // Maximum number of expenses that can be tracked

typedef struct Expense { 
  float amount;
  char category[MAX_INPUT_SIZE];
  char description[MAX_INPUT_SIZE];
} Expense;

// Function declarations
void addExpense(Expense expenses[], int *numExpenses);
void viewExpenses(Expense expenses[], int numExpenses);
void saveExpenses(Expense expenses[], int numExpenses);
void loadExpenses(Expense expenses[], int *numExpenses);

int main() {
  Expense expenses[MAX_EXPENSES];
  int numExpenses = 0;
  char choice;

  // Load existing expenses from file (if any)
  loadExpenses(expenses, &numExpenses);

  do {
    // Print menu
    printf("Expense Tracker\n");
    printf("---------------\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");

    // Get user choice
    printf("\nEnter choice (1-3): ");
    scanf(" %c", &choice);

    // Handle user choice
    switch (choice) {
      case '1':
        addExpense(expenses, &numExpenses);
        break;
      case '2':
        viewExpenses(expenses, numExpenses);
        break;
      case '3':
        printf("\nExiting program...\n");
        break;
      default:
        printf("\nInvalid choice. Please enter a number from 1-3.\n");
        break;
    }
  } while (choice != '3');

  // Save expenses to file before exiting
  saveExpenses(expenses, numExpenses);

  return 0;
}

// Adds a new expense to the array
void addExpense(Expense expenses[], int *numExpenses) {
  Expense newExpense;

  // Get amount
  printf("\nEnter amount: ");
  scanf("%f", &newExpense.amount);

  // Get category
  printf("Enter category: ");
  scanf("%s", newExpense.category);

  // Get description
  printf("Enter description: ");
  scanf("%s", newExpense.description);

  // Add expense to array and update counter
  expenses[*numExpenses] = newExpense;
  (*numExpenses)++;

  printf("\nExpense added!\n");
}

// Displays all expenses in the array
void viewExpenses(Expense expenses[], int numExpenses) {
  float total = 0;

  // Print header
  printf("\n%-10s %-15s %-15s\n", "Amount", "Category", "Description");
  printf("----------------------------------------\n");

  // Print each expense
  for (int i = 0; i < numExpenses; i++) {
    printf("%-10.2f %-15s %-15s\n", expenses[i].amount, expenses[i].category, expenses[i].description);
    total += expenses[i].amount;
  }

  // Print total amount
  printf("Total: %-10.2f\n", total);
}

// Saves all expenses in the array to a file
void saveExpenses(Expense expenses[], int numExpenses) {
  FILE *file = fopen("expenses.txt", "w");

  // Write each expense to file
  for (int i = 0; i < numExpenses; i++) {
    fprintf(file, "%.2f %s %s\n", expenses[i].amount, expenses[i].category, expenses[i].description);
  }

  fclose(file);
  printf("\nExpenses saved to file!\n");
}

// Loads expenses from a file into the array
void loadExpenses(Expense expenses[], int *numExpenses) {
  FILE *file = fopen("expenses.txt", "r");

  if (file != NULL) {
    // Read each line from file and create Expense struct
    char line[MAX_INPUT_SIZE * 3];
    while (fgets(line, sizeof(line), file) != NULL && *numExpenses < MAX_EXPENSES) {
      Expense expense;

      char *amountStr = strtok(line, " ");
      char *categoryStr = strtok(NULL, " ");
      char *descriptionStr = strtok(NULL, " ");

      expense.amount = atof(amountStr);
      strcpy(expense.category, categoryStr);
      strcpy(expense.description, descriptionStr);

      expenses[*numExpenses] = expense;
      (*numExpenses)++;
    }

    fclose(file);
    printf("\nExpenses loaded from file!\n");
  }
}