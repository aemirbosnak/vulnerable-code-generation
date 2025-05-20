//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to your Personal Finance Planner!\n\n");

  float income, rent, utilities, groceries, transportation, entertainment;
  float expenses_total, savings, savings_rate;
  char name[30];

  printf("Let's get started by getting to know you better.\n");
  printf("What's your name? ");
  scanf("%s", name);
  printf("Nice to meet you, %s!\n\n", name);

  printf("What is your monthly income? $");
  scanf("%f", &income);

  printf("\nGreat! Let's move on to your monthly expenses.\n");
  printf("How much do you spend on rent/mortgage? $");
  scanf("%f", &rent);

  printf("How much do you spend on utilities? $");
  scanf("%f", &utilities);

  printf("How much do you spend on groceries? $");
  scanf("%f", &groceries);

  printf("How much do you spend on transportation? $");
  scanf("%f", &transportation);

  printf("How much do you spend on entertainment? $");
  scanf("%f", &entertainment);

  expenses_total = rent + utilities + groceries + transportation + entertainment;
  savings = income - expenses_total;
  savings_rate = (savings / income) * 100;

  printf("\nHere is a summary of your monthly finances:\n");
  printf("Monthly Income: $%.2f\n", income);
  printf("Monthly Expenses: $%.2f\n", expenses_total);
  printf("Monthly Savings: $%.2f\n", savings);
  printf("Savings Rate: %.2f%%\n\n", savings_rate);

  if (savings_rate >= 20) {
    printf("Fantastic job, %s! You are a great saver and on your way to financial independence!\n", name);
  } else if (savings_rate >= 10 && savings_rate < 20) {
    printf("Great work, %s! Your savings rate is decent, but there is still room for improvement!\n", name);
  } else {
    printf("Uh oh, %s! You may need to re-evaluate your spending habits and try to cut back!\n", name);
  }

  return 0;
}