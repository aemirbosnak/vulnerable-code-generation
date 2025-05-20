//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income, saving_rate, rent, utilities, groceries, dining_out, transportation, entertainment, clothing, healthcare, insurance, taxes, total_expenses, net_income;
  
  printf("Welcome to the Personal Finance Planner!\n");
  printf("----------------------------------------\n");
  
  printf("Please enter your monthly income: ");
  scanf("%f", &income);
  
  printf("Please enter your desired saving rate: ");
  scanf("%f", &saving_rate);
  
  printf("Please enter your monthly rent/mortgage expense: ");
  scanf("%f", &rent);
  
  printf("Please enter your monthly utilities expense: ");
  scanf("%f", &utilities);
  
  printf("Please enter your monthly groceries expense: ");
  scanf("%f", &groceries);
  
  printf("Please enter your monthly dining out expense: ");
  scanf("%f", &dining_out);
  
  printf("Please enter your monthly transportation expense: ");
  scanf("%f", &transportation);
  
  printf("Please enter your monthly entertainment expense: ");
  scanf("%f", &entertainment);
  
  printf("Please enter your monthly clothing expense: ");
  scanf("%f", &clothing);
  
  printf("Please enter your monthly healthcare expense: ");
  scanf("%f", &healthcare);
  
  printf("Please enter your monthly insurance expense: ");
  scanf("%f", &insurance);
  
  printf("Please enter your monthly taxes expense: ");
  scanf("%f", &taxes);
  
  printf("\n");
  
  total_expenses = rent + utilities + groceries + dining_out + transportation + entertainment + clothing + healthcare + insurance + taxes;
  
  printf("Here is your monthly finance report:\n");
  printf("-------------------------------------\n");
  printf("Monthly Income: $%.2f\n", income);
  printf("Desired Saving Rate: %.2f%%\n", saving_rate);
  printf("Total Expenses: $%.2f\n", total_expenses);
  
  net_income = income - total_expenses - (income * (saving_rate / 100));
  
  printf("Net Income: $%.2f\n", net_income);
  
  if (net_income < 0) {
    printf("Warning: Your expenses exceed your income!\n");
  } else {
    printf("Congratulations: You are spending within your means!\n");
  }
  
  return 0;
}