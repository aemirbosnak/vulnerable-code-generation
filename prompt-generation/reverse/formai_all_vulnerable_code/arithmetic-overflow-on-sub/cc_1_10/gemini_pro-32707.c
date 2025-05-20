//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

//Prototypes
void welcome(void);
void menu(void);
void add_income(void);
void add_expense(void);
void view_report(void);
void exit_program(void);
void add_income(void);
void add_expense(void);
void view_report(void);
void exit_program(void);

//Global variables
int income = 0;
int expenses = 0;
int balance = 0;

int main() {
  welcome();
  menu();
  return 0;
}

void welcome() {
  printf("Welcome to the Surrealist Personal Finance Planner!\n");
  printf("Where dreams meet reality and money becomes a canvas.\n");
  printf("----------------------------------------------------\n");
}

void menu() {
  int choice;
  while (1) {
    printf("What would you like to do today?\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Report\n");
    printf("4. Exit Program\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_income();
        break;
      case 2:
        add_expense();
        break;
      case 3:
        view_report();
        break;
      case 4:
        exit_program();
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
}

void add_income() {
  int amount;
  printf("Enter the amount of income: ");
  scanf("%d", &amount);
  income += amount;
  balance += amount;
  printf("Income added successfully. Your current balance is %d.\n", balance);
}

void add_expense() {
  int amount;
  printf("Enter the amount of the expense: ");
  scanf("%d", &amount);
  expenses += amount;
  balance -= amount;
  printf("Expense added successfully. Your current balance is %d.\n", balance);
}

void view_report() {
  printf("Income: %d\n", income);
  printf("Expenses: %d\n", expenses);
  printf("Balance: %d\n", balance);
}

void exit_program() {
  printf("Thank you for using the Surrealist Personal Finance Planner!\n");
  printf("May your dreams of financial freedom be realized.\n");
  exit(0);
}