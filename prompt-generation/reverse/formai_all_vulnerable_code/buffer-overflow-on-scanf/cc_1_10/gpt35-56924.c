//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to store expense details
struct expense {
  char *note;
  float amount;
  char *category;
};

// Function to add a new expense
void addExpense(struct expense expenses[], int *count) {
  char note[100], category[50];
  float amount;

  printf("Enter expense note: ");
  fflush(stdin);
  fgets(note, 100, stdin);
  note[strcspn(note, "\n")] = 0;

  printf("Enter amount: ");
  scanf("%f", &amount);

  printf("Enter category: ");
  fflush(stdin);
  fgets(category, 50, stdin);
  category[strcspn(category, "\n")] = 0;

  expenses[*count].note = strdup(note);
  expenses[*count].amount = amount;
  expenses[*count].category = strdup(category);

  (*count)++;
  printf("\nExpense added successfully!\n\n");
}

// Function to display all expenses
void displayExpenses(struct expense expenses[], int count) {
  if (count == 0) {
    printf("\nNo expenses to display.\n\n");
    return;
  }

  printf("\nExpense Details:\n\n");

  for (int i = 0; i < count; i++) {
    printf("Note: %s\n", expenses[i].note);
    printf("Amount: %.2f\n", expenses[i].amount);
    printf("Category: %s\n\n", expenses[i].category);
  }
}

// Function to search for expenses by category
void searchExpenses(struct expense expenses[], int count) {
  if (count == 0) {
    printf("\nNo expenses to search.\n\n");
    return;
  }

  char searchCategory[50];
  printf("\nEnter category to search for: ");
  fflush(stdin);
  fgets(searchCategory, 50, stdin);
  searchCategory[strcspn(searchCategory, "\n")] = 0;

  printf("\nExpenses under category '%s':\n\n", searchCategory);

  int found = 0;
  for (int i = 0; i < count; i++) {
    if (strcmp(expenses[i].category, searchCategory) == 0) {
      printf("Note: %s\n", expenses[i].note);
      printf("Amount: %.2f\n\n", expenses[i].amount);
      found = 1;
    }
  }

  if (!found) {
    printf("No expenses under category '%s' found.\n\n", searchCategory);
  }
}

// Main function
int main() {
  struct expense expenses[MAX_ENTRIES];
  int count = 0;

  int option;

  while (1) {
    printf("Expense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Search Expenses by Category\n");
    printf("4. Exit\n\n");

    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        addExpense(expenses, &count);
        break;

      case 2:
        displayExpenses(expenses, count);
        break;

      case 3:
        searchExpenses(expenses, count);
        break;

      case 4:
        printf("\nThank you for using Expense Tracker.\n\n");
        exit(0);
        break;

      default:
        printf("\nInvalid option. Try again.\n\n");
        break;
    }
  }

  return 0;
}