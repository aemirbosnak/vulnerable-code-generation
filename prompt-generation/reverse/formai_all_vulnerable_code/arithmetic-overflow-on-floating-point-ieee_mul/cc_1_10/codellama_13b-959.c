//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
// Personal Finance Planner Example Program

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total amount to be saved
double calculateTotalSaved(double income, double expenses, double savingsRate) {
  return income * savingsRate - expenses;
}

// Function to calculate the total amount to be spent
double calculateTotalSpent(double income, double expenses, double savingsRate) {
  return income - income * savingsRate - expenses;
}

// Function to calculate the net worth
double calculateNetWorth(double totalSaved, double totalSpent) {
  return totalSaved - totalSpent;
}

// Main function
int main() {
  // Get the user's income, expenses, and savings rate
  printf("Enter your income: ");
  double income;
  scanf("%lf", &income);

  printf("Enter your expenses: ");
  double expenses;
  scanf("%lf", &expenses);

  printf("Enter your savings rate (in percentage): ");
  double savingsRate;
  scanf("%lf", &savingsRate);

  // Calculate the total amount to be saved
  double totalSaved = calculateTotalSaved(income, expenses, savingsRate);

  // Calculate the total amount to be spent
  double totalSpent = calculateTotalSpent(income, expenses, savingsRate);

  // Calculate the net worth
  double netWorth = calculateNetWorth(totalSaved, totalSpent);

  // Print the results
  printf("Total saved: %f\n", totalSaved);
  printf("Total spent: %f\n", totalSpent);
  printf("Net worth: %f\n", netWorth);

  return 0;
}