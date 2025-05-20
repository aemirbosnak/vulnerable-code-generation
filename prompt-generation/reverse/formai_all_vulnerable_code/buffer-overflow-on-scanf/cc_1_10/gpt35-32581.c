//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>

int main() {
  int income, expense, savings, budget;
  
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please enter your monthly income: ");
  scanf("%d", &income);
  
  printf("Please enter your monthly expenses: ");
  scanf("%d", &expense);
  
  printf("Your monthly income is $%d and your monthly expenses are $%d.\n", income, expense);
  
  savings = income - expense;
  
  if (savings >= expense) {
    printf("Great job! You have a positive savings balance of $%d.\n", savings);
  } else {
    printf("Uh oh, your expenses are more than your income. You are in the negative by $%d.\n", savings);
  }
  
  printf("Let's make a budget for the month!\n");
  
  printf("How much would you like to allocate for food? ");
  scanf("%d", &budget);
  savings = savings - budget;
  printf("You now have $%d remaining.\n", savings);
  
  printf("How much would you like to allocate for rent/mortgage? ");
  scanf("%d", &budget);
  savings = savings - budget;
  printf("You now have $%d remaining.\n", savings);
  
  printf("How much would you like to allocate for transportation? ");
  scanf("%d", &budget);
  savings = savings - budget;
  printf("You now have $%d remaining.\n", savings);
  
  printf("How much would you like to allocate for entertainment? ");
  scanf("%d", &budget);
  savings = savings - budget;
  printf("You now have $%d remaining.\n", savings);
  
  printf("Let's review your budget.\n");
  printf("- Food: $%d\n", income - savings - expense);
  printf("- Rent/Mortgage: $%d\n", income - savings - expense);
  printf("- Transportation: $%d\n", income - savings - expense);
  printf("- Entertainment: $%d\n", income - savings - expense);
  
  return 0;
}