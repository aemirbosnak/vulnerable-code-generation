//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include<stdio.h>
#include<string.h>

int main()
{
  float income, savings;
  int expense[12], i, total_expense=0;
  char month[12][10]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  printf("\n\t\t Personal Finance Planner\n\n"); // Title of the planner

  printf("\nEnter your monthly income: ");
  scanf("%f",&income);

  printf("\nEnter your monthly savings goal: ");
  scanf("%f",&savings);

  for(i=0; i<12; i++)
  {
    printf("\n\nEnter your expenses for %s: ",month[i]);
    scanf("%d",&expense[i]);
    total_expense += expense[i];

    if(total_expense > income)
      printf("Warning: Your expenses are greater than your income for the previous months\n\n");

    if((i+1)%3==0) // Every three months, display quarterly summary
    {
      printf("\n\n___________________Quaterly Summary___________________\n");
      printf("\nTotal expenses for the past three months: %d", total_expense);
      printf("\nTotal income for the past three months: %.2f", (income * 3));
      printf("\nAmount saved for the past three months: %.2f", ((income * 3) - total_expense));
      printf("\nMonthly average expenses for the past three months: %.2f\n\n", (float)total_expense/3.0);

      total_expense = 0;
    }
  }

  printf("\n\n___________________Annual Summary___________________\n");
  printf("\nTotal expenses for the year: %d", total_expense+expense[11]);
  printf("\nTotal income for the year: %.2f", (income * 12));
  printf("\nAmount saved for the year: %.2f", ((income * 12) - (total_expense+expense[11])));
  printf("\nAverage monthly expenses for the year: %.2f\n\n",(float)(total_expense+expense[11])/12.0);

  if(((income * 12) - (total_expense+expense[11])) < savings)
    printf("Warning: You did not meet your annual savings goal.");
  else
    printf("Congratulations! You have met your annual savings goal.");

  return 0; // End of program
}