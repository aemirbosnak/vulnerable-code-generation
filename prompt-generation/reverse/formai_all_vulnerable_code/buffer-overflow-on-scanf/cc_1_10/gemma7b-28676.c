//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void main()
{
  int expense_type;
  char expense_name[20];
  int expense_amount;

  printf("Welcome to the Exquisite Expense Tracker!\n");
  printf("Please select an expense type:\n");
  printf("1. Food\n");
  printf("2. Transportation\n");
  printf("3. Shopping\n");
  printf("4. Entertainment\n");
  printf("Enter your selection:");

  scanf("%d", &expense_type);

  switch (expense_type)
  {
    case 1:
      printf("Please enter the name of your expense:");
      scanf("%s", expense_name);
      printf("Enter the amount of the expense:");
      scanf("%d", &expense_amount);
      printf("Your expense has been recorded: %s, %d\n", expense_name, expense_amount);
      break;

    case 2:
      printf("Please enter the name of your expense:");
      scanf("%s", expense_name);
      printf("Enter the amount of the expense:");
      scanf("%d", &expense_amount);
      printf("Your expense has been recorded: %s, %d\n", expense_name, expense_amount);
      break;

    case 3:
      printf("Please enter the name of your expense:");
      scanf("%s", expense_name);
      printf("Enter the amount of the expense:");
      scanf("%d", &expense_amount);
      printf("Your expense has been recorded: %s, %d\n", expense_name, expense_amount);
      break;

    case 4:
      printf("Please enter the name of your expense:");
      scanf("%s", expense_name);
      printf("Enter the amount of the expense:");
      scanf("%d", &expense_amount);
      printf("Your expense has been recorded: %s, %d\n", expense_name, expense_amount);
      break;

    default:
      printf("Invalid selection\n");
  }

  return;
}