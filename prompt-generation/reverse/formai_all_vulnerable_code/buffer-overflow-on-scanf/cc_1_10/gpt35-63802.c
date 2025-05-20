//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income, tax, social_security, medicare, total_tax, net_income;
  float rent, utilities, food, transportation, entertainment, total_expenses;
  float savings, remaining_budget;

  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &income);

  // Calculate taxes
  tax = income * 0.2;
  social_security = income * 0.062;
  medicare = income * 0.0145;
  total_tax = tax + social_security + medicare;
  net_income = income - total_tax;

  printf("Your total tax for this month is: $%.2f\n", total_tax);
  printf("Your net income for this month is: $%.2f\n", net_income);

  // Calculate expenses
  printf("Now let's calculate your monthly expenses.\n");
  printf("Enter your monthly rent: ");
  scanf("%f", &rent);

  printf("Enter your monthly utilities: ");
  scanf("%f", &utilities);

  printf("Enter your monthly food expenses: ");
  scanf("%f", &food);

  printf("Enter your monthly transportation expenses: ");
  scanf("%f", &transportation);

  printf("Enter your monthly entertainment expenses: ");
  scanf("%f", &entertainment);

  total_expenses = rent + utilities + food + transportation + entertainment;
  printf("Your total expenses for this month is: $%.2f\n", total_expenses);

  // Calculate remaining budget
  savings = net_income * 0.2;
  remaining_budget = net_income - total_expenses - savings;

  printf("You should save: $%.2f\n", savings);

  if (remaining_budget > 0) {
    printf("You have $%.2f remaining for other expenses this month.\n", remaining_budget);
  }
  else if (remaining_budget == 0) {
    printf("You have no remaining budget for other expenses this month.\n");
  }
  else {
    printf("You are over your budget by $%.2f this month.\n", remaining_budget * -1);
  }

  return 0;
}