//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define constants for tax rates and retirement contribution limits
#define TAX_RATE_10 0.10
#define TAX_RATE_12 0.12
#define TAX_RATE_22 0.22
#define TAX_RATE_24 0.24
#define TAX_RATE_32 0.32
#define TAX_RATE_35 0.35
#define TAX_RATE_37 0.37
#define RETIREMENT_CONTRIBUTION_LIMIT 19500

// Define struct for a monthly budget item
typedef struct {
  char name[50];
  double amount;
} budget_item;

int main() {
  // Define variables for income, tax rate, retirement contribution, and budget items
  double income, tax_rate, retirement_contribution;
  budget_item budget[12];

  // Get the user's income
  printf("Enter your annual income: $");
  scanf("%lf", &income);

  // Calculate the user's tax rate based on their income
  if (income <= 9875) {
    tax_rate = TAX_RATE_10;
  } else if (income <= 40125) {
    tax_rate = TAX_RATE_12;
  } else if (income <= 85525) {
    tax_rate = TAX_RATE_22;
  } else if (income <= 163300) {
    tax_rate = TAX_RATE_24;
  } else if (income <= 207350) {
    tax_rate = TAX_RATE_32;
  } else if (income <= 518400) {
    tax_rate = TAX_RATE_35;
  } else {
    tax_rate = TAX_RATE_37;
  }

  // Calculate the user's retirement contribution based on their income
  retirement_contribution = (income * 0.15 > RETIREMENT_CONTRIBUTION_LIMIT) ? RETIREMENT_CONTRIBUTION_LIMIT : income * 0.15;

  // Get the user's monthly budget items
  printf("Enter your monthly budget items:\n");
  for (int i = 0; i < 12; i++) {
    printf("%d. Name: ", i + 1);
    scanf("%s", budget[i].name);
    printf("   Amount: $");
    scanf("%lf", &budget[i].amount);
  }

  // Calculate total budget and output it to the user
  double total_budget = 0;
  for (int i = 0; i < 12; i++) {
    total_budget += budget[i].amount;
  }
  printf("Your total monthly budget is: $%.2lf\n", total_budget);

  // Calculate taxes and net income and output them to the user
  double taxes = income * tax_rate;
  double net_income = income - taxes - retirement_contribution;
  printf("Your annual taxes are: $%.2lf\n", taxes);
  printf("Your annual net income after taxes and retirement contribution is: $%.2lf\n", net_income);

  return 0;
}