//FormAI DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of expenses
#define MAX_EXPENSES 100

// Define maximum length of expense description
#define MAX_DESC_LENGTH 50

// Define maximum length of expense type
#define MAX_TYPE_LENGTH 20

// Define maximum length of expense date
#define MAX_DATE_LENGTH 15

// Define expense structure
struct Expense {
  char description[MAX_DESC_LENGTH];
  char type[MAX_TYPE_LENGTH];
  float amount;
  char date[MAX_DATE_LENGTH];
};

// Define function to print menu and get user input
int printMenu() {
  int choice;

  printf("\nWelcome to the cheerful Expense Tracker!\n");
  printf("1. Add Expense\n");
  printf("2. Delete Expense\n");
  printf("3. View All Expenses\n");
  printf("4. View Expenses by Type\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  return choice;
}

// Define function to add expense
void addExpense(struct Expense expenses[], int *numExpenses) {
  char desc[MAX_DESC_LENGTH], type[MAX_TYPE_LENGTH], date[MAX_DATE_LENGTH];
  float amount;

  printf("\nEnter expense description: ");
  scanf(" %[^\n]s", desc);

  printf("Enter expense type: ");
  scanf(" %[^\n]s", type);

  printf("Enter expense amount: ");
  scanf("%f", &amount);

  printf("Enter expense date (dd/mm/yyyy): ");
  scanf(" %[^\n]s", date);

  strcpy(expenses[*numExpenses].description, desc);
  strcpy(expenses[*numExpenses].type, type);
  expenses[*numExpenses].amount = amount;
  strcpy(expenses[*numExpenses].date, date);

  printf("\nExpense added successfully!\n");

  (*numExpenses)++;
}

// Define function to delete expense
void deleteExpense(struct Expense expenses[], int *numExpenses) {
  int i, choice;

  printf("\nSelect the expense number to delete (1-%d): ", *numExpenses);

  for (i = 0; i < *numExpenses; i++) {
    printf("\n%d. %s (%s) - %.2f on %s", i + 1, expenses[i].description, expenses[i].type, expenses[i].amount, expenses[i].date);
  }

  printf("\n\nEnter your choice: ");
  scanf("%d", &choice);

  if (choice < 1 || choice > *numExpenses) {
    printf("\nInvalid choice!\n");
    return;
  }

  for (i = choice - 1; i < *numExpenses - 1; i++) {
    strcpy(expenses[i].description, expenses[i + 1].description);
    strcpy(expenses[i].type, expenses[i + 1].type);
    expenses[i].amount = expenses[i + 1].amount;
    strcpy(expenses[i].date, expenses[i + 1].date);
  }

  (*numExpenses)--;

  printf("\nExpense deleted successfully!\n");
}

// Define function to view all expenses
void viewAllExpenses(struct Expense expenses[], int *numExpenses) {
  int i;

  if (*numExpenses == 0) {
    printf("\nThere are no expenses to display!\n");
    return;
  }

  printf("\nAll Expenses:\n");

  for (i = 0; i < *numExpenses; i++) {
    printf("\n%d. %s (%s) - %.2f on %s", i + 1, expenses[i].description, expenses[i].type, expenses[i].amount, expenses[i].date);
  }
}

// Define function to view expenses by type
void viewExpensesByType(struct Expense expenses[], int *numExpenses) {
  int i;
  char type[MAX_TYPE_LENGTH];

  if (*numExpenses == 0) {
    printf("\nThere are no expenses to display!\n");
    return;
  }

  printf("\nEnter expense type to display: ");
  scanf(" %[^\n]s", type);

  printf("\nExpenses for type '%s':\n", type);

  for (i = 0; i < *numExpenses; i++) {
    if (strcmp(expenses[i].type, type) == 0) {
      printf("\n%d. %s (%s) - %.2f on %s", i + 1, expenses[i].description, expenses[i].type, expenses[i].amount, expenses[i].date);
    }
  }
}

// Main function
int main() {
  struct Expense expenses[MAX_EXPENSES] = {0};
  int numExpenses = 0;
  int choice;

  do {
    choice = printMenu();

    switch (choice) {
      case 1:
        addExpense(expenses, &numExpenses);
        break;
      case 2:
        deleteExpense(expenses, &numExpenses);
        break;
      case 3:
        viewAllExpenses(expenses, &numExpenses);
        break;
      case 4:
        viewExpensesByType(expenses, &numExpenses);
        break;
      case 5:
        printf("\nThank you for using the cheerful Expense Tracker!\n");
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}