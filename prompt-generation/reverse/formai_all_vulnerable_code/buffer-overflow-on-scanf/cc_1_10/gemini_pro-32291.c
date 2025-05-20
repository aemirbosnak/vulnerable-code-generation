//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to print welcome message
void welcome() {
  printf("Welcome to the Personal Finance Planner!\n");
  printf("This program will help you manage your finances and reach your financial goals.\n\n");
}

// Function to get user input
float get_input(char *prompt) {
  float input;
  printf("%s", prompt);
  scanf("%f", &input);
  return input;
}

// Function to calculate total expenses
float calculate_expenses(float *expenses, int num_expenses) {
  float total = 0;
  for (int i = 0; i < num_expenses; i++) {
    total += expenses[i];
  }
  return total;
}

// Function to calculate total savings
float calculate_savings(float income, float expenses) {
  return income - expenses;
}

// Function to print results
void print_results(float income, float expenses, float savings) {
  printf("Your income is $%.2f.\n", income);
  printf("Your total expenses are $%.2f.\n", expenses);
  printf("Your total savings are $%.2f.\n", savings);
}

// Main function
int main() {
  // Welcome the user
  welcome();

  // Get user input
  float income = get_input("Enter your monthly income: $");
  int num_expenses = get_input("Enter the number of expenses you have: ");
  float expenses[num_expenses];
  for (int i = 0; i < num_expenses; i++) {
    expenses[i] = get_input("Enter the amount of your expense: $");
  }

  // Calculate total expenses
  float total_expenses = calculate_expenses(expenses, num_expenses);

  // Calculate total savings
  float total_savings = calculate_savings(income, total_expenses);

  // Print results
  print_results(income, total_expenses, total_savings);

  return 0;
}