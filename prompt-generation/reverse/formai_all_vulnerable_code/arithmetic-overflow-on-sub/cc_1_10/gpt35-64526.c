//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>

struct expenses {
  int rent;
  int utilities;
  int groceries;
  int transportation;
  int entertainment;
};

int main() {
  struct expenses month;
  int total_expenses = 0;

  // Getting user input for monthly expenses
  printf("Enter your monthly rent: ");
  scanf("%d", &month.rent);

  printf("Enter your approximate monthly utilities bill: ");
  scanf("%d", &month.utilities);

  printf("Enter your monthly grocery expenses: ");
  scanf("%d", &month.groceries);

  printf("Enter your monthly transportation expenses: ");
  scanf("%d", &month.transportation);

  printf("Enter your monthly entertainment expenses: ");
  scanf("%d", &month.entertainment);

  // Calculating total monthly expenses
  total_expenses = month.rent + month.utilities + month.groceries + month.transportation + month.entertainment;

  // Displaying the calculated total expenses to the user
  printf("\nYour total monthly expenses are $%d.\n", total_expenses);

  // Checking if expenses exceed income
  int monthly_income;
  int after_expenses_income;
  printf("\nEnter your monthly income: ");
  scanf("%d", &monthly_income);

  after_expenses_income = monthly_income - total_expenses;
  if(after_expenses_income < 0) {
    printf("\nUh oh! Your expenses exceed your income. Please consider making some changes to your expenses.\n");
  } else {
    printf("\nYou have $%d left after expenses.\n", after_expenses_income);
  }

  return 0;
}