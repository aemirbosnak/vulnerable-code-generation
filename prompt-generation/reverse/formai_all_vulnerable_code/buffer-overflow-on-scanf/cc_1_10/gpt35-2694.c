//FormAI DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
  char description[50];
  float amount;
  char category[20];
};

struct Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
  if (num_expenses >= MAX_EXPENSES) {
    printf("Error: Maximum number of expenses reached\n");
    return;
  }

  printf("Enter expense description: ");
  scanf("%s", expenses[num_expenses].description);

  printf("Enter expense amount: ");
  scanf("%f", &expenses[num_expenses].amount);

  printf("Enter expense category: ");
  scanf("%s", expenses[num_expenses].category);

  num_expenses++;

  printf("Expense added successfully\n");
}

void view_expenses() {
  if (num_expenses == 0) {
    printf("No expenses to view\n");
    return;
  }

  printf("%-20s %-10s %-20s\n", "Description", "Amount", "Category");
  for (int i = 0; i < num_expenses; i++) {
    struct Expense expense = expenses[i];
    printf("%-20s %-10.2f %-20s\n", expense.description, expense.amount, expense.category);
  }
}

void write_to_file() {
  FILE *file = fopen("expenses.txt", "w");
  if (file == NULL) {
    printf("Error: Failed to open expenses file\n");
    return;
  }

  fprintf(file, "%-20s %-10s %-20s\n", "Description", "Amount", "Category");
  for (int i = 0; i < num_expenses; i++) {
    struct Expense expense = expenses[i];
    fprintf(file, "%-20s %-10.2f %-20s\n", expense.description, expense.amount, expense.category);
  }

  fclose(file);
  printf("Expenses saved to file successfully\n");
}

void read_from_file() {
  FILE *file = fopen("expenses.txt", "r");
  if (file == NULL) {
    printf("Error: Failed to open expenses file\n");
    return;
  }

  int count = 0;
  char line[100];
  while (fgets(line, sizeof(line), file)) {
    if (count == 0) {
      // Skip header
      count++;
      continue;
    }

    char *description = strtok(line, " ");
    float amount = atof(strtok(NULL, " "));
    char *category = strtok(NULL, "\n");

    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].category, category);

    num_expenses++;
  }

  fclose(file);
  printf("Expenses loaded from file successfully\n");
}

int main() {
  int choice;

  printf("===================\n");
  printf("EXPENSE TRACKER MENU\n");
  printf("===================\n");
  printf("1. Add expense\n");
  printf("2. View expenses\n");
  printf("3. Write expenses to file\n");
  printf("4. Load expenses from file\n");
  printf("5. Exit\n");

  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_expense();
        break;
      case 2:
        view_expenses();
        break;
      case 3:
        write_to_file();
        break;
      case 4:
        read_from_file();
        break;
      case 5:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice. Try again.\n");
    }
  } while(choice != 5);

  return 0;
}