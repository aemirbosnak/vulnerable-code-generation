//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
// C Personal Finance Planner Example Program
#include <stdio.h>
#include <stdlib.h>

struct Expense {
  char name[50];
  float amount;
};

int main() {
  int num_expenses;
  float total_expenses = 0.0;
  
  // Get number of expenses from user
  printf("Enter the number of expenses: ");
  scanf("%d", &num_expenses);
  
  // Allocate memory for expenses
  struct Expense *expenses = (struct Expense*) malloc(num_expenses * sizeof(struct Expense));
  
  // Get expense details from user
  for (int i = 0; i < num_expenses; i++) {
    printf("Enter expense name for expense %d: ", i+1);
    scanf("%s", &(expenses[i].name));
    printf("Enter expense amount for expense %d: ", i+1);
    scanf("%f", &(expenses[i].amount));
    total_expenses += expenses[i].amount;
  }
  
  // Display expense summary
  printf("\nExpense Summary:\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("- %s: $%.2f\n", expenses[i].name, expenses[i].amount);
  }
  printf("Total Expenses: $%.2f\n\n", total_expenses);
  
  // Get user's projected income
  float income;
  printf("Enter your projected total income: ");
  scanf("%f", &income);
  
  // Calculate remaining income after expenses
  float remaining_income = income - total_expenses;
  if (remaining_income >= 0) {
    printf("\nYou have %.2f dollars leftover after expenses.\n", remaining_income);
  } else {
    printf("\nYou are in debt by %.2f dollars.\n", -(remaining_income));
  }
  
  // Free allocated memory
  free(expenses);
  
  return 0;
}