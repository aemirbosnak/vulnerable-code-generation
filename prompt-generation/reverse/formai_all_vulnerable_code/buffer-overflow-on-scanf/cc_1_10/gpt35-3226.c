//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printMenu();
void addExpense(float expenseAmount, char* expenseCategory);
void viewExpenses();
void viewTotalExpenses();

// Structure to hold expense information
struct Expense {
  float amount;
  char category[20];
};

// Array to hold all expenses
struct Expense expenses[100];
int numExpenses = 0;

// Main function
int main()
{
  int choice;
  float expenseAmount;
  char expenseCategory[20];
  
  while(1) {
    printMenu();
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("Enter expense amount: ");
        scanf("%f", &expenseAmount);
        printf("Enter expense category: ");
        scanf("%s", expenseCategory);
        addExpense(expenseAmount, expenseCategory);
        break;
      case 2:
        viewExpenses();
        break;
      case 3:
        viewTotalExpenses();
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice, please try again.\n");
    }
  }
  
  return 0;
}

// Function to print menu
void printMenu() {
  printf("\nExpense Tracker\n");
  printf("----------------\n");
  printf("1. Add expense\n");
  printf("2. View expenses\n");
  printf("3. View total expenses\n");
  printf("4. Exit\n");
  printf("Enter choice: ");
}

// Function to add expense
void addExpense(float expenseAmount, char* expenseCategory) {
  expenses[numExpenses].amount = expenseAmount;
  strcpy(expenses[numExpenses].category, expenseCategory);
  numExpenses++;
  printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses() {
  printf("\nExpense\t\tCategory\n");
  printf("------------------------\n");
  for(int i=0; i<numExpenses; i++) {
    printf("%.2f\t\t%s\n", expenses[i].amount, expenses[i].category);
  }
}

// Function to view total expenses
void viewTotalExpenses() {
  float total = 0.0;
  for(int i=0; i<numExpenses; i++) {
    total += expenses[i].amount;
  }
  printf("\nTotal expenses: $%.2f\n", total);
}