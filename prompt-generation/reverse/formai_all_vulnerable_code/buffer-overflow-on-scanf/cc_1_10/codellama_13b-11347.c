//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
// Personal Finance Planner in a Decentralized Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct to store user's financial data
struct FinancialData {
  int age;
  float income;
  float expenses;
  float savings;
  float debt;
  float emergencyFund;
};

// Function to calculate the user's net worth
float calculateNetWorth(struct FinancialData *data) {
  return data->income + data->savings - data->expenses - data->debt;
}

// Function to calculate the user's debt to income ratio
float calculateDebtToIncomeRatio(struct FinancialData *data) {
  return data->debt / data->income;
}

// Function to calculate the user's emergency fund percentage
float calculateEmergencyFundPercentage(struct FinancialData *data) {
  return data->emergencyFund / data->income;
}

// Function to calculate the user's credit score
int calculateCreditScore(struct FinancialData *data) {
  return (data->income + data->savings) / (data->expenses + data->debt);
}

// Main function to run the program
int main() {
  // Declare variables
  struct FinancialData data;
  float netWorth, debtToIncomeRatio, emergencyFundPercentage, creditScore;

  // Get user's financial data
  printf("Enter your age: ");
  scanf("%d", &data.age);
  printf("Enter your income: ");
  scanf("%f", &data.income);
  printf("Enter your expenses: ");
  scanf("%f", &data.expenses);
  printf("Enter your savings: ");
  scanf("%f", &data.savings);
  printf("Enter your debt: ");
  scanf("%f", &data.debt);
  printf("Enter your emergency fund: ");
  scanf("%f", &data.emergencyFund);

  // Calculate the user's net worth
  netWorth = calculateNetWorth(&data);
  // Calculate the user's debt to income ratio
  debtToIncomeRatio = calculateDebtToIncomeRatio(&data);
  // Calculate the user's emergency fund percentage
  emergencyFundPercentage = calculateEmergencyFundPercentage(&data);
  // Calculate the user's credit score
  creditScore = calculateCreditScore(&data);

  // Print the results
  printf("Net Worth: %f\n", netWorth);
  printf("Debt to Income Ratio: %f\n", debtToIncomeRatio);
  printf("Emergency Fund Percentage: %f\n", emergencyFundPercentage);
  printf("Credit Score: %d\n", creditScore);

  return 0;
}