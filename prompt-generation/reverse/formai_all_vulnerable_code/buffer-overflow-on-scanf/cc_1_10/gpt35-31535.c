//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
// This program keeps track of expenses for a user

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
  char name[50];
  float amount;
  char category[30];
};

void printMenu() {
  printf("=======================\n");
  printf("      EXPENSE TRACKER\n");
  printf("=======================\n");
  printf("1. Add a new expense\n");
  printf("2. View all expenses\n");
  printf("3. View expenses by category\n");
  printf("4. Quit\n");
  printf("=======================\n");
}

int main() {
  struct Expense expenses[MAX_EXPENSES];
  int numExpenses = 0; // keeps track of number of expenses added by user

  while (1) { // loop runs until user quits
    printMenu();
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: {
        printf("\nEnter expense name: ");
        scanf("%s", expenses[numExpenses].name);
        printf("Enter amount ($): ");
        scanf("%f", &expenses[numExpenses].amount);
        printf("Enter category: ");
        scanf("%s", expenses[numExpenses].category);
        numExpenses++;
        printf("\nExpense added successfully!\n\n");
        break;
      }
      case 2: {
        if (numExpenses == 0) {
          printf("\nNo expenses added yet!\n\n");
          break;
        }
        printf("\nAll expenses:\n");
        for (int i = 0; i < numExpenses; i++) {
          printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
        }
        printf("\n");
        break;
      }
      case 3: {
        if (numExpenses == 0) {
          printf("\nNo expenses added yet!\n\n");
          break;
        }
        char searchCategory[30];
        printf("\nEnter category to search for: ");
        scanf("%s", searchCategory);
        printf("\nExpenses in category %s:\n", searchCategory);
        for (int i = 0; i < numExpenses; i++) {
          if (strcmp(expenses[i].category, searchCategory) == 0) {
            printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
          }
        }
        printf("\n");
        break;
      }
      case 4: {
        printf("\nThank you for using the expense tracker! Goodbye!\n");
        exit(0);
        break;
      }
      default: {
        printf("\nInvalid choice! Please try again.\n\n");
        break;
      }
    }
  }

  return 0;
}