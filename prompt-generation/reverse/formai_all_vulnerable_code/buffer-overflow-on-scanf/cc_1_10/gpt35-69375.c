//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please input your monthly income: ");

  float income;
  scanf("%f", &income);

  printf("Please input your monthly expenses:\n");

  float total_expenses = 0;
  float item_cost;
  
  // Using "while" loop to keep asking for item costs until user inputs "done"
  while (1) {
    char item_name[50];
    printf("Item name (or 'done' to finish adding expenses): ");
    scanf("%s", item_name);

    if (strcmp(item_name, "done") == 0) {
      break;
    }

    printf("Cost of '%s': $", item_name);
    scanf("%f", &item_cost);
    total_expenses += item_cost;
  }

  // Calculating the remaining budget after expenses
  float remaining_budget = income - total_expenses;

  printf("\nLimit your expenses to: $%.2f\n", income * 0.5);
  printf("Suggested savings amount: $%.2f\n\n", income * 0.2);

  printf("Your monthly income: $%.2f\n", income);
  printf("Your total expenses: $%.2f\n", total_expenses);
  printf("Your remaining budget: $%.2f\n", remaining_budget);

  // Using "if" statement to suggest adjustments to monthly spending
  if (total_expenses > income * 0.5) {
    printf("\nYou have exceeded your monthly spending limit. Please review your expenses and seek ways to reduce them.\n");
  } else if (remaining_budget < income * 0.2) {
    printf("\nYou may need to adjust your spending and reduce expenses in order to save more.\n");
  } else {
    printf("\nYou are on track to meet your financial goals! Keep it up!\n");
  }

  return 0;
}