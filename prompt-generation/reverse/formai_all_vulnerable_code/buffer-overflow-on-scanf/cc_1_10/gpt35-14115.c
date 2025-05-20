//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>

int main() {
  int choice, amount;
  int total_expenses = 0;
  int food_expenses = 0;
  int travel_expenses = 0;
  int shopping_expenses = 0;
  int other_expenses = 0;

  while (1) {
    printf("\nExpense Tracker Menu\n");
    printf("---------------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Total Expenses\n");
    printf("3. View Category Wise Expenses\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nAdd Expense Menu\n");
        printf("---------------------------\n");
        printf("1. Food\n");
        printf("2. Travel\n");
        printf("3. Shopping\n");
        printf("4. Others\n");
        printf("\nEnter expense category: ");
        scanf("%d", &choice);
        printf("Enter expense amount: ");
        scanf("%d", &amount);

        total_expenses += amount;

        switch (choice) {
          case 1:
            food_expenses += amount;
            break;
          case 2:
            travel_expenses += amount;
            break;
          case 3:
            shopping_expenses += amount;
            break;
          case 4:
            other_expenses += amount;
            break;
          default:
            printf("\nInvalid expense category!\n");
            break;
        }
        break;
      case 2:
        printf("\nTotal Expenses\n");
        printf("---------------------------\n");
        printf("Total Expenses: %d\n", total_expenses);
        break;
      case 3:
        printf("\nCategory Wise Expenses\n");
        printf("---------------------------\n");
        printf("Food: %d\n", food_expenses);
        printf("Travel: %d\n", travel_expenses);
        printf("Shopping: %d\n", shopping_expenses);
        printf("Others: %d\n", other_expenses);
        break;
      case 4:
        printf("\nThank you for using Expense Tracker!\n");
        return 0;
      default:
        printf("\nInvalid choice!\n");
        break;
    }
  }
}