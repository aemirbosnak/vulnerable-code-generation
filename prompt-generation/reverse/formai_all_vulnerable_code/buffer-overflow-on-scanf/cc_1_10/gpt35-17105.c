//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct Expense {
  char item[50];  // Name of the item or product
  float cost;     // Cost of the item or product
  char date[11];  // Date of the purchase (DD/MM/YYYY)
};

void print_menu() {
  printf("\n");
  printf("Expense Tracker\n");
  printf("================\n");
  printf("1. Add Expense\n");
  printf("2. View All Expenses\n");
  printf("3. Exit\n");
  printf("================\n");
}

int main() {
  struct Expense expenses[MAX_ENTRIES];
  int num_expenses = 0;

  while (1) {
    print_menu();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      // Add an expense
      if (num_expenses >= MAX_ENTRIES) {
        printf("Maximum number of expenses reached!\n");
        continue;
      }

      printf("Enter item name: ");
      scanf("%s", expenses[num_expenses].item);

      printf("Enter cost: ");
      scanf("%f", &expenses[num_expenses].cost);

      printf("Enter date (DD/MM/YYYY): ");
      scanf("%s", expenses[num_expenses].date);

      num_expenses++;

      printf("Expense has been added!\n");
    } else if (choice == 2) {
      // View all expenses
      if (num_expenses == 0) {
        printf("No expenses to view!\n");
        continue;
      }

      printf("\n");

      // Print header
      printf("%-30s %-10s %-10s\n", "Item", "Cost", "Date");
      printf("--------------------------------------------------\n");

      // Print expenses
      for (int i = 0; i < num_expenses; i++) {
        printf("%-30s $%-9.2f %-10s\n", expenses[i].item, expenses[i].cost, expenses[i].date);
      }

      printf("\n");
    } else if (choice == 3) {
      // Exit
      printf("Exiting Expense Tracker...\n");
      break;
    } else {
      printf("Invalid choice!\n");
    }
  }

  return 0;
}