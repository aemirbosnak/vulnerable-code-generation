//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// struct to store expense details
struct Expense {
  char category[20];
  float amount;
  char date[15];
};

// function to add an expense to the tracker
void addExpense(struct Expense expenses[], int *count) {
  printf("Category: ");
  scanf("%s", expenses[*count].category);
  printf("Amount: ");
  scanf("%f", &expenses[*count].amount);
  printf("Date (DD/MM/YYYY): ");
  scanf("%s", expenses[*count].date);
  (*count)++;
  printf("Expense added successfully!\n");
}

// function to view all expenses in the tracker
void viewExpenses(struct Expense expenses[], int count) {
  float total = 0.0;
  printf("| %-20s | %-10s | %-15s |\n", "Category", "Amount", "Date");
  printf("|---------------------|-----------|----------------|\n");
  for (int i = 0; i < count; i++) {
    printf("| %-20s | %9.2f | %-15s |\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    total += expenses[i].amount;
  }
  printf("|---------------------|-----------|----------------|\n");
  printf("| Total: %35.2f |\n", total);
}

// main function to run the expense tracker
int main() {
  int count = 0; // count of total expenses
  struct Expense expenses[100]; // array to store expenses

  // menu to choose option
  int choice;
  do {
    printf("\nExpense Tracker\n\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addExpense(expenses, &count);
        break;
      case 2:
        if (count == 0) {
          printf("No expenses found.\n");
        } else {
          viewExpenses(expenses, count);
        }
        break;
      case 3:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
    }

  } while (choice != 3);

  return 0;
}