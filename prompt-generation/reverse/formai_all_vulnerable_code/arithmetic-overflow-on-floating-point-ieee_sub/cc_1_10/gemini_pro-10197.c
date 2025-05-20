//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some happy colors for our output
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_RESET "\x1b[0m"

// Declare our main function
int main() {
  // Declare our variables
  char name[50];
  int age;
  double income;
  double expenses;
  double savings;

  // Get the user's name
  printf("Welcome to your happy personal finance planner! What's your name? ");
  scanf("%s", name);

  // Get the user's age
  printf("How old are you, %s? ", name);
  scanf("%d", &age);

  // Get the user's income
  printf("What's your annual income, %s? ", name);
  scanf("%lf", &income);

  // Get the user's expenses
  printf("What are your monthly expenses, %s? ", name);
  scanf("%lf", &expenses);

  // Calculate the user's savings
  savings = income - expenses;

  // Print the user's financial summary
  printf("\nHere's your financial summary, %s:\n", name);
  printf("  - Age: %d\n", age);
  printf("  - Income: %s%.2lf%s\n", COLOR_GREEN, income, COLOR_RESET);
  printf("  - Expenses: %s%.2lf%s\n", COLOR_YELLOW, expenses, COLOR_RESET);
  printf("  - Savings: %s%.2lf%s\n", COLOR_MAGENTA, savings, COLOR_RESET);

  // Give the user some financial advice
  if (savings > 0) {
    printf("\nCongratulations, %s! You're saving money! Keep it up!\n", name);
  } else if (savings == 0) {
    printf("\nYou're breaking even, %s. Maybe it's time to start saving some money?\n", name);
  } else {
    printf("\nOh no, %s! You're spending more than you're earning. You need to cut back on your expenses!\n", name);
  }

  // End the program with a happy message
  printf("\nThanks for using your happy personal finance planner, %s! Have a great day!\n", name);

  return 0;
}