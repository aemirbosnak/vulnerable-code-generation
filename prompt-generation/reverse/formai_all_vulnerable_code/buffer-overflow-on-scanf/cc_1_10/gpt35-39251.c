//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum length of the expense category and item name
#define MAX_LENGTH 20

// Struct to store expense details
struct Expense {
  char category[MAX_LENGTH];
  char itemName[MAX_LENGTH];
  double amount;
};

// Function to print the expense report
void printReport(struct Expense* expenses, int numExpenses) {
  printf("\nExpense Report:\n");

  // Initializing total amount to 0
  double total = 0.0;

  // Looping through each expense and printing its details
  for (int i = 0; i < numExpenses; i++) {
    printf("Category: %s\n", expenses[i].category);
    printf("Item: %s\n", expenses[i].itemName);
    printf("Amount: %.2lf\n\n", expenses[i].amount);

    // Adding the current expense amount to the total amount
    total += expenses[i].amount;
  }

  // Printing the total expense amount
  printf("Total Expense: %.2lf\n", total);
}

int main() {
  // Initializing the maximum number of expenses to 10
  int MAX_EXPENSES = 10;

  // Initializing the array of expenses to the maximum number of expenses
  struct Expense expenses[MAX_EXPENSES];

  // Initializing the number of expenses to 0
  int numExpenses = 0;

  // Initializing the choice variable
  int choice;

  // Looping through the menu of options till the user chooses to exit
  while (1) {
    printf("\nEnter your choice:\n");
    printf("1. Add Expense\n");
    printf("2. Print Expense Report\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Checking if the maximum number of expenses limit has been reached
        if (numExpenses == MAX_EXPENSES) {
          printf("Maximum number of expenses reached!\n");
          continue;
        }

        // Reading the category, item name, and amount of the expense from the user
        printf("\nEnter Expense Category: ");
        scanf("%s", expenses[numExpenses].category);
        printf("Enter Expense Item Name: ");
        scanf("%s", expenses[numExpenses].itemName);
        printf("Enter Expense Amount: ");
        scanf("%lf", &expenses[numExpenses].amount);

        // Incrementing the number of expenses
        numExpenses++;

        printf("Expense Added!\n");

        break;

      case 2:
        // Checking if any expenses have been added
        if (numExpenses == 0) {
          printf("No Expenses Found!\n");
          continue;
        }

        // Printing the expense report
        printReport(expenses, numExpenses);

        break;

      case 3:
        // Exiting the program
        printf("Exiting Expense Tracker!\n");
        exit(0);

      default:
        printf("Invalid Choice!\n");
    }
  }

  return 0;
}