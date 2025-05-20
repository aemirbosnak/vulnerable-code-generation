//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Welcome to Personal Finance Planner!\n\n");

  float total_amount, expenses, income, savings;
  char choice;

  printf("Enter your total monthly income: ");
  scanf("%f", &income);

  printf("Enter your total monthly expenses: ");
  scanf("%f", &expenses);

  total_amount = income - expenses;

  if (total_amount < 0)
  {
    printf("\nYou are in debt! Please consider reducing your expenses.\n\n");
  }
  else
  {
    printf("\nCongrats! You have a monthly surplus of %.2f.\n\n", total_amount);
  }

  printf("Do you want to save some money? (y/n)\n");
  scanf(" %c", &choice);

  if (choice == 'y' || choice == 'Y')
  {
    printf("Enter the amount you want to save: ");
    scanf("%f", &savings);

    if (savings > total_amount)
    {
      printf("\nYou don't have enough money to save that much. Please try again.\n\n");
    }
    else
    {
      total_amount -= savings;
      printf("\nYou have successfully saved %.2f. Your remaining balance is %.2f.\n\n", savings, total_amount);
    }
  }
  else if (choice == 'n' || choice == 'N')
  {
    printf("\nOkay, no problem. Your remaining balance is %.2f.\n\n", total_amount);
  }
  else
  {
    printf("\nInvalid choice. Please try again.\n\n");
  }

  printf("Thank you for using Personal Finance Planner!\n");

  return 0;
}