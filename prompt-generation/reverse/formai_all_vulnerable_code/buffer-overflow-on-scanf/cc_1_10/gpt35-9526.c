//FormAI DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

// Define constants for maximum length of expense name and number of expenses
#define MAX_NAME_LENGTH 20
#define MAX_EXPENSES 10

struct Expense {
  char name[MAX_NAME_LENGTH];
  double amount;
};

int main() {
  printf("Welcome to the Expense Tracker program\n\n");

  // Initialize variables
  int num_expenses = 0;
  double total_spending = 0.0;
  struct Expense expenses[MAX_EXPENSES];

  while (true) {
    printf("Enter expense name (or 'done' to stop adding): ");
    char input_name[MAX_NAME_LENGTH];
    scanf("%19s", input_name); // Read at most 19 characters to prevent buffer overflow

    if (strcmp(input_name, "done") == 0) {
      break; // Exit loop if input is "done"
    }

    double input_amount;
    printf("Enter amount: $");
    scanf("%lf", &input_amount);

    // Add new expense to array of expenses
    struct Expense new_expense;
    strcpy(new_expense.name, input_name);
    new_expense.amount = input_amount;
    expenses[num_expenses] = new_expense;

    // Increment number of expenses and add to total spending
    num_expenses++;
    total_spending += input_amount;

    printf("Added expense: %s - $%.2lf\n\n", input_name, input_amount);
  }

  // Print summary of expenses
  printf("\nExpense Summary\n");
  printf("---------------------------------------------\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("%-20s $ %.2lf\n", expenses[i].name, expenses[i].amount);
  }
  printf("---------------------------------------------\n");
  printf("Total:              $ %.2lf\n", total_spending);

  return 0;
}