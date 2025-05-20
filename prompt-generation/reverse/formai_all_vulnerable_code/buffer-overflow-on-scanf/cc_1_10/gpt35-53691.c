//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main(){

  /* User Input */
  double monthlyIncome;
  double housingExpenses;
  double utilitiesExpenses;
  double foodExpenses;
  double transportationExpenses;
  double miscellaneousExpenses;

  printf("Welcome to Retro Finance Planner!\n");
  printf("Please enter your monthly income: $");
  scanf("%lf", &monthlyIncome);
  printf("Please enter your housing expenses: $");
  scanf("%lf", &housingExpenses);
  printf("Please enter your utilities expenses: $");
  scanf("%lf", &utilitiesExpenses);
  printf("Please enter your food expenses: $");
  scanf("%lf", &foodExpenses);
  printf("Please enter your transportation expenses: $");
  scanf("%lf", &transportationExpenses);
  printf("Please enter your miscellaneous expenses: $");
  scanf("%lf", &miscellaneousExpenses);

  /* Calculations */
  double totalExpenses = housingExpenses + utilitiesExpenses + foodExpenses + transportationExpenses + miscellaneousExpenses;
  double savings = monthlyIncome - totalExpenses;
  double savingsPercentage = savings / monthlyIncome * 100;

  /* Output */
  system("clear"); // Clears the console screen
  printf("Retro Finance Planner Results\n");
  printf("-------------------------------\n");
  printf("Monthly Income: $%.2f\n", monthlyIncome);
  printf("Housing Expenses: $%.2f\n", housingExpenses);
  printf("Utilities Expenses: $%.2f\n", utilitiesExpenses);
  printf("Food Expenses: $%.2f\n", foodExpenses);
  printf("Transportation Expenses: $%.2f\n", transportationExpenses);
  printf("Miscellaneous Expenses: $%.2f\n", miscellaneousExpenses);
  printf("Total Expenses: $%.2f\n", totalExpenses);
  printf("-------------------------------\n");
  if (savings >= 0) {
    printf("Savings: $%.2f (%.2f%%)\n", savings, savingsPercentage);
  } else {
    printf("Deficit: $%.2f\n", -savings);
  }

  return 0;
}