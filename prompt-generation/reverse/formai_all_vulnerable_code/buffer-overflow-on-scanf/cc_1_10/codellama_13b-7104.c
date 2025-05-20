//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: brave
// Personal Finance Planner in C

#include <stdio.h>
#include <stdlib.h>

// Define struct to store user inputs
struct FinancePlan {
  char name[50];
  float income;
  float expenses[10];
  float savings[10];
  int num_expenses;
  int num_savings;
};

// Function to print the financial plan
void printFinancialPlan(struct FinancePlan plan) {
  printf("Name: %s\n", plan.name);
  printf("Income: %.2f\n", plan.income);
  printf("Expenses:\n");
  for (int i = 0; i < plan.num_expenses; i++) {
    printf("%d. %s: %.2f\n", i + 1, plan.expenses[i]);
  }
  printf("Savings:\n");
  for (int i = 0; i < plan.num_savings; i++) {
    printf("%d. %s: %.2f\n", i + 1, plan.savings[i]);
  }
}

// Main function
int main() {
  struct FinancePlan plan;

  // Get user input for name and income
  printf("Enter your name: ");
  scanf("%s", plan.name);
  printf("Enter your income: ");
  scanf("%f", &plan.income);

  // Get user input for expenses
  printf("Enter the number of expenses: ");
  scanf("%d", &plan.num_expenses);
  for (int i = 0; i < plan.num_expenses; i++) {
    printf("Enter expense %d: ", i + 1);
    scanf("%f", &plan.expenses[i]);
  }

  // Get user input for savings
  printf("Enter the number of savings: ");
  scanf("%d", &plan.num_savings);
  for (int i = 0; i < plan.num_savings; i++) {
    printf("Enter savings %d: ", i + 1);
    scanf("%f", &plan.savings[i]);
  }

  // Print the financial plan
  printFinancialPlan(plan);

  return 0;
}