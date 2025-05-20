//FormAI DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Define structure for expense record
struct Expense {
  char date[11];
  char name[50];
  float amount;
};
 
int main() {
  int n; // number of expenses
  printf("How many expenses do you want to record? ");
  scanf("%d", &n);
 
  struct Expense* expenses = (struct Expense*) malloc(n * sizeof(struct Expense)); // Allocate memory for expenses
 
  // Record expenses
  for (int i = 0; i < n; i++) {
    printf("\nExpense %d:\n", i + 1);
    printf("Date (yyyy-mm-dd): ");
    scanf("%s", &expenses[i].date);
    printf("Name: ");
    scanf("%s", &expenses[i].name);
    printf("Amount: ");
    scanf("%f", &expenses[i].amount);
  }
 
  // Display expenses
  printf("\nExpenses:\n");
  printf("%-15s %-20s %s\n", "Date", "Name", "Amount");
  for (int i = 0; i < n; i++) {
    printf("%-15s %-20s $%.2f\n", expenses[i].date, expenses[i].name, expenses[i].amount);
  }
 
  // Calculate total expenses
  float total = 0;
  for (int i = 0; i < n; i++) {
    total += expenses[i].amount;
  }
  printf("\nTotal Expenses: $%.2f\n", total);

  // Find expense by name
  printf("\nEnter expense name to search: ");
  char search_name[50];
  scanf("%s", &search_name);
  for (int i = 0; i < n; i++) {
    if (strcmp(expenses[i].name, search_name) == 0) {
      printf("Expense found:\n");
      printf("%-15s %-20s $%.2f\n", expenses[i].date, expenses[i].name, expenses[i].amount);
      break;
    }
    if (i == n - 1) { // expense not found
      printf("Expense not found.\n");
    }
  }
 
  free(expenses); // Free memory allocated for expenses
  return 0;
}