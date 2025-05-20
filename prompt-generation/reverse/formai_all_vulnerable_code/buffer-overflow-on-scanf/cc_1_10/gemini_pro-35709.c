//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome the user
  printf("Welcome to the Ultimate Personal Finance Planner!\n");
  printf("Get ready to conquer your financial goals like a boss!\n\n");

  // Gather user input
  char name[50];
  printf("What's your name, financial superstar?\n");
  scanf("%s", name);
  printf("Greetings, %s! Let's get started on your financial adventure.\n", name);

  // Set up the budget
  int income;
  printf("Awesome! Now, let's talk money. What's your monthly income?\n");
  scanf("%d", &income);

  // Calculate expenses
  int expenses[10];
  int numExpenses;
  printf("Time to get real. List down your monthly expenses. How many expenses do you have?\n");
  scanf("%d", &numExpenses);
  printf("Okay, enter each expense one by one:\n");
  for (int i = 0; i < numExpenses; i++) {
    scanf("%d", &expenses[i]);
  }

  // Analyze financial situation
  int totalExpenses = 0;
  for (int i = 0; i < numExpenses; i++) {
    totalExpenses += expenses[i];
  }

  printf("Okay, %s. Let's break it down.\n", name);
  printf("Your total monthly income is: %d\n", income);
  printf("Your total monthly expenses are: %d\n", totalExpenses);

  // Calculate savings
  int savings = income - totalExpenses;
  printf("And here's your savings: %d\n\n", savings);

  // Offer personalized advice
  if (savings > 0) {
    printf("You're rocking it, %s! Keep up the great work.\n", name);
  } else if (savings == 0) {
    printf("Hey, %s, let's find ways to optimize your expenses.\n", name);
  } else {
    printf("Time for some financial adjustments, %s!\n", name);
  }

  // Encourage the user
  printf("Remember, %s, you've got this! Make smart financial decisions and watch your savings grow.\n", name);

  return 0;
}