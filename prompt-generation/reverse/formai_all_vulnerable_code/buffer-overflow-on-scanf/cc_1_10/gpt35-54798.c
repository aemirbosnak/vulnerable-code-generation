//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

const int MAX_EXPENSES = 100;

struct Expense {
  char name[50];
  float cost;
};

void printMenu() {
  printf("\n1. Add expense");
  printf("\n2. Print all expenses");
  printf("\n3. Calculate total expenses");
  printf("\n4. Calculate average expense");
  printf("\n5. Exit\n");
}

int main() {
  struct Expense expenses[MAX_EXPENSES];
  int numExpenses = 0;
  float totalExpense = 0;

  int choice;
  do {
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        if (numExpenses == MAX_EXPENSES) {
          printf("\nMaximum number of expenses reached\n");
        } else {
          printf("\nEnter name of expense: ");
          scanf("%s", expenses[numExpenses].name);
          printf("Enter cost of expense: ");
          scanf("%f", &expenses[numExpenses].cost);
          totalExpense += expenses[numExpenses].cost;
          numExpenses++;
          printf("\nExpense added successfully\n");
        }
        break;
      case 2:
        if (numExpenses == 0) {
          printf("\nNo expenses added yet\n");
        } else {
          printf("\nList of expenses:\n");
          for (int i = 0; i < numExpenses; i++) {
            printf("%d. %s - $%.2f\n", i+1, expenses[i].name, expenses[i].cost);
          }
        }
        break;
      case 3:
        if (numExpenses == 0) {
          printf("\nNo expenses added yet\n");
        } else {
          printf("\nTotal expenses: $%.2f\n", totalExpense);
        }
        break;
      case 4:
        if (numExpenses == 0) {
          printf("\nNo expenses added yet\n");
        } else {
          printf("\nAverage expense: $%.2f\n", totalExpense / numExpenses);
        }
        break;
      case 5:
        printf("\nExiting program\n");
        break;
      default:
        printf("\nInvalid choice\n");
    }
  } while (choice != 5);

  return 0;
}