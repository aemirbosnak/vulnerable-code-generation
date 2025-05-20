//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>

int main()
{
  float income, expenses, savings;

  printf("Enter your income: ");
  scanf("%f", &income);

  printf("Enter your expenses: ");
  scanf("%f", &expenses);

  savings = income - expenses;

  if(savings > 0)
  {
    printf("You have saved $%.2f this month.\n", savings);
  }
  else if(savings < 0)
  {
    printf("You are in debt for $%.2f this month.\n", -savings);
  }
  else
  {
    printf("You did not save any money this month.\n");
  }

  float percentSaved = (savings / income) * 100;

  printf("You saved %.2f percent of your income.\n", percentSaved);

  if(percentSaved < 10)
  {
    printf("You should try to save at least 10 percent of your income.\n");
  }
  else if(percentSaved < 20)
  {
    printf("Good job! You saved more than 10 percent of your income.\n");
  }
  else
  {
    printf("Great job! You saved more than 20 percent of your income.\n");
  }

  float twentyPercent = 0.20 * income;
  float remaining = twentyPercent - savings;

  if(remaining <= 0)
  {
    printf("You have reached your goal of saving 20 percent of your income!\n");
  }
  else
  {
    printf("You still need to save $%.2f to reach your goal of saving 20 percent of your income.\n", remaining);
  }

  return 0;
}