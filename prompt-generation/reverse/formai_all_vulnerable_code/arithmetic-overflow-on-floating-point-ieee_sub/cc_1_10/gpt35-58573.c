//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>

int main() {
  float monthly_income, rent, groceries, utilities, savings_goal;
  int months;

  printf("Welcome to the Personal Finance Planner!\n\n");

  // Get user input
  printf("Please enter your monthly income: ");
  scanf("%f", &monthly_income);

  printf("Please enter your monthly rent/mortgage payment: ");
  scanf("%f", &rent);

  printf("Please enter your monthly grocery budget: ");
  scanf("%f", &groceries);

  printf("Please enter your monthly utilities budget: ");
  scanf("%f", &utilities);

  printf("Please enter your savings goal per month: ");
  scanf("%f", &savings_goal);

  printf("Please enter the number of months you want to plan for: ");
  scanf("%d", &months);

  // Calculate and print monthly budget breakdown
  float monthly_expenses = rent + groceries + utilities;
  float monthly_savings = savings_goal;
  float monthly_remaining = monthly_income - monthly_expenses - monthly_savings;

  printf("\n--------------------------------------------\n");
  printf("Monthly Budget Breakdown\n");
  printf("--------------------------------------------\n");
  printf("Income: $%.2f\n", monthly_income);
  printf("Expenses: $%.2f\n", monthly_expenses);
  printf("Savings: $%.2f\n", monthly_savings);
  printf("Remaining: $%.2f\n\n", monthly_remaining);

  // Calculate and print total budget breakdown
  float total_income = monthly_income * months;
  float total_expenses = monthly_expenses * months;
  float total_savings = monthly_savings * months;
  float total_remaining = total_income - total_expenses - total_savings;

  printf("--------------------------------------------\n");
  printf("Total Budget Breakdown for %d Months\n", months);
  printf("--------------------------------------------\n");
  printf("Total Income: $%.2f\n", total_income);
  printf("Total Expenses: $%.2f\n", total_expenses);
  printf("Total Savings: $%.2f\n", total_savings);
  printf("Total Remaining: $%.2f\n", total_remaining);

  printf("\nThank you for using the Personal Finance Planner! Good luck with your savings goals!\n");

  return 0;
}