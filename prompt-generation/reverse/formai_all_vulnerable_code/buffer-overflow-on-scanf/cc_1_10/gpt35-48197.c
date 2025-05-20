//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>

// function to calculate total expenses
float calculateExpenses(int n) {
  float expenses = 0;
  for(int i = 0; i < n; i++) {
    float expense;
    printf("Enter expense %d: ", i+1);
    scanf("%f", &expense);
    expenses += expense;
  }
  return expenses;
}

// function to calculate total income
float calculateIncome(int n) {
  float income = 0;
  for(int i = 0; i < n; i++) {
    float salary;
    printf("Enter salary %d: ", i+1);
    scanf("%f", &salary);
    income += salary;
  }
  return income;
}

// function to calculate net savings
float calculateSavings(float income, float expenses) {
  return income - expenses;
}

// function to display monthly budget
void displayBudget() {
  int numExpenses, numIncomes;
  float expenses, income, savings;

  // ask for number of expenses and calculate total expenses
  printf("Enter number of expenses: ");
  scanf("%d", &numExpenses);
  expenses = calculateExpenses(numExpenses);

  // ask for number of incomes and calculate total income
  printf("Enter number of incomes: ");
  scanf("%d", &numIncomes);
  income = calculateIncome(numIncomes);

  // calculate net savings
  savings = calculateSavings(income, expenses);

  // display monthly budget
  printf("\nMonthly Budget:\n");
  printf("Expenses: %.2f\n", expenses);
  printf("Income: %.2f\n", income);
  printf("Savings: %.2f\n", savings);
}

int main() {
  // display monthly budget
  displayBudget();

  return 0;
}