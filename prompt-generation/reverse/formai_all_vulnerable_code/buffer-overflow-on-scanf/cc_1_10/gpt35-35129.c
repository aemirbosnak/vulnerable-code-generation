//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
  int id;
  char date[20];
  char category[50];
  char description[100];
  double amount;
};

void displayMenu();
void createExpense(struct Expense *expense, int *count);
void viewExpenses(struct Expense *expenses, int count);
void totalExpense(struct Expense *expenses, int count);
void editExpense(struct Expense *expenses, int count);

int main() {
  int choice, count=0;
  struct Expense expenses[100];
  
  do {
    displayMenu();
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        createExpense(&expenses[count], &count);
        break;
      case 2:
        viewExpenses(expenses, count);
        break;
      case 3:
        totalExpense(expenses, count);
        break;
      case 4:
        editExpense(expenses, count);
        break;
      case 5:
        printf("\nThank you for using the Expense Tracker!\n");
        break;
      default:
        printf("\nInvalid input. Please try again.\n");
    }
  } while(choice != 5);
  
  return 0;
}

void displayMenu() {
  printf("\nExpense Tracker\n");
  printf("----------------\n");
  printf("1. Create Expense\n");
  printf("2. View Expenses\n");
  printf("3. Total Expense\n");
  printf("4. Edit Expense\n");
  printf("5. Exit\n");
  printf("Enter choice: ");
}

void createExpense(struct Expense *expense, int *count) {
  printf("\nEnter the date (dd/mm/yyyy): ");
  scanf("%s", expense->date);
  printf("Enter the category: ");
  scanf("%s", expense->category);
  printf("Enter the description: ");
  scanf("%s", expense->description);
  printf("Enter the amount: ");
  scanf("%lf", &expense->amount);
  
  expense->id = *count + 1;
  *count += 1;
  
  printf("\nExpense added successfully!\n");
}

void viewExpenses(struct Expense *expenses, int count) {
  if(count == 0) {
    printf("\nNo expenses found.\n");
    return;
  }
  
  printf("\n%-5s | %-12s | %-15s | %-30s | %-8s \n", "ID", "DATE", "CATEGORY", "DESCRIPTION", "AMOUNT");
  printf("---------------------------------------------------------------------------\n");
  
  for(int i=0; i<count; i++) {
    printf("%-5d | %-12s | %-15s | %-30s | %-8.2lf \n", expenses[i].id, expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
  }
}

void totalExpense(struct Expense *expenses, int count) {
  if(count == 0) {
    printf("\nNo expenses found.\n");
    return;
  }
  
  double total = 0;
  
  for(int i=0; i<count; i++) {
    total += expenses[i].amount;
  }
  
  printf("\nTotal expense: %.2lf\n", total);
}

void editExpense(struct Expense *expenses, int count) {
  if(count == 0) {
    printf("\nNo expenses found.\n");
    return;
  }
  
  int id;
  printf("\nEnter the ID of the expense to edit: ");
  scanf("%d", &id);
  
  for(int i=0; i<count; i++) {
    if(expenses[i].id == id) {
      printf("Enter the date (dd/mm/yyyy): ");
      scanf("%s", expenses[i].date);
      printf("Enter the category: ");
      scanf("%s", expenses[i].category);
      printf("Enter the description: ");
      scanf("%s", expenses[i].description);
      printf("Enter the amount: ");
      scanf("%lf", &expenses[i].amount);
      
      printf("\nExpense updated successfully!\n");
      return;
    }
  }
  
  printf("\nExpense not found.\n");
}