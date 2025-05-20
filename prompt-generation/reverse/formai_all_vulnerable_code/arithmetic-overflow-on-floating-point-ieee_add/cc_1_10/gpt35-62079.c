//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  //initialize variables for income and expenses
  float monthlyIncome, housing, food, transportation, utilities, health, entertainment, savings, totalExpense;
  
  //prompt user to input monthly income
  printf("Enter your monthly income: ");
  scanf("%f", &monthlyIncome);

  //prompt user to input each expense category
  printf("Enter your monthly housing expense: ");
  scanf("%f", &housing);

  printf("Enter your monthly food expense: ");
  scanf("%f", &food);

  printf("Enter your monthly transportation expense: ");
  scanf("%f", &transportation);

  printf("Enter your monthly utilities expense: ");
  scanf("%f", &utilities);

  printf("Enter your monthly healthcare expense: ");
  scanf("%f", &health);

  printf("Enter your monthly entertainment expense: ");
  scanf("%f", &entertainment);

  printf("Enter your monthly savings amount: ");
  scanf("%f", &savings);

  //calculate total expenses
  totalExpense = housing + food + transportation + utilities + health + entertainment + savings;

  //display results to user
  printf("\nIncome:\t\t\t$%.2f\n", monthlyIncome);
  printf("Housing:\t\t$%.2f\n", housing);
  printf("Food:\t\t\t$%.2f\n", food);
  printf("Transportation:\t\t$%.2f\n", transportation);
  printf("Utilities:\t\t$%.2f\n", utilities);
  printf("Healthcare:\t\t$%.2f\n", health);
  printf("Entertainment:\t\t$%.2f\n", entertainment);
  printf("Savings:\t\t$%.2f\n", savings);
  printf("Total Expenses:\t\t$%.2f\n", totalExpense);
  
  //check if user is over or under budget
  if (monthlyIncome > totalExpense) {
    printf("You are under budget by $%.2f\n", monthlyIncome - totalExpense);
  } else if (monthlyIncome < totalExpense) {
    printf("You are over budget by $%.2f\n", totalExpense - monthlyIncome);
  } else {
    printf("You are exactly on budget\n");
  }

  return 0;
}