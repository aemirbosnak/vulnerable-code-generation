//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define variables
  float salary, expenses, savings, weekly_expenses, investment_return;
  int years_saved;
  char option;

  // Prompt user for input values
  printf("Enter your annual salary: $");
  scanf("%f", &salary);

  printf("Enter your monthly expenses: $");
  scanf("%f", &expenses);

  printf("Enter the number of years you plan to save: ");
  scanf("%d", &years_saved);

  printf("Enter the expected return on your investments (as a percentage): ");
  scanf("%f", &investment_return);

  // Calculate and display results
  savings = salary - expenses;
  weekly_expenses = expenses / 4;
  float investment_return_decimal = investment_return / 100;
  float total_savings = savings * years_saved;
  float total_investment_return = total_savings * investment_return_decimal;

  printf("\n\n");
  printf("******************************\n");
  printf("    PERSONAL FINANCE PLANNER   \n");
  printf("******************************\n");
  printf("\n");

  printf("Total savings: $%.2f\n", total_savings);
  printf("Total investment return: $%.2f\n", total_investment_return);
  printf("Total savings + return: $%.2f\n", total_savings + total_investment_return);
  printf("\n");
  printf("Weekly expenses: $%.2f\n", weekly_expenses);
  printf("\n");
  printf("Would you like to see a breakdown of your savings per year? (y/n)\n");
  scanf("%s", &option);

  if (option == 'y' || option == 'Y') {
    printf("\n");
    printf("******************************\n");
    printf("      SAVING BREAKDOWN        \n");
    printf("******************************\n");
    printf("\n");

    for (int i = 1; i <= years_saved; i++) {
      printf("Year %d: $%.2f\n", i, savings * i * 12);
    }
  }

  return 0;
}