//FormAI DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
  char name[50];
  float amount;
  char category[20];
};

int numOfExpenses = 0;
float totalExpenses = 0.0;
struct Expense expenses[MAX_EXPENSES];

void printMenu() {
  printf("\n\nExpense Tracker Menu:\n");
  printf("1. Add an Expense\n");
  printf("2. Display all Expenses\n");
  printf("3. Display Expenses by Category\n");
  printf("4. Display Total Expenses\n");
  printf("5. Exit\n");
  printf("Enter your choice (1-5): ");
}

void addExpense() {
  if (numOfExpenses == MAX_EXPENSES) {
    printf("Cannot add another expense. Expense limit reached.\n");
    return;
  }
  
  struct Expense expense;
  printf("Enter expense name: ");
  scanf("%s", expense.name);
  printf("Enter amount: ");
  scanf("%f", &expense.amount);
  printf("Enter category: ");
  scanf("%s", expense.category);
  
  expenses[numOfExpenses] = expense;
  numOfExpenses++;
  totalExpenses += expense.amount;
}

void displayAllExpenses() {
  printf("\n\nExpenses:\n");
  for (int i = 0; i < numOfExpenses; i++) {
    printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
  }
}

void displayExpensesByCategory() {
  char category[20];
  printf("Enter category to display: ");
  scanf("%s", category);
  
  printf("\n\nExpenses in Category %s:\n", category);
  for (int i = 0; i < numOfExpenses; i++) {
    if (strcmp(expenses[i].category, category) == 0) {
      printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
    }
  }
}

void displayTotalExpenses() {
  printf("\n\nTotal Expenses: $%.2f\n", totalExpenses);
}

int main() {
  int choice = 0;
  
  do {
    printMenu();
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        addExpense();
        break;
      case 2:
        displayAllExpenses();
        break;
      case 3:
        displayExpensesByCategory();
        break;
      case 4:
        displayTotalExpenses();
        break;
      case 5:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
    
  } while (choice != 5);
  
  return 0;
}