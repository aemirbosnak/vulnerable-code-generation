//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the income and expense categories
#define INCOME_CATEGORIES 5
#define EXPENSE_CATEGORIES 7

// Define the income and expense names
const char *INCOME_NAMES[] = {"Salary", "Investment Income", "Rental Income", "Business Income", "Other Income"};
const char *EXPENSE_NAMES[] = {"Housing", "Food", "Transportation", "Utilities", "Entertainment", "Healthcare", "Other Expenses"};

// Define the income and expense amounts
float income_amounts[INCOME_CATEGORIES];
float expense_amounts[EXPENSE_CATEGORIES];

// Function to get the user's income
void get_income() {
  for (int i = 0; i < INCOME_CATEGORIES; i++) {
    printf("Enter your %s income: $", INCOME_NAMES[i]);
    scanf("%f", &income_amounts[i]);
  }
}

// Function to get the user's expenses
void get_expenses() {
  for (int i = 0; i < EXPENSE_CATEGORIES; i++) {
    printf("Enter your %s expenses: $", EXPENSE_NAMES[i]);
    scanf("%f", &expense_amounts[i]);
  }
}

// Function to calculate the user's net income
float calculate_net_income() {
  float net_income = 0;
  for (int i = 0; i < INCOME_CATEGORIES; i++) {
    net_income += income_amounts[i];
  }
  for (int i = 0; i < EXPENSE_CATEGORIES; i++) {
    net_income -= expense_amounts[i];
  }
  return net_income;
}

// Function to print the user's financial plan
void print_financial_plan() {
  printf("**Income**\n");
  for (int i = 0; i < INCOME_CATEGORIES; i++) {
    printf("%s: $%.2f\n", INCOME_NAMES[i], income_amounts[i]);
  }

  printf("\n**Expenses**\n");
  for (int i = 0; i < EXPENSE_CATEGORIES; i++) {
    printf("%s: $%.2f\n", EXPENSE_NAMES[i], expense_amounts[i]);
  }

  float net_income = calculate_net_income();
  printf("\n**Net Income**\n");
  printf("Net Income: $%.2f\n", net_income);
}

// Main function
int main() {
  get_income();
  get_expenses();
  print_financial_plan();
  return 0;
}