//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>

int main() {
  float income, expenses;
  float savings, total;

  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  savings = income - expenses;

  printf("\nSavings: $%.2f\n", savings);

  printf("\nMonthly Budget Overview\n");
  printf("------------------------\n");
  printf("Income: $%.2f\n", income);
  printf("Expenses: $%.2f\n", expenses);
  printf("Savings: $%.2f\n", savings);

  printf("\nAnnual Budget Overview\n");
  printf("----------------------\n");
  printf("Income: $%.2f\n", income * 12);
  printf("Expenses: $%.2f\n", expenses * 12);
  printf("Savings: $%.2f\n", savings * 12);

  printf("\nInvestment Plan\n");
  printf("----------------\n");

  printf("Enter the amount you wish to invest: ");
  float amount;
  scanf("%f", &amount);

  printf("Enter the number of years you wish to invest: ");
  int noOfYears;
  scanf("%d", &noOfYears);

  printf("Enter the expected rate of return (in percentage): ");
  float rateOfReturn;
  scanf("%f", &rateOfReturn);

  rateOfReturn /= 100;

  total = amount * (1 + rateOfReturn) * noOfYears;

  printf("\nTotal Value after %d years: $%.2f\n", noOfYears, total);

  return 0;
}