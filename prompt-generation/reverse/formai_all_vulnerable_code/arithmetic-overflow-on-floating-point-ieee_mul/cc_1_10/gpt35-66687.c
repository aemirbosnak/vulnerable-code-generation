//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>

// Function to calculate net income
float calculateNetIncome(float gross_income, float taxes) {
  return gross_income - taxes;
}

// Function to calculate absolute difference
float calculateDifference(float x, float y) {
  if (x > y) {
    return x - y;
  } else {
    return y - x;
  }
}

int main() {

  // Declare variables
  float gross_income, taxes, net_income, rent, groceries, utilities, other_expenses, total_expenses;
  int savings_rate;

  // Get input values
  printf("Enter your gross income: ");
  scanf("%f", &gross_income);

  printf("Enter your taxes: ");
  scanf("%f", &taxes);

  printf("Enter your monthly rent: ");
  scanf("%f", &rent);

  printf("Enter your monthly groceries: ");
  scanf("%f", &groceries);

  printf("Enter your monthly utilities: ");
  scanf("%f", &utilities);

  printf("Enter your other monthly expenses: ");
  scanf("%f", &other_expenses);

  printf("Enter your desired savings rate (percentage): ");
  scanf("%d", &savings_rate);

  // Calculate net income and total expenses
  net_income = calculateNetIncome(gross_income, taxes);
  total_expenses = rent + groceries + utilities + other_expenses;

  // Calculate savings and discretionary spending
  float savings_amount = net_income * savings_rate / 100;
  float discretionary_spending = calculateDifference(net_income - savings_amount, total_expenses);

  // Print results
  printf("\n----------- Personal Finance Planner -----------\n");
  printf("Net Income: $%.2f\n", net_income);
  printf("Total Expenses: $%.2f\n", total_expenses);
  printf("Savings Amount: $%.2f (with a savings rate of %d%%)\n", savings_amount, savings_rate);
  printf("Discretionary Spending: $%.2f\n", discretionary_spending);

  return 0;
}