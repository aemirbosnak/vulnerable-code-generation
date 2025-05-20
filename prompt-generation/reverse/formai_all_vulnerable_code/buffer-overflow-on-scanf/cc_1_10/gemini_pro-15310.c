//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main() {
  // Declare variables for user input
  char name[256];
  int age;
  double income;
  double expenses;
  double savings;

  // Welcome the user
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Let's get started with some basic information.\n\n");

  // Get the user's name
  printf("What's your name?\n");
  scanf("%s", name);

  // Get the user's age
  printf("How old are you?\n");
  scanf("%d", &age);

  // Get the user's income
  printf("What's your annual income?\n");
  scanf("%lf", &income);

  // Get the user's expenses
  printf("What are your total monthly expenses?\n");
  scanf("%lf", &expenses);

  // Calculate the user's savings
  savings = income - expenses;

  // Print the user's financial summary
  printf("\nHere's a summary of your finances, %s:\n", name);
  printf("-----------------------------------------\n");
  printf("Age: %d\n", age);
  printf("Income: $%.2f\n", income);
  printf("Expenses: $%.2f\n", expenses);
  printf("Savings: $%.2f\n", savings);

  // Provide some financial advice
  printf("\nBased on your information, here are some tips for managing your finances:\n");
  if (savings < 0) {
    printf("- You're spending more than you earn. Try to reduce your expenses or increase your income.\n");
  } else if (savings < 0.2 * income) {
    printf("- You're saving some money, but you could be saving more. Try to increase your savings rate.\n");
  } else if (savings > 0.2 * income) {
    printf("- You're doing a great job saving money! Keep it up!\n");
  }

  // Thank the user and exit the program
  printf("\nThank you for using the Personal Finance Planner! We hope you found it helpful.\n");
  return 0;
}