//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>

int main() {
  float income, expenses, savings_goal, savings = 0;
  int months_left;

  printf("Welcome to the Personal Finance Planner!\n\n");

  printf("Please enter your monthly income: ");
  scanf("%f", &income);

  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);

  printf("Please enter your savings goal: ");
  scanf("%f", &savings_goal);

  printf("How many months do you have left to achieve your savings goal? ");
  scanf("%d", &months_left);

  // Calculate monthly savings required to reach goal
  float monthly_savings_required = (savings_goal - savings) / months_left;

  if (monthly_savings_required < 0) {
    printf("\nCongratulations! You have already exceeded your savings goal.");
    return 0;
  }

  printf("\nGreat! Based on your inputs, you need to save %.2f per month to reach your goal.\n", monthly_savings_required);

  int month = 1;

  while (month <= months_left) {
    printf("\nMonth %d:\n", month);

    printf("\tIncome: %.2f\n", income);
    printf("\tExpenses: %.2f\n", expenses);
    
    float savings_this_month = income - expenses;

    if (savings_this_month > 0) {
      printf("\tSavings: %.2f\n", savings_this_month);
      savings += savings_this_month;
    } else {
      printf("\tDeficit: %.2f\n", savings_this_month);
    }

    printf("\tTotal savings so far: %.2f\n", savings);

    month++;
  }

  if (savings < savings_goal) {
    printf("\nUh oh, it looks like you did not reach your savings goal. Keep working at it!");
  } else {
    printf("\nCongratulations! You have reached or exceeded your savings goal. Well done!");
  }

  return 0;
}