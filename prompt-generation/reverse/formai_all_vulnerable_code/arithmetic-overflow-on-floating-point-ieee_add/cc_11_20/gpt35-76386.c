//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

  printf("Welcome to Personal Finance Planner 2.0!\n");

  //First, we need to obtain user's monthly income.

  float monthly_income;

  printf("Please enter your monthly income: ");
  scanf("%f", &monthly_income);

  if (monthly_income <= 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &monthly_income);
  }

  printf("\n");

  //Next, we need to calculate user's monthly expenses.

  float housing_expenses;
  float transport_expenses;
  float food_expenses;
  float entertainment_expenses;
  float other_expenses;

  printf("Please enter your monthly housing expenses: ");
  scanf("%f", &housing_expenses);

  if (housing_expenses <= 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &housing_expenses);
  }

  printf("Please enter your monthly transport expenses: ");
  scanf("%f", &transport_expenses);

  if (transport_expenses <= 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &transport_expenses);
  }

  printf("Please enter your monthly food expenses: ");
  scanf("%f", &food_expenses);

  if (food_expenses <= 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &food_expenses);
  }

  printf("Please enter your monthly entertainment expenses: ");
  scanf("%f", &entertainment_expenses);

  if (entertainment_expenses <= 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &entertainment_expenses);
  }

  printf("Please enter your monthly other expenses: ");
  scanf("%f", &other_expenses);

  if (other_expenses <= 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &other_expenses);
  }

  float total_expenses = housing_expenses + transport_expenses + food_expenses + entertainment_expenses + other_expenses;

  printf("\n");
  printf("Your monthly income: $%.2f\n", monthly_income);
  printf("Your total monthly expenses: $%.2f\n", total_expenses);

  //Now, we need to calculate user's savings and debts.

  float savings;
  float debts;

  printf("\n");
  printf("Please enter your total savings: ");
  scanf("%f", &savings);

  if (savings < 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &savings);
  }

  printf("Please enter your total debts: ");
  scanf("%f", &debts);

  if (debts < 0){
    printf("Invalid input! Please enter a valid number: ");
    scanf("%f", &debts);
  }

  printf("\n");
  printf("Your total savings: $%.2f\n", savings);
  printf("Your total debts: $%.2f\n", debts);

  //Finally, we need to give user an overall financial summary.

  float net_worth = savings - debts;
  float monthly_budget = monthly_income - total_expenses;

  printf("\n");
  printf("--- Financial Summary ---\n");

  if (net_worth >= 0){
    printf("Congratulations! Your current net worth is $%.2f.\n", net_worth);
  }
  else {
    printf("Warning! Your current net worth is -$%.2f. You have more debts than savings.\n", -net_worth);
  }

  if (monthly_budget >= 0){
    printf("Congratulations! Your current monthly budget is $%.2f.\n", monthly_budget);
  }
  else {
    printf("Warning! Your current monthly budget is -$%.2f. You are spending more than you earn.\n", -monthly_budget);
  }

  printf("Thank you for using Personal Finance Planner 2.0!");

  return 0;
}