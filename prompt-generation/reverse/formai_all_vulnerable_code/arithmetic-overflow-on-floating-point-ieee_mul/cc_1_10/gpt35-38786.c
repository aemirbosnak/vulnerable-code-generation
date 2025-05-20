//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>

int main() {
  // set starting values
  float income = 0;
  float expenses = 0;
  float savings_goal = 0;
  float current_savings = 0;

  // get user inputs for income, expenses, and savings goal
  printf("Welcome to the Personal Finance Planner\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &income);
  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);
  printf("Please enter your desired savings goal: ");
  scanf("%f", &savings_goal);

  // calculate initial savings rate
  float savings_rate = (income - expenses) / income;

  // print initial personal finance report
  printf("\nPersonal Finance Report\n");
  printf("Monthly Income: $%.2f\n", income);
  printf("Monthly Expenses: $%.2f\n", expenses);
  printf("Monthly Savings: $%.2f\n", income - expenses);
  printf("Savings Rate: %.2f%%\n", savings_rate * 100);
  printf("Current Savings: $%.2f\n", current_savings);

  // calculate months to reach savings goal
  int months_to_goal = savings_goal / (income - expenses);

  // loop through each month, updating savings and displaying report
  for (int month = 1; month <= months_to_goal; month++) {
    current_savings += income - expenses;
    savings_rate = current_savings / income;

    printf("\nPersonal Finance Report (Month %d)\n", month);
    printf("Monthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%.2f\n", expenses);
    printf("Monthly Savings: $%.2f\n", income - expenses);
    printf("Savings Rate: %.2f%%\n", savings_rate * 100);
    printf("Current Savings: $%.2f\n", current_savings);

    // check if savings goal has been reached
    if (current_savings >= savings_goal) {
      break;
    }
  }

  // print final personal finance report
  printf("\nPersonal Finance Report (Final)\n");
  printf("Monthly Income: $%.2f\n", income);
  printf("Monthly Expenses: $%.2f\n", expenses);
  printf("Monthly Savings: $%.2f\n", income - expenses);
  printf("Savings Rate: %.2f%%\n", savings_rate * 100);
  printf("Current Savings: $%.2f\n", current_savings);

  // check if savings goal was reached
  if (current_savings >= savings_goal) {
    printf("Congratulations! You have reached your savings goal!\n");
  } else {
    printf("Sorry, you did not reach your savings goal after %d months.\n", months_to_goal);
  }

  return 0;
}