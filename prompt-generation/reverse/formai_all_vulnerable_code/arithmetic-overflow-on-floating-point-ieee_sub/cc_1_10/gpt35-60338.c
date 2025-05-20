//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
// Welcome to the Personal Finance Planner!
// With this program, you'll be able to keep track of your spending and saving habits.

#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library
#include <string.h> // String library

int main() {
  // First, let's set some variables to store our income and expenses
  float income = 0.0;
  float expenses = 0.0;
  float savings = 0.0;

  // Next, we'll prompt the user to input their income and expenses
  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  // Let's calculate the difference between the user's income and expenses
  savings = income - expenses;

  // If the user's expenses are greater than their income...
  if (savings < 0) {
    float difference = expenses - income;
    printf("Uh oh! You're spending $%.2f more than you're making each month.", difference);
    printf("Let's make a plan to get you back on track.\n");

    // Ask the user if they're willing to cut back on their expenses
    char response[3];
    printf("Are you willing to cut back on your expenses? (yes/no): ");
    scanf("%s", response);

    // If the user is willing to cut back on their expenses...
    if (strcmp(response, "yes") == 0) {
      printf("Great! Let's see how we can reduce your expenses.\n");

      // Ask the user which expenses they're willing to cut back on
      char option[10];
      printf("What expense would you like to cut back on? (utilities/groceries/entertainment): ");
      scanf("%s", option);

      // Calculate the new expenses
      if (strcmp(option, "utilities") == 0) {
        expenses -= 50.0;
      } else if (strcmp(option, "groceries") == 0) {
        expenses -= 100.0;
      } else if (strcmp(option, "entertainment") == 0) {
        expenses -= 75.0;
      } else {
        printf("Sorry, I didn't understand that option. Please try again.\n");
        exit(0);
      }

      printf("Great! Your new monthly expenses are $%.2f.\n", expenses);

      // Calculate the new savings after cutting back on expenses
      savings = income - expenses;

      printf("Your monthly savings are now $%.2f.\n", savings);
    } else {
      printf("No problem. Let's find another way to increase your savings.\n");
    }
  } else {
    // If the user is spending less than they're making...
    printf("Congratulations! You are spending within your means and saving $%.2f each month.\n", savings);
  }

  // Finally, let's show the user how much they'll be saving over the next year
  float yearly_savings = savings * 12;
  printf("Over the next year, you'll save $%.2f!\n", yearly_savings);

  return 0;
}