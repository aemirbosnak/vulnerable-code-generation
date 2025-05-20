//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int num_expenses = 0;
  double total_amount = 0.0;
  double average_amount = 0.0;
  double min_amount = 0.0;
  double max_amount = 0.0;
  char user_input[20];

  // Prompt user to enter the total number of expenses
  printf("Enter the total number of expenses: ");
  scanf("%d", &num_expenses);

  // Prompt user to enter the amount of each expense
  for (int i = 1; i <= num_expenses; i++) {
    printf("Enter the amount of expense #%d: ", i);
    scanf("%s", user_input);
    total_amount += atof(user_input);
  }

  // Calculate average amount of expenses
  average_amount = total_amount / num_expenses;

  // Find minimum and maximum amounts of expenses
  for (int i = 1; i <= num_expenses; i++) {
    if (total_amount < atof(user_input)) {
      min_amount = atof(user_input);
    }
    if (total_amount > atof(user_input)) {
      max_amount = atof(user_input);
    }
  }

  // Display total amount of expenses
  printf("Total amount of expenses: %.2f\n", total_amount);

  // Display average amount of expenses
  printf("Average amount of expenses: %.2f\n", average_amount);

  // Display minimum and maximum amounts of expenses
  printf("Minimum amount of expenses: %.2f\n", min_amount);
  printf("Maximum amount of expenses: %.2f\n", max_amount);

  // Display highest and lowest amounts of expenses
  printf("Highest amount of expenses: %.2f\n", max_amount);
  printf("Lowest amount of expenses: %.2f\n", min_amount);

  // Ask user if they want to continue
  printf("Do you want to continue? (Y/N): ");
  char user_input2[20];
  scanf("%s", user_input2);

  // End program if user doesn't want to continue
  if (strcmp(user_input2, "N") == 0 || strcmp(user_input2, "n") == 0) {
    printf("End of program.\n");
    return 0;
  }

  // Repeat process if user wants to continue
  return 0;
}