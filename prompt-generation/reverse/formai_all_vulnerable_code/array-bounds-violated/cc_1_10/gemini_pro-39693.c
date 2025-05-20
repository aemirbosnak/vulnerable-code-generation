//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the expense structure
typedef struct {
  char description[100];
  float amount;
  int category;
} Expense;

// Define the category names
char *category_names[] = {"Food", "Entertainment", "Transportation", "Other"};

// Define the main function
int main() {
  // Initialize the expenses array
  Expense expenses[MAX_EXPENSES];

  // Get the number of expenses from the user
  int num_expenses;
  printf("Enter the number of expenses: ");
  scanf("%d", &num_expenses);

  // Get the expenses from the user
  for (int i = 0; i < num_expenses; i++) {
    printf("Enter the description of expense %d: ", i + 1);
    scanf("%s", expenses[i].description);

    printf("Enter the amount of expense %d: ", i + 1);
    scanf("%f", &expenses[i].amount);

    printf("Enter the category of expense %d: ", i + 1);
    scanf("%d", &expenses[i].category);
  }

  // Calculate the total expenses
  float total_expenses = 0;
  for (int i = 0; i < num_expenses; i++) {
    total_expenses += expenses[i].amount;
  }

  // Calculate the average expenses
  float average_expenses = total_expenses / num_expenses;

  // Calculate the median expenses
  float median_expenses;
  if (num_expenses % 2 == 0) {
    median_expenses = (expenses[num_expenses / 2].amount + expenses[num_expenses / 2 - 1].amount) / 2;
  } else {
    median_expenses = expenses[num_expenses / 2].amount;
  }

  // Calculate the mode expenses
  int mode_expenses[4] = {0, 0, 0, 0};
  for (int i = 0; i < num_expenses; i++) {
    mode_expenses[expenses[i].category]++;
  }
  int max_count = 0;
  int mode_category;
  for (int i = 0; i < 4; i++) {
    if (mode_expenses[i] > max_count) {
      max_count = mode_expenses[i];
      mode_category = i;
    }
  }

  // Print the expense report
  printf("\nExpense Report\n");
  printf("--------------------\n");
  printf("Total expenses: $%.2f\n", total_expenses);
  printf("Average expenses: $%.2f\n", average_expenses);
  printf("Median expenses: $%.2f\n", median_expenses);
  printf("Mode expenses: %s\n", category_names[mode_category]);

  return 0;
}