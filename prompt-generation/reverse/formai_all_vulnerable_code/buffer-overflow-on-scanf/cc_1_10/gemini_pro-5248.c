//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
// Welcome to the Personal Finance Planner, your financial confidant!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 20
#define MAX_BUDGETS 10

// Define some structures
typedef struct {
  char name[50];
  int amount;
} Transaction;

typedef struct {
  char name[50];
  int budget;
} Budget;

typedef struct {
  char name[50];
  Transaction transactions[MAX_TRANSACTIONS];
  int numTransactions;
} Category;

// Define some global variables
Category categories[MAX_CATEGORIES];
int numCategories;
Budget budgets[MAX_BUDGETS];
int numBudgets;

// Function declarations
void addTransaction(char *category, char *name, int amount);
void addBudget(char *name, int budget);
void printTransactions();
void printBudgets();

// Main function
int main() {
  // Initialize the program

  char choice;
  do {
    // Display the menu
    printf("Personal Finance Planner\n");
    printf("-----------------------\n");
    printf("1. Add a transaction\n");
    printf("2. Add a budget\n");
    printf("3. Print transactions\n");
    printf("4. Print budgets\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    // Get the user's choice
    scanf(" %c", &choice);

    // Process the user's choice
    switch (choice) {
      case '1': {
        // Get the transaction details
        char category[50];
        char name[50];
        int amount;
        printf("Enter the category: ");
        scanf(" %s", category);
        printf("Enter the name: ");
        scanf(" %s", name);
        printf("Enter the amount: ");
        scanf(" %d", &amount);

        // Add the transaction
        addTransaction(category, name, amount);

        break;
      }
      case '2': {
        // Get the budget details
        char name[50];
        int budget;
        printf("Enter the name: ");
        scanf(" %s", name);
        printf("Enter the budget: ");
        scanf(" %d", &budget);

        // Add the budget
        addBudget(name, budget);

        break;
      }
      case '3': {
        // Print the transactions
        printTransactions();

        break;
      }
      case '4': {
        // Print the budgets
        printBudgets();

        break;
      }
      case '5': {
        // Exit the program
        printf("Goodbye!\n");

        break;
      }
      default: {
        // Invalid choice
        printf("Invalid choice. Please try again.\n");

        break;
      }
    }
  } while (choice != '5');

  return 0;
}

// Function to add a transaction
void addTransaction(char *category, char *name, int amount) {
  // Find the category
  int i;
  for (i = 0; i < numCategories; i++) {
    if (strcmp(categories[i].name, category) == 0) {
      break;
    }
  }

  // If the category does not exist, create it
  if (i == numCategories) {
    strcpy(categories[i].name, category);
    categories[i].numTransactions = 0;
  }

  // Add the transaction to the category
  strcpy(categories[i].transactions[categories[i].numTransactions].name, name);
  categories[i].transactions[categories[i].numTransactions].amount = amount;
  categories[i].numTransactions++;
}

// Function to add a budget
void addBudget(char *name, int budget) {
  // Find the budget
  int i;
  for (i = 0; i < numBudgets; i++) {
    if (strcmp(budgets[i].name, name) == 0) {
      break;
    }
  }

  // If the budget does not exist, create it
  if (i == numBudgets) {
    strcpy(budgets[i].name, name);
    budgets[i].budget = budget;
  }

  // Add the budget to the list of budgets
  numBudgets++;
}

// Function to print the transactions
void printTransactions() {
  // Loop through the categories
  int i;
  for (i = 0; i < numCategories; i++) {
    // Print the category name
    printf("%s\n", categories[i].name);

    // Loop through the transactions
    int j;
    for (j = 0; j < categories[i].numTransactions; j++) {
      // Print the transaction details
      printf(" - %s: %d\n", categories[i].transactions[j].name, categories[i].transactions[j].amount);
    }
  }
}

// Function to print the budgets
void printBudgets() {
  // Loop through the budgets
  int i;
  for (i = 0; i < numBudgets; i++) {
    // Print the budget details
    printf(" - %s: %d\n", budgets[i].name, budgets[i].budget);
  }
}