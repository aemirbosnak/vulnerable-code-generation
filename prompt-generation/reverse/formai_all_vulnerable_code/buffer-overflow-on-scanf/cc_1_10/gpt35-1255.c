//FormAI DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
struct ExpenseTracker {
  char name[20];
  float amount;
};
 
typedef struct ExpenseTracker EXP;
 
void display_menu() {
  printf("Welcome to your Expense Tracker\n");
  printf("1. Add an Expense\n");
  printf("2. View Expenses\n");
  printf("3. Total Expenses\n");
  printf("4. Exit\n");
}
 
float total_expenses(EXP expenses[], int n) {
  float total = 0.0;
  int i;
  for (i = 0; i < n; i++) {
    total += expenses[i].amount;
  }
  return total;
}
 
void add_expense(EXP expenses[], int *n) {
  printf("Enter expense name: ");
  scanf("%s", expenses[*n].name);
 
  printf("Enter amount: $");
  scanf("%f", &expenses[*n].amount);
   
  *n = *n + 1;
   
  printf("Expense added successfully!\n");
}
 
void view_expenses(EXP expenses[], int n) {
  int i;
  printf("Expenses:\n");
  for (i = 0; i < n; i++) {
    printf("%d. Expense Name: %s Amount: $%.2f\n", i+1, expenses[i].name, expenses[i].amount);
  }
}
 
int main() {
  EXP expenses[100];
  int choice, n = 0;
 
  while (1) {
    display_menu();
 
    printf("Enter your choice: ");
    scanf("%d", &choice);
 
    switch (choice) {
      case 1:
        add_expense(expenses, &n);
        break;
      case 2:
        view_expenses(expenses, n);
        break;
      case 3:
        printf("Total Expenses: $%.2f\n", total_expenses(expenses, n));
        break;
      case 4:
        printf("Thank you for using your Expense Tracker!\n");
        return 0;
      default:
        printf("Invalid choice! Please try again.\n");
    }
  }
 
  return 0;
}