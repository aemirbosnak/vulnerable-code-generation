//FormAI DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 1000

struct Expense {
  char description[50];
  float cost;
  int day;
  int month;
  int year;
};

void addExpense(struct Expense expenses[], int *totalExpenses) {
  char desc[50];
  float cost;
  int day, month, year;
  
  printf("Enter expense description: ");
  scanf(" %[^\n]s", desc);
  
  printf("Enter expense cost: ");
  scanf("%f", &cost);
  
  printf("Enter expense date (DD/MM/YYYY format): ");
  scanf("%d/%d/%d", &day, &month, &year);
  
  struct Expense newExpense = {desc, cost, day, month, year};
  expenses[*totalExpenses] = newExpense;
  (*totalExpenses)++;
}

void viewExpenses(struct Expense expenses[], int totalExpenses) {
  printf("%-15s%-10s%-15s\n", "Date", "Cost", "Description");
  printf("----------------------------------------\n");
  for (int i = 0; i < totalExpenses; i++) {
    printf("%02d/%02d/%04d    $%-7.2f   %s\n", expenses[i].day, expenses[i].month, expenses[i].year,
           expenses[i].cost, expenses[i].description);
  }
  printf("\n");
}

void searchExpense(struct Expense expenses[], int totalExpenses) {
  char desc[50];
  printf("Enter description to search for: ");
  scanf(" %[^\n]s", desc);
  
  int found = 0;
  for (int i = 0; i < totalExpenses; i++) {
    if (strcmp(expenses[i].description, desc) == 0) {
      printf("%-15s%-10s%-15s\n", "Date", "Cost", "Description");
      printf("----------------------------------------\n");
      printf("%02d/%02d/%04d    $%-7.2f   %s\n\n", expenses[i].day, expenses[i].month,
             expenses[i].year, expenses[i].cost, expenses[i].description);
      found = 1;
      break;
    }
  }
  
  if (!found) {
    printf("No expenses found with description \"%s\".\n\n", desc);
  }
}

int main() {
  struct Expense expenses[MAX_EXPENSES];
  int totalExpenses = 0;
  int choice;
  
  do {
    printf("MENU\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Search expense by description\n");
    printf("4. Exit\n");
    
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        if (totalExpenses == MAX_EXPENSES) {
          printf("Error: Maximum number of expenses reached.\n\n");
        } else {
          printf("\nADD EXPENSE\n");
          addExpense(expenses, &totalExpenses);
          printf("Expense added successfully.\n\n");
        }
        break;
      case 2:
        printf("\nVIEW EXPENSES\n");
        viewExpenses(expenses, totalExpenses);
        break;
      case 3:
        printf("\nSEARCH EXPENSE\n");
        searchExpense(expenses, totalExpenses);
        break;
      case 4:
        printf("\nThank you for using the expense tracker!\n");
        exit(0);
      default:
        printf("Error: Invalid choice. Please enter a number from 1 to 4.\n\n");
    }
  } while (1);
  
  return 0;
}