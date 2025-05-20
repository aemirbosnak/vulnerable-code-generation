//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main() {
  // Initialize variables
  int choice;
  double income, expense, balance, totalIncome = 0, totalExpense = 0;

  // Welcome message
  printf("Welcome to the Personal Finance Planner!\n");

  // Menu loop
  while (1) {
    // Display menu
    printf("\n");
    printf("1. Enter Income\n");
    printf("2. Enter Expense\n");
    printf("3. View Income Statement\n");
    printf("4. View Expense Statement\n");
    printf("5. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    // Perform action based on user choice
    switch (choice) {
      case 1:
        // Enter income
        printf("Enter your income: ");
        scanf("%lf", &income);
        totalIncome += income;
        printf("Income added successfully!\n");
        break;
      case 2:
        // Enter expense
        printf("Enter your expense: ");
        scanf("%lf", &expense);
        totalExpense += expense;
        printf("Expense added successfully!\n");
        break;
      case 3:
        // View income statement
        printf("\n");
        printf("Income Statement\n");
        printf("================\n");
        printf("Total Income: $%.2lf\n", totalIncome);
        printf("Expenses: $%.2lf\n", totalExpense);
        printf("Net Income: $%.2lf\n", totalIncome - totalExpense);
        printf("\n");
        break;
      case 4:
        // View expense statement
        printf("\n");
        printf("Expense Statement\n");
        printf("================\n");
        printf("Total Expenses: $%.2lf\n", totalExpense);
        printf("\n");
        break;
      case 5:
        // Exit program
        printf("Thank you for using the Personal Finance Planner!\n");
        exit(0);
      default:
        // Invalid choice
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}