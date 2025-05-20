//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
   int i, j, num_months;
   float monthly_income, monthly_expenses, spending_limit;
   float total_income = 0, total_expenses = 0, total_savings = 0;

   // get user input
   printf("Enter your monthly income: ");
   scanf("%f", &monthly_income);
   printf("Enter your monthly expenses: ");
   scanf("%f", &monthly_expenses);
   printf("Enter the number of months you want to plan: ");
   scanf("%d", &num_months);

   // calculate spending limit based on income and expenses
   spending_limit = (monthly_income - monthly_expenses) * 0.75;

   for (i = 1; i <= num_months; i++) {

      printf("\n---------- Month %d ----------\n", i);

      // get user input for expenses
      float expenses = 0;
      for (j = 1; j <= 5; j++) {
         printf("Enter your expenses for category %d: ", j);
         float category_expenses;
         scanf("%f", &category_expenses);
         expenses += category_expenses;
      }
      // calculate savings and update totals
      float savings = monthly_income - expenses;
      total_income += monthly_income;
      total_expenses += expenses;
      total_savings += savings;

      // check if user went over spending limit
      if (expenses > spending_limit) {
         printf("\nWarning! You have exceeded your spending limit for this month.\n");
      }

      // display results for this month
      printf("Income: $%.2f\n", monthly_income);
      printf("Expenses: $%.2f\n", expenses);
      printf("Savings: $%.2f\n", savings);
   }

   // display total results for the planning period
   printf("\n---------- Total Results ----------\n");
   printf("Total Income: $%.2f\n", total_income);
   printf("Total Expenses: $%.2f\n", total_expenses);
   printf("Total Savings: $%.2f\n", total_savings);

   return 0;
}