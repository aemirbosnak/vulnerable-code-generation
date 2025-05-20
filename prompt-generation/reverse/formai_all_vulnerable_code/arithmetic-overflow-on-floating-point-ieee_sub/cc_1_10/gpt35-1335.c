//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {

  float starting_salary, expenses, investments, savings, total_saved, total_invested, total_spent, temp_savings, temp_investments, temp_expenses, total_expenses;
  int years, months, i;

  printf("Welcome to the Personal Finance Planner!\n\n");

  printf("Please enter your starting salary (per month): ");
  scanf("%f", &starting_salary);

  printf("\nHow many years do you plan to stay on this salary? ");
  scanf("%d", &years);

  printf("\nHow many months in a year will you have this salary? ");
  scanf("%d", &months);

  total_saved = 0;
  total_invested = 0;
  total_spent = 0;

  for(i=1; i<=years*months; i++) {

    printf("\nMonth %d\n", i);

    printf("How much do you plan to invest this month? ");
    scanf("%f", &investments);
    total_invested += investments;
    temp_investments = investments;

    printf("How much do you plan to save this month? ");
    scanf("%f", &savings);
    total_saved += savings;
    temp_savings = savings;

    expenses = starting_salary - savings - investments;
    total_expenses += expenses;
    temp_expenses = expenses;

    printf("Expenses this month: %.2f\n", expenses);
    printf("Total expenses so far: %.2f\n", total_expenses);

    printf("Savings this month: %.2f\n", savings);
    printf("Total savings so far: %.2f\n", total_saved);

    printf("Investments this month: %.2f\n", investments);
    printf("Total investments so far: %.2f\n", total_invested);

    printf("Money left over this month: %.2f\n\n", starting_salary - expenses);

    starting_salary += starting_salary * 0.1 / 12;

  }

  printf("\n\nAfter %d years and %d months, here is your financial status: \n", years, months);

  printf("\nTotal money spent: %.2f\n", total_expenses);
  printf("Total money saved: %.2f\n", total_saved);
  printf("Total money invested: %.2f\n", total_invested);

  return 0;
}