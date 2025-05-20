//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
  float salary, budget, expenses;
  char ans;

  printf("Welcome to the Personal Finance Planner. We care about your money and privacy.\n");
  printf("Please enter your monthly salary: ");
  scanf("%f", &salary);

  printf("Have you paid attention to any suspicious activity on your bank account recently? (Y/N): ");
  scanf(" %c", &ans);

  if(ans == 'Y' || ans == 'y'){
    printf("Warning! Your financial information may be compromised. We advise you not to proceed with the planner.");
    exit(0);
  }
  else{
    printf("Good to know. Let's move on.\n");
  }

  printf("Please enter your monthly budget: ");
  scanf("%f", &budget);

  expenses = budget;
  printf("Do you have any additional income besides your monthly salary? (Y/N): ");
  scanf(" %c", &ans);

  if(ans == 'Y' || ans == 'y'){
    float additionalIncome;
    printf("Please enter the amount of additional income: ");
    scanf("%f", &additionalIncome);

    salary += additionalIncome;
    printf("Your total monthly salary is now: %f\n", salary);
  }

  printf("Now, let's track your expenses.\n");
  printf("Do you want us to store your expenses on our server to track it better? (Y/N): ");
  scanf(" %c", &ans);

  if(ans == 'Y' || ans == 'y'){
    printf("We understand your concern about privacy, but we promise to keep your data safe.\n");
  }
  else{
    printf("We respect your decision. However, the planner may not function optimally without tracking expenses.\n");
  }

  int numExpenses;
  printf("How many expense categories do you want to track? (Enter a number): ");
  scanf("%d", &numExpenses);

  char expenseNames[numExpenses][20];
  float expenseAmounts[numExpenses];

  for(int i=0; i<numExpenses; i++){
    printf("Please enter expense category #%d name: ", i+1);
    scanf("%s", expenseNames[i]);

    printf("Please enter amount spent for %s: ", expenseNames[i]);
    scanf("%f", &expenseAmounts[i]);

    expenses += expenseAmounts[i];
  }

  printf("Thank you for entering your expenses.\n");

  if(expenses > salary){
    printf("Warning! Your expenses exceed your monthly income. Please review your expenses and adjust your budget accordingly.");
  }
  else{
    printf("Here is your Financial Overview\n");
    printf("Monthly Salary: %f\n", salary);
    printf("Monthly Budget: %f\n", budget);
    printf("Total Monthly Expenses: %f\n", expenses);
    printf("Monthly Savings: %f\n", salary-expenses);
  }

  printf("Thank you for using Personal Finance Planner.\n");
  
  return 0;
}