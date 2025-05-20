//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>

int main() {
  float monthlyIncome, rent, utilities, groceries, transportation, entertainment, savings;
  float totalExpenses;
  
  printf("Welcome to the Personal Finance Planner!\n\n");
  printf("Please enter your monthly income: ");
  scanf("%f", &monthlyIncome);
  
  printf("\nPlease enter your monthly rent payment: ");
  scanf("%f", &rent);
  
  printf("\nPlease enter your monthly utilities cost: ");
  scanf("%f", &utilities);
  
  printf("\nPlease enter your monthly grocery expenses: ");
  scanf("%f", &groceries);
  
  printf("\nPlease enter your monthly transportation costs: ");
  scanf("%f", &transportation);
  
  printf("\nPlease enter your monthly entertainment expenses: ");
  scanf("%f", &entertainment);
  
  printf("\nPlease enter your desired monthly savings: ");
  scanf("%f", &savings);
  
  totalExpenses = rent + utilities + groceries + transportation + entertainment + savings;
  
  printf("\n\n------- EXPENSES -------\n");
  printf("Rent: $%.2f\n", rent);
  printf("Utilities: $%.2f\n", utilities);
  printf("Groceries: $%.2f\n", groceries);
  printf("Transportation: $%.2f\n", transportation);
  printf("Entertainment: $%.2f\n", entertainment);
  printf("Savings: $%.2f\n", savings);
  printf("------------------------\n");
  printf("Total monthly expenses: $%.2f\n\n", totalExpenses);
  
  printf("Monthly income after expenses: $%.2f\n\n", monthlyIncome - totalExpenses);
  
  float percentExpenses = (totalExpenses / monthlyIncome) * 100;
  float percentSavings = (savings / monthlyIncome) * 100;
  
  printf("EXPENSES make up %.2f%% of your income.\n", percentExpenses);
  printf("SAVINGS make up %.2f%% of your income.\n", percentSavings);
  
  if (percentExpenses > 50) {
    printf("\nWARNING: Your expenses are too high! Consider reducing them.\n");
  }
  
  return 0;
}