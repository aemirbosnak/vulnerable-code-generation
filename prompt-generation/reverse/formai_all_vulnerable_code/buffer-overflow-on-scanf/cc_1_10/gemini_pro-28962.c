//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Let's introduce our finance-savvy friend, Fin!
  printf("Welcome to the Fin-tastic Personal Finance Planner!\n");
  printf("Let's get you on the path to financial freedom, one step at a time.\n\n");

  // Gather some essential info
  char name[50];
  printf("What's your name, money maestro?\n");
  scanf("%s", name);
  printf("Nice to meet you, %s! Let's dive into your financial journey.\n\n", name);

  // Income time!
  float income;
  printf("Let's start with your hard-earned income. How much do you bring in each month?\n");
  scanf("%f", &income);
  printf("That's great, %s! Income is the backbone of your financial plan.\n\n", name);

  // Now, let's explore your expenses
  float expenses[10];
  char expense_names[10][50];
  int num_expenses;
  printf("Time to face the spending beast. How many major expenses do you have each month?\n");
  scanf("%d", &num_expenses);

  // Dive into each expense
  for (int i = 0; i < num_expenses; i++) {
    printf("Name your %dth expense, %s:\n", (i + 1), name);
    scanf("%s", expense_names[i]);
    printf("And how much do you spend on %s each month?\n", expense_names[i]);
    scanf("%f", &expenses[i]);
  }
  printf("Excellent! We've got a clear picture of your cash flow.\n\n");

  // Let's crunch some numbers
  float total_expenses = 0;
  for (int i = 0; i < num_expenses; i++) {
    total_expenses += expenses[i];
  }
  printf("Time for a reality check, %s. You're spending a total of %f per month.\n", name, total_expenses);

  // Assess the situation
  if (total_expenses > income) {
    printf("Uh oh, your expenses are creeping up on your income. We need to reign them in!\n");
  } else if (total_expenses < income) {
    printf("Fantastic! You're living below your means. Let's explore how to make your money work harder.\n");
  } else {
    printf("Balance achieved! You're managing your expenses perfectly. Keep up the good work!\n");
  }

  // Generate some advice
  printf("Here's a money mantra for you, %s:\n\n", name);
  if (total_expenses > income) {
    printf("Live within your means. Track your expenses meticulously and cut out unnecessary spending.\n");
  } else if (total_expenses < income) {
    printf("Invest wisely. Explore different investment options to grow your wealth over time.\n");
  } else {
    printf("Stay vigilant. Regularly review your expenses and make adjustments as needed.\n");
  }

  // Encourage continued planning
  printf("Remember, %s, financial planning is an ongoing journey. Keep track of your progress and make adjustments along the way.\n", name);
  printf("Fin is always here to guide you! Visit us again anytime for more financial wisdom.\n");

  return 0;
}