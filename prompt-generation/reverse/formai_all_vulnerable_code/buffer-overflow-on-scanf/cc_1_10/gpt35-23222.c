//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef enum {
  GROCERIES,
  TRANSPORTATION,
  ENTERTAINMENT,
  UTILITIES
} ExpenseType;

typedef struct {
  int id;
  ExpenseType type;
  double amount;
  Date date;
} Expense;

void display_menu() {
  printf("************************************\n");
  printf("********** EXPENSE TRACKER **********\n");
  printf("************************************\n\n");
  printf("Select an option:\n");
  printf("1. Add expense\n");
  printf("2. View expenses\n");
  printf("3. Exit\n\n");
}

void add_expense(Expense *expenses, int *num_expenses) {
  Expense expense;

  printf("Enter expense id: ");
  scanf("%d", &expense.id);

  printf("Select expense type:\n");
  printf("1. Groceries\n");
  printf("2. Transportation\n");
  printf("3. Entertainment\n");
  printf("4. Utilities\n");
  printf("Option: ");
  int option;
  scanf("%d", &option);

  switch (option) {
    case 1:
      expense.type = GROCERIES;
      break;
    case 2:
      expense.type = TRANSPORTATION;
      break;
    case 3:
      expense.type = ENTERTAINMENT;
      break;
    case 4:
      expense.type = UTILITIES;
      break;
    default:
      printf("Invalid option\n");
      return;
  }

  printf("Enter expense amount: ");
  scanf("%lf", &expense.amount);

  printf("Enter expense date:\n");
  printf("Day: ");
  scanf("%d", &expense.date.day);
  printf("Month: ");
  scanf("%d", &expense.date.month);
  printf("Year: ");
  scanf("%d", &expense.date.year);

  expenses[*num_expenses] = expense;
  (*num_expenses)++;
}

void view_expenses(Expense *expenses, int num_expenses) {
  if (num_expenses == 0) {
    printf("No expenses found\n");
    return;
  }

  printf("************************************\n");
  printf("************* EXPENSES *************\n");
  printf("************************************\n\n");
  printf("ID\tTYPE\tAMOUNT\tDATE\n");

  for (int i = 0; i < num_expenses; i++) {
    Expense expense = expenses[i];

    char type_str[15];

    if (expense.type == GROCERIES) {
      sprintf(type_str, "Groceries");
    } else if (expense.type == TRANSPORTATION) {
      sprintf(type_str, "Transportation");
    } else if (expense.type == ENTERTAINMENT) {
      sprintf(type_str, "Entertainment");
    } else if (expense.type == UTILITIES) {
      sprintf(type_str, "Utilities");
    }

    printf("%d\t%s\t%.2f\t%d/%d/%d\n", expense.id, type_str, expense.amount, expense.date.day, expense.date.month, expense.date.year);
  }
}

int main() {
  Expense expenses[100];
  int num_expenses = 0;

  srand(time(NULL));

  display_menu();

  int option = 0;
  while (option != 3) {
    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_expense(expenses, &num_expenses);
        break;
      case 2:
        view_expenses(expenses, num_expenses);
        break;
      case 3:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option\n");
        break;
    }
  }

  return 0;
}