//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store financial data
typedef struct FinancialData {
  char name[50];
  int age;
  double income;
  double expenses;
  double savings;
} FinancialData;

// Function to calculate total savings
double calculateTotalSavings(FinancialData *data) {
  return data->savings + data->income * 0.1;
}

// Function to print financial data
void printFinancialData(FinancialData *data) {
  printf("Name: %s\n", data->name);
  printf("Age: %d\n", data->age);
  printf("Income: %.2lf\n", data->income);
  printf("Expenses: %.2lf\n", data->expenses);
  printf("Savings: %.2lf\n", data->savings);
  printf("Total Savings: %.2lf\n", calculateTotalSavings(data));
}

int main() {
  // Create a financial data structure
  FinancialData data;

  // Get the user's name, age, income, and expenses
  printf("Enter your name: ");
  scanf("%s", data.name);

  printf("Enter your age: ");
  scanf("%d", &data.age);

  printf("Enter your income: ");
  scanf("%lf", &data.income);

  printf("Enter your expenses: ");
  scanf("%lf", &data.expenses);

  // Calculate the user's savings
  data.savings = calculateTotalSavings(&data);

  // Print the user's financial data
  printFinancialData(&data);

  return 0;
}