//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include<stdio.h> 
#include<string.h>

#define MAX_EXPENSES 1000 // Maximum number of expenses

// Struct to store individual expense information
struct Expense {
  char name[50]; // Name of person who made the expense
  float amount; // Expense amount
  char description[200]; // Description of the expense
};

// Struct to store all expenses made
struct ExpenseManager {
  struct Expense expenses[MAX_EXPENSES]; // Array of expenses made
  int numExpenses; // Total number of expenses
  float totalAmount; // Total amount spent
  float avgAmount; // Average amount spent per expense
};

// Function to add a new expense
void addExpense(struct ExpenseManager *expenseManager) {
  printf("Enter the name of the person who made the expense: ");
  scanf("%s", expenseManager->expenses[expenseManager->numExpenses].name);

  printf("Enter the amount of the expense: ");
  scanf("%f", &expenseManager->expenses[expenseManager->numExpenses].amount);

  printf("Enter a description for the expense: ");
  scanf("%s", expenseManager->expenses[expenseManager->numExpenses].description);

  // Update total amount and average amount spent
  expenseManager->totalAmount += expenseManager->expenses[expenseManager->numExpenses].amount; 
  expenseManager->avgAmount = expenseManager->totalAmount / (float)expenseManager->numExpenses;

  printf("Expense added successfully!\n");
  expenseManager->numExpenses++; // Increment total number of expenses
}

// Function to view all expenses made
void viewExpenses(struct ExpenseManager *expenseManager) {
  printf("Total number of expenses: %d\n", expenseManager->numExpenses);
  
  for(int i=0; i<expenseManager->numExpenses; i++) {
    printf("Name: %s\n", expenseManager->expenses[i].name);
    printf("Amount: %.2f\n", expenseManager->expenses[i].amount);
    printf("Description: %s\n", expenseManager->expenses[i].description);
    printf("\n");
  }

  printf("Total amount spent: %.2f\n", expenseManager->totalAmount);
  printf("Average amount spent per expense: %.2f\n", expenseManager->avgAmount);
}

// Main function to run the program
int main() {
  struct ExpenseManager expenseManager;
  expenseManager.numExpenses = 0;
  expenseManager.totalAmount = 0.0;
  expenseManager.avgAmount = 0.0;

  int choice;
  while(1) {
    printf("1. Add expense\n2. View expenses\n3. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addExpense(&expenseManager);
        break;

      case 2:
        viewExpenses(&expenseManager);
        break;

      case 3:
        printf("Exiting program...\n");
        return 0;

      default:
        printf("Invalid choice. Please try again.\n");
    }

    printf("\n");
  }

  return 0;
}