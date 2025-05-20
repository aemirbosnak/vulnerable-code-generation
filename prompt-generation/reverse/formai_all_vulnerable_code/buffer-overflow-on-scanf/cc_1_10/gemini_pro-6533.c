//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Macros for menu options
#define ADD_INCOME 1
#define ADD_EXPENSE 2
#define VIEW_BALANCE 3
#define EXIT 4

// Function to add income
void add_income(float *balance) {
  float amount;
  printf("Enter amount: ");
  scanf("%f", &amount);
  *balance += amount;
  printf("Income added successfully!\n");
}

// Function to add expense
void add_expense(float *balance) {
  float amount;
  printf("Enter amount: ");
  scanf("%f", &amount);
  *balance -= amount;
  printf("Expense added successfully!\n");
}

// Function to view balance
void view_balance(float balance) {
  printf("Your balance is: %.2f\n", balance);
}

// Main function
int main() {
  // Initialize balance to 0
  float balance = 0;

  // Display menu
  printf("Welcome to your Personal Finance Planner!\n");
  printf("1. Add Income\n");
  printf("2. Add Expense\n");
  printf("3. View Balance\n");
  printf("4. Exit\n");

  // Get user input
  int option;
  do {
    printf("Enter your choice: ");
    scanf("%d", &option);

    // Perform action based on user choice
    switch (option) {
      case ADD_INCOME:
        add_income(&balance);
        break;
      case ADD_EXPENSE:
        add_expense(&balance);
        break;
      case VIEW_BALANCE:
        view_balance(balance);
        break;
      case EXIT:
        printf("Thank you for using the Personal Finance Planner. Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please enter a valid option (1-4).\n");
    }
  } while (option != EXIT);

  return 0;
}