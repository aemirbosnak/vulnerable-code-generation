//FormAI DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct expense {
  char name[50];
  double amount;
  char date[11]; // in format "yyyy-mm-dd"
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(){
  if(num_expenses >= MAX_EXPENSES){
    printf("Maximum number of expenses exceeded!\n");
    return;
  }
  expense new_expense;
  printf("Enter the name of the expense: ");
  scanf("%s", new_expense.name);
  printf("Enter the amount of the expense: ");
  scanf("%lf", &new_expense.amount);
  printf("Enter the date of the expense (yyyy-mm-dd): ");
  scanf("%s", new_expense.date);
  expenses[num_expenses++] = new_expense;
  printf("Expense added successfully!\n");
}

void print_expense(expense ex) {
  printf("%s\t%.2lf\t%s\n", ex.name, ex.amount, ex.date);
}

void print_expenses() {
  printf("Name\tAmount\tDate\n");
  for(int i=0; i<num_expenses; i++) {
    print_expense(expenses[i]);
  }
}

void total_expenses() {
  double total = 0.0;
  for(int i=0; i<num_expenses; i++) {
    total += expenses[i].amount;
  }
  printf("Total expenses: %.2lf\n", total);
}

int main() {
  int choice;
  do {
    printf("\nExpense Tracker\n");
    printf("================\n");
    printf("1. Add an expense\n");
    printf("2. Print all expenses\n");
    printf("3. Calculate total expenses\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_expense();
        break;
      case 2:
        print_expenses();
        break;
      case 3:
        total_expenses();
        break;
      case 4:
        printf("Exiting program. Thank you for using our Expense Tracker!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while(choice != 4);

  return 0;
}