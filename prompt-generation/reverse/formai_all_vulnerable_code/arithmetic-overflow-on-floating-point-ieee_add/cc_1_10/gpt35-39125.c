//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>

float monthly_salary, rent, utilities, food, transportation, insurance, other_expenses;
float total_expenses, savings, emergency_fund, investments, debt;

int main() {
  printf("Welcome to your Personal Finance Planner!\n\n");

  printf("Enter your monthly salary: $");
  scanf("%f", &monthly_salary);

  printf("\nEnter your monthly rent: $");
  scanf("%f", &rent);

  printf("\nEnter your monthly utilities bill: $");
  scanf("%f", &utilities);

  printf("\nEnter your monthly food expenses: $");
  scanf("%f", &food);

  printf("\nEnter your monthly transportation expenses: $");
  scanf("%f", &transportation);

  printf("\nEnter your monthly insurance costs: $");
  scanf("%f", &insurance);

  printf("\nEnter any other monthly expenses: $");
  scanf("%f", &other_expenses);

  total_expenses = rent + utilities + food + transportation + insurance + other_expenses;

  printf("\n\nYour total monthly expenses are: $%.2f", total_expenses);

  savings = 0.5 * monthly_salary;
  emergency_fund = 3 * total_expenses;
  investments = 0.2 * monthly_salary;
  debt = 0.3 * monthly_salary;

  printf("\n\nBased on your monthly salary of $%.2f, here are our recommended allocations:\n", monthly_salary);

  printf("\nSavings: $%.2f (minimum of 50%% of your monthly salary)\n", savings);

  printf("\nEmergency Fund: $%.2f (minimum of 3 months' worth of expenses)\n", emergency_fund);

  printf("\nInvestments: $%.2f (minimum of 20%% of your monthly salary)\n", investments);

  printf("\nDebt Repayment: $%.2f (maximum of 30%% of your monthly salary)\n", debt);

  return 0;
}