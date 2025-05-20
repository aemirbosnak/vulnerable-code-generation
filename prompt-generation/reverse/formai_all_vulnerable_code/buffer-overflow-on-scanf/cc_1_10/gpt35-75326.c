//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
  char name[30];
  float amount;
  char category[15];
  char date[15];
};

void addExpense(struct Expense expenses[], int* size) {
  printf("Enter expense details:\n");
  printf("Name: ");
  scanf("%s", expenses[*size].name);
  printf("Amount: ");
  scanf("%f", &expenses[*size].amount);
  printf("Category: ");
  scanf("%s", expenses[*size].category);
  printf("Date (dd/mm/yyyy): ");
  scanf("%s", expenses[*size].date);
  *size += 1;
  printf("Expense added successfully!\n\n");
}

void viewExpenses(struct Expense expenses[], int size) {
  printf("Expenses:\n");
  if (size == 0) {
    printf("No expenses found.\n");
    return;
  }
  for (int i = 0; i < size; i++) {
    printf("%d. Name: %s\n   Amount: %.2f\n   Category: %s\n   Date: %s\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
  }
}

void calculateTotalExpense(struct Expense expenses[], int size) {
  float total = 0;
  for (int i = 0; i < size; i++) {
    total += expenses[i].amount;
  }
  printf("Total expense: %.2f\n\n", total);
}

void viewByCategory(struct Expense expenses[], int size) {
  char category[15];
  printf("Enter category: ");
  scanf("%s", category);
  printf("Expenses for category %s:\n", category);
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(expenses[i].category, category) == 0) {
      printf("%d. Name: %s\n   Amount: %.2f\n   Date: %s\n", count+1, expenses[i].name, expenses[i].amount, expenses[i].date);
      count++;
    }
  }
  if (count == 0) {
    printf("No expenses found for category %s.\n", category);
  }
  printf("\n");
}

int main() {
  struct Expense expenses[100];
  int size = 0;
  int choice;
  do {
    printf("Expense Tracker:\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Calculate total expense\n");
    printf("4. View expenses by category\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addExpense(expenses, &size);
        break;
      case 2:
        viewExpenses(expenses, size);
        break;
      case 3:
        calculateTotalExpense(expenses, size);
        break;
      case 4:
        viewByCategory(expenses, size);
        break;
      case 0:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice, try again.\n\n");
    }
  } while (choice != 0);
  return 0;
}