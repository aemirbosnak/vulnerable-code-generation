//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user input
typedef struct {
  char name[50];
  int age;
  double income;
  double expenses[5];
  double savings;
  double debt;
} User;

// Function to read user input
void readUserInput(User *user) {
  printf("Enter your name: ");
  scanf("%s", user->name);
  printf("Enter your age: ");
  scanf("%d", &user->age);
  printf("Enter your income: ");
  scanf("%lf", &user->income);
  for (int i = 0; i < 5; i++) {
    printf("Enter your %dth expense: ", i + 1);
    scanf("%lf", &user->expenses[i]);
  }
  printf("Enter your savings: ");
  scanf("%lf", &user->savings);
  printf("Enter your debt: ");
  scanf("%lf", &user->debt);
}

// Function to calculate net worth
double calculateNetWorth(User *user) {
  double netWorth = user->income - user->expenses[0] - user->expenses[1] - user->expenses[2] - user->expenses[3] - user->expenses[4] - user->debt;
  return netWorth;
}

// Function to calculate debt-to-income ratio
double calculateDebtToIncomeRatio(User *user) {
  double debtToIncomeRatio = user->debt / user->income;
  return debtToIncomeRatio;
}

// Function to calculate savings ratio
double calculateSavingsRatio(User *user) {
  double savingsRatio = user->savings / user->income;
  return savingsRatio;
}

// Function to print results
void printResults(User *user) {
  printf("Name: %s\n", user->name);
  printf("Age: %d\n", user->age);
  printf("Income: %.2f\n", user->income);
  printf("Expenses:\n");
  for (int i = 0; i < 5; i++) {
    printf("  %d: %.2f\n", i + 1, user->expenses[i]);
  }
  printf("Savings: %.2f\n", user->savings);
  printf("Debt: %.2f\n", user->debt);
  printf("Net worth: %.2f\n", calculateNetWorth(user));
  printf("Debt-to-income ratio: %.2f\n", calculateDebtToIncomeRatio(user));
  printf("Savings ratio: %.2f\n", calculateSavingsRatio(user));
}

int main() {
  User user;
  readUserInput(&user);
  printResults(&user);
  return 0;
}