//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for personal finance planner
typedef struct {
  char name[50];
  char account_type[50];
  double balance;
} Account;

// Define structure for budget planner
typedef struct {
  char category[50];
  double budget;
  double spent;
} Budget;

int main() {
  // Initialize variables
  int num_accounts, num_budgets;
  Account accounts[10];
  Budget budgets[10];
  
  // Prompt user for number of accounts
  printf("Enter number of accounts: ");
  scanf("%d", &num_accounts);
  
  // Loop through accounts and get user input
  for (int i = 0; i < num_accounts; i++) {
    printf("Enter name for account %d: ", i+1);
    scanf("%s", accounts[i].name);
    
    printf("Enter account type for account %d: ", i+1);
    scanf("%s", accounts[i].account_type);
    
    printf("Enter balance for account %d: ", i+1);
    scanf("%lf", &accounts[i].balance);
  }
  
  // Prompt user for number of budgets
  printf("Enter number of budgets: ");
  scanf("%d", &num_budgets);
  
  // Loop through budgets and get user input
  for (int i = 0; i < num_budgets; i++) {
    printf("Enter category for budget %d: ", i+1);
    scanf("%s", budgets[i].category);
    
    printf("Enter budget for category %s: ", budgets[i].category);
    scanf("%lf", &budgets[i].budget);
    
    printf("Enter amount spent for category %s: ", budgets[i].category);
    scanf("%lf", &budgets[i].spent);
  }
  
  // Print account information
  printf("\nAccount Information:\n");
  for (int i = 0; i < num_accounts; i++) {
    printf("Name: %s\n", accounts[i].name);
    printf("Account Type: %s\n", accounts[i].account_type);
    printf("Balance: $%.2f\n\n", accounts[i].balance);
  }
  
  // Print budget information
  printf("\nBudget Information:\n");
  for (int i = 0; i < num_budgets; i++) {
    printf("Category: %s\n", budgets[i].category);
    printf("Budget: $%.2f\n", budgets[i].budget);
    printf("Spent: $%.2f\n\n", budgets[i].spent);
  }
  
  return 0;
}