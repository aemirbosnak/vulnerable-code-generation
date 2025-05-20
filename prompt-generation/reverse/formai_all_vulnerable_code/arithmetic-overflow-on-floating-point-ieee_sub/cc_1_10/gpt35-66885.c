//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>

int main()
{
  float monthly_income;
  int monthly_savings_goal, current_savings;
  int months_till_goal_reached;
  
  printf("Enter your current savings: $");
  scanf("%d", &current_savings);
  
  printf("Enter your monthly income: $");
  scanf("%f", &monthly_income);
  
  printf("Enter your monthly savings goal: $");
  scanf("%d", &monthly_savings_goal);
  
  months_till_goal_reached = (monthly_savings_goal - current_savings) / monthly_income;
  
  printf("At your current income and savings, you will reach your goal in %d months.\n", months_till_goal_reached);
  
  float monthly_expenses, net_savings;
  
  printf("Enter your monthly expenses: $");
  scanf("%f", &monthly_expenses);
  
  net_savings = monthly_income - monthly_expenses;
  
  printf("Your net savings each month is $%.2f\n", net_savings);
  
  float total_savings, total_income, total_expenses;
  int num_months;
  
  printf("Enter the number of months you would like to project your finances: ");
  scanf("%d", &num_months);
  
  total_savings = current_savings;
  total_income = monthly_income * num_months;
  total_expenses = monthly_expenses * num_months;
  
  printf("Over the next %d months, your projected income is $%.2f. \n", num_months, total_income);
  printf("Your projected expenses over the next %d months is $%.2f.\n", num_months, total_expenses);
  
  float projected_savings;
  
  projected_savings = total_income - total_expenses;
  
  printf("Your projected total savings over the next %d months is $%.2f.\n", num_months, projected_savings + current_savings);
  
  return 0;
}