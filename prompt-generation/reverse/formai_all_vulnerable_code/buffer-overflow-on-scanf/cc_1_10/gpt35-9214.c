//FormAI DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the Expense Tracker\n\n");

  int choice, expenses[30], total_expenses = 0;
  char dates[30][15], categories[30][15], descriptions[30][40];

  do {
    printf("What would you like to do?\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter the Date (dd/mm/yyyy): ");
        scanf("%s", dates[total_expenses]);

        printf("Enter the Category: ");
        scanf("%s", categories[total_expenses]);

        printf("Enter the Description: ");
        scanf("%s", descriptions[total_expenses]);

        printf("Enter the Amount: ");
        scanf("%d", &expenses[total_expenses]);

        total_expenses++;

        printf("\nExpense Added!\n\n");
        break;

      case 2:
        printf("\nExpenses:\n\n");
        printf("Date\t\tCategory\tDescription\t\tAmount\n\n");

        for (int i = 0; i < total_expenses; i++) {
          printf("%s\t%s\t%s\t\t%d\n", dates[i], categories[i], descriptions[i], expenses[i]);
        }

        printf("\nTotal Expenses: %d\n\n", total_expenses);
        break;

      case 3:
        printf("\nThank you for using Expense Tracker. Goodbye!\n");
        break;

      default:
        printf("\nInvalid choice. Please try again.\n\n");
        break;
    }
  } while (choice != 3);

  return 0;
}