//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store financial data
typedef struct FinanceData {
  char name[50];
  int age;
  double income;
  double expenses;
  double savings;
} FinanceData;

// Function to calculate total savings
double calculateSavings(FinanceData *data) {
  double totalSavings = data->savings;
  return totalSavings;
}

// Function to calculate total expenses
double calculateExpenses(FinanceData *data) {
  double totalExpenses = data->expenses;
  return totalExpenses;
}

// Function to calculate net worth
double calculateNetWorth(FinanceData *data) {
  double totalAssets = data->savings;
  double totalLiabilities = calculateExpenses(data);
  double netWorth = totalAssets - totalLiabilities;
  return netWorth;
}

int main() {
  // Create a struct instance
  FinanceData data;

  // Get user input
  printf("Enter your name: ");
  scanf("%s", data.name);

  printf("Enter your age: ");
  scanf("%d", &data.age);

  printf("Enter your income: ");
  scanf("%lf", &data.income);

  printf("Enter your expenses: ");
  scanf("%lf", &data.expenses);

  // Calculate total savings, expenses, and net worth
  double totalSavings = calculateSavings(&data);
  double totalExpenses = calculateExpenses(&data);
  double netWorth = calculateNetWorth(&data);

  // Display results
  printf("Your total savings is: $%.2lf", totalSavings);
  printf("\nYour total expenses are: $%.2lf", totalExpenses);
  printf("\nYour net worth is: $%.2lf", netWorth);

  return 0;
}