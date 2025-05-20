//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>

// function to calculate total expenses
float calculateExpenses(float expenses[], int numExpenses) {
  float totalExpenses = 0;
  for (int i = 0; i < numExpenses; i++) {
    totalExpenses += expenses[i];
  }
  return totalExpenses;
}

// function to calculate total income
float calculateIncome(float income[], int numIncome) {
  float totalIncome = 0;
  for (int i = 0; i < numIncome; i++) {
    totalIncome += income[i];
  }
  return totalIncome;
}

// function to calculate total savings
float calculateSavings(float income[], int numIncome, float expenses[], int numExpenses) {
  float totalIncome = calculateIncome(income, numIncome);
  float totalExpenses = calculateExpenses(expenses, numExpenses);
  float totalSavings = totalIncome - totalExpenses;
  return totalSavings;
}

int main() {
  int numExpenses, numIncome;
  printf("How many expenses do you have? ");
  scanf("%d", &numExpenses);
  float expenses[numExpenses];
  for (int i = 0; i < numExpenses; i++) {
    printf("Expense #%d: ", i+1);
    scanf("%f", &expenses[i]);
  }
  
  printf("\nHow many sources of income do you have? ");
  scanf("%d", &numIncome);
  float income[numIncome];
  for (int i = 0; i < numIncome; i++) {
    printf("Income #%d: ", i+1);
    scanf("%f", &income[i]);
  }

  float totalExpenses = calculateExpenses(expenses, numExpenses);
  float totalIncome = calculateIncome(income, numIncome);
  float totalSavings = calculateSavings(income, numIncome, expenses, numExpenses);

  printf("\nTotal expenses: $%.2f", totalExpenses);
  printf("\nTotal income: $%.2f", totalIncome);
  if (totalSavings >= 0) {
    printf("\nYour net savings this month: $%.2f", totalSavings);
  } else {
    printf("\nYou have overspent this month by: $%.2f", -totalSavings);
  }

  return 0;
}