//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>

int main()
{
  //variables for income
  float salary, side_income, total_income;
  
  //variables for expenses
  float rent, utilities, food, transportation, entertainment, total_expenses;
  
  //getting income details
  printf("Enter your monthly salary: ");
  scanf("%f", &salary);
  
  printf("Enter your monthly side income: ");
  scanf("%f", &side_income);
  
  total_income = salary + side_income; //adding up total income
  
  //getting expense details
  printf("\nEnter your monthly rent amount: ");
  scanf("%f", &rent);
  
  printf("Enter your monthly utility bill: ");
  scanf("%f", &utilities);
  
  printf("Enter your monthly food expenses: ");
  scanf("%f", &food);
  
  printf("Enter your monthly transportation expenses: ");
  scanf("%f", &transportation);
  
  printf("Enter your monthly entertainment expenses: ");
  scanf("%f", &entertainment);
  
  total_expenses = rent + utilities + food + transportation + entertainment; //adding up total expenses
  
  //displaying final results
  printf("\nTotal Monthly Income: $%.2f\n", total_income);
  printf("Total Monthly Expenses: $%.2f\n", total_expenses);
  
  if(total_income > total_expenses)
  {
    printf("Congratulations! You have a surplus of $%.2f this month.\n", (total_income - total_expenses));
  }
  else if(total_income == total_expenses)
  {
    printf("You broke even this month. Keep an eye on your expenses.\n");
  }
  else
  {
    printf("Uh oh, you have a deficit of $%.2f this month. You may need to cut back on expenses.\n", (total_expenses - total_income));
  }
  
  return 0;
}