//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float income = 0;
  float expenses = 0;
  float savings = 0;
  float budget = 0;
  int choice = 0;

  printf("Welcome to the Personal Finance Planner!\n\n");

  while (1) {
    printf("Choose an option:\n");
    printf("(1) Set Income\n");
    printf("(2) Set Expenses\n");
    printf("(3) Calculate Savings\n");
    printf("(4) Calculate Budget\n");
    printf("(5) Exit\n\n");

    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("\nEnter your monthly income: $");
        scanf("%f", &income);
        break;
      
      case 2:
        printf("\nEnter your monthly expenses: $");
        scanf("%f", &expenses);
        break;
      
      case 3:
        savings = income - expenses;
        if (savings < 0) {
          printf("\nWARNING: Your expenses are greater than your income!\n");
        }
        printf("\nYour monthly savings: $%.2f\n", savings);
        break;

      case 4:
        budget = income - expenses;
        if (budget < 0) {
          printf("\nWARNING: Your expenses are greater than your income!\n");
        } else if (budget < 500) {
          printf("\nYour budget is tight. Consider cutting back on expenses.\n");
        } else {
          printf("\nYour budget is healthy! You have room to spend and save.\n");
        }
        printf("Your monthly budget: $%.2f\n", budget);
        break;

      case 5:
        printf("\nThank you for using the Personal Finance Planner! Goodbye.\n");
        exit(0);

      default:
        printf("\nInvalid choice! Please try again.\n");
        break;
    }

    printf("\n");
  }

  return 0;
}