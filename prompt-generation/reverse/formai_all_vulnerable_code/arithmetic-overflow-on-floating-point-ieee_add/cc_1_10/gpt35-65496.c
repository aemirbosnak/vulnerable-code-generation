//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Declare variables for user input
  float income, rent, utilities, groceries, entertainment, savings;
  int months;

  // Retrieve user input for monthly expenses
  printf("Enter your monthly income: $");
  scanf("%f", &income);
  printf("Enter your monthly rent: $");
  scanf("%f", &rent);
  printf("Enter your monthly utilities: $");
  scanf("%f", &utilities);
  printf("Enter your monthly groceries: $");
  scanf("%f", &groceries);
  printf("Enter your monthly entertainment expenses: $");
  scanf("%f", &entertainment);
  printf("Enter how many months you want to plan: ");
  scanf("%d", &months);
  printf("Enter your monthly savings goal: $");
  scanf("%f", &savings);

  // Calculate total monthly expenses and savings
  float totalExpenses = rent + utilities + groceries + entertainment;
  float monthlySavings = savings / months;
  float totalSavings = monthlySavings * months;

  // Print out results
  printf("\n");
  printf("Monthly Budget Plan:\n");
  printf("=====================\n");
  printf("Monthly Income:\t\t$%.2f\n", income);
  printf("Monthly Rent:\t\t$%.2f\n", rent);
  printf("Monthly Utilities:\t$%.2f\n", utilities);
  printf("Monthly Groceries:\t$%.2f\n", groceries);
  printf("Monthly Entertainment:\t$%.2f\n", entertainment);
  printf("---------------------\n");
  printf("Total Monthly Expenses:\t$%.2f\n", totalExpenses);
  printf("Monthly Savings Goal:\t$%.2f\n", monthlySavings);
  printf("---------------------\n");
  printf("Total Savings Goal:\t$%.2f over %d months\n", totalSavings, months);
  printf("=====================\n");

  // Determine if savings goal is achievable
  if (income - totalExpenses < monthlySavings) {
    printf("\n");
    printf("WARNING: Your monthly savings goal is not achievable with your current monthly income and expenses.\n");
  }

  return 0;
}