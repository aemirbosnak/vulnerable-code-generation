//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct PersonalFinancePlanner {
  int budget;
  int savings;
  int debts;
  int expenses;
  int income;
};

void print_menu() {
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please select an option:\n");
  printf("1. Add income\n");
  printf("2. Add expenses\n");
  printf("3. Add savings\n");
  printf("4. Add debts\n");
  printf("5. View financial status\n");
  printf("6. Exit\n");
}

void add_income(struct PersonalFinancePlanner *pfp) {
  printf("Enter income: ");
  scanf("%d", &pfp->income);
}

void add_expenses(struct PersonalFinancePlanner *pfp) {
  printf("Enter expenses: ");
  scanf("%d", &pfp->expenses);
}

void add_savings(struct PersonalFinancePlanner *pfp) {
  printf("Enter savings: ");
  scanf("%d", &pfp->savings);
}

void add_debts(struct PersonalFinancePlanner *pfp) {
  printf("Enter debts: ");
  scanf("%d", &pfp->debts);
}

void view_financial_status(struct PersonalFinancePlanner *pfp) {
  printf("Financial Status:\n");
  printf("Budget: %d\n", pfp->budget);
  printf("Savings: %d\n", pfp->savings);
  printf("Debts: %d\n", pfp->debts);
  printf("Expenses: %d\n", pfp->expenses);
  printf("Income: %d\n", pfp->income);
}

int main() {
  struct PersonalFinancePlanner pfp;
  int option;

  print_menu();
  scanf("%d", &option);

  while (option != 6) {
    switch (option) {
      case 1:
        add_income(&pfp);
        break;
      case 2:
        add_expenses(&pfp);
        break;
      case 3:
        add_savings(&pfp);
        break;
      case 4:
        add_debts(&pfp);
        break;
      case 5:
        view_financial_status(&pfp);
        break;
    }
    print_menu();
    scanf("%d", &option);
  }

  return 0;
}