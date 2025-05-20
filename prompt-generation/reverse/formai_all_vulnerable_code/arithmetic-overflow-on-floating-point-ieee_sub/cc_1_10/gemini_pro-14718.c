//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main() {

  // Welcome the user to the program
  printf("Welcome to the Personal Finance Planner!\n");

  // Prompt the user for their name
  printf("What is your name? ");
  char name[50];
  scanf("%s", name);

  // Prompt the user for their income
  printf("What is your monthly income? ");
  float income;
  scanf("%f", &income);

  // Prompt the user for their expenses
  printf("What are your monthly expenses? ");
  float expenses;
  scanf("%f", &expenses);

  // Calculate the user's savings
  float savings = income - expenses;

  // Print the user's savings
  printf("Your monthly savings are %f.\n", savings);

  // Prompt the user for their financial goals
  printf("What are your financial goals? ");
  char goals[50];
  scanf(" %[^\n]", goals);

  // Print the user's financial goals
  printf("Your financial goals are %s.\n", goals);

  // Prompt the user for their target date
  printf("What is your target date for achieving your goals? ");
  char date[50];
  scanf(" %[^\n]", date);

  // Print the user's target date
  printf("Your target date is %s.\n", date);

  // Calculate the user's monthly savings goal
  float savings_goal = (income * 0.2);

  // Print the user's monthly savings goal
  printf("Your monthly savings goal is %f.\n", savings_goal);

  // Calculate the number of months needed to achieve the goal
  float months_needed = (savings_goal / savings);

  // Print the number of months needed to achieve the goal
  printf("You need %f months to achieve your goal.\n", months_needed);

  // Thank the user for using the program
  printf("Thank you for using the Personal Finance Planner!\n");

  return 0;
}