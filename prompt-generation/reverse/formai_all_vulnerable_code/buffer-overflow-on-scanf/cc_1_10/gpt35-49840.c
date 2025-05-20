//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
/*Welcome to Personal Finance Planner*/
/*Thank you for choosing our program*/
/*We are grateful for your trust in us*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  float income, expenses, savings;

  /*Asking for user input*/
  printf("Enter your monthly income: ");
  scanf("%f", &income);

  printf("Enter your monthly expenses: ");
  scanf("%f", &expenses);

  /*Calculating savings*/
  savings = income - expenses;

  /*Checking if user is overspending*/
  if (savings < 0) {
    printf("You are overspending! Please review your expenses. \n");
  }
  else {
    printf("Your monthly savings: $%.2f \n", savings);
  }

  /*Providing a suggestion for saving*/
  if (savings > 500) {
    printf("Great job! You are saving a lot! Here are some ideas to invest your savings: \n");
    printf("- Open a savings account with high-interest rates \n");
    printf("- Invest in index funds \n");
    printf("- Pay off high-interest debt \n");
  }
  else if (savings > 200) {
    printf("Good job! You are saving a decent amount. Here are some ideas to increase your savings: \n");
    printf("- Cut back on eating out \n");
    printf("- Cancel subscriptions you don't use \n");
    printf("- Shop for deals and discounts \n");
  }
  else {
    printf("You could be saving more! Here are some ideas to save money: \n");
    printf("- Make your coffee at home instead of buying it \n");
    printf("- Buy generic brands instead of name brands \n");
    printf("- Use cashback apps while shopping \n");
  }

  return 0;
}