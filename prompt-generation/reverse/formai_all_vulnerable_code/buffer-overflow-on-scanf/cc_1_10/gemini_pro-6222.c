//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define income and expense categories
#define INCOME_CATEGORIES 5
#define EXPENSE_CATEGORIES 7

// Define income and expense names
char *incomeNames[INCOME_CATEGORIES] = {"Salary", "Investments", "Gifts", "Other"};
char *expenseNames[EXPENSE_CATEGORIES] = {"Rent/Mortgage", "Utilities", "Food", "Transportation", "Entertainment", "Debt", "Other"};

// Define income and expense amounts
int incomeAmounts[INCOME_CATEGORIES];
int expenseAmounts[EXPENSE_CATEGORIES];

// Define total income and expenses
int totalIncome = 0;
int totalExpenses = 0;

// Get user input
void getInput() {
  int i;

  // Get income amounts
  printf("Enter your income amounts:\n");
  for (i = 0; i < INCOME_CATEGORIES; i++) {
    printf("%s: ", incomeNames[i]);
    scanf("%d", &incomeAmounts[i]);
    totalIncome += incomeAmounts[i];
  }

  // Get expense amounts
  printf("Enter your expense amounts:\n");
  for (i = 0; i < EXPENSE_CATEGORIES; i++) {
    printf("%s: ", expenseNames[i]);
    scanf("%d", &expenseAmounts[i]);
    totalExpenses += expenseAmounts[i];
  }
}

// Calculate net income
int calculateNetIncome() {
  return totalIncome - totalExpenses;
}

// Print financial summary
void printSummary() {
  int i;

  // Print income summary
  printf("Income Summary:\n");
  for (i = 0; i < INCOME_CATEGORIES; i++) {
    printf("%s: %d\n", incomeNames[i], incomeAmounts[i]);
  }
  printf("Total Income: %d\n", totalIncome);

  // Print expense summary
  printf("Expense Summary:\n");
  for (i = 0; i < EXPENSE_CATEGORIES; i++) {
    printf("%s: %d\n", expenseNames[i], expenseAmounts[i]);
  }
  printf("Total Expenses: %d\n", totalExpenses);

  // Print net income summary
  printf("Net Income: %d\n", calculateNetIncome());
}

// Main function
int main() {
  // Get user input
  getInput();

  // Print financial summary
  printSummary();

  return 0;
}