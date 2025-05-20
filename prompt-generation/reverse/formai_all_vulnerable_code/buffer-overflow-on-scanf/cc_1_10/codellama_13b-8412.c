//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100
#define MAX_INCOMES 100

struct expense {
  char name[50];
  float amount;
};

struct income {
  char name[50];
  float amount;
};

void print_expenses(struct expense* expenses, int num_expenses) {
  printf("Expenses:\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("  %s: $%.2f\n", expenses[i].name, expenses[i].amount);
  }
}

void print_incomes(struct income* incomes, int num_incomes) {
  printf("Incomes:\n");
  for (int i = 0; i < num_incomes; i++) {
    printf("  %s: $%.2f\n", incomes[i].name, incomes[i].amount);
  }
}

void print_balance(float total_income, float total_expenses) {
  printf("Balance: $%.2f\n", total_income - total_expenses);
}

int main() {
  struct expense expenses[MAX_EXPENSES];
  struct income incomes[MAX_INCOMES];
  int num_expenses = 0;
  int num_incomes = 0;
  float total_income = 0.0;
  float total_expenses = 0.0;

  printf("Enter expenses:\n");
  while (num_expenses < MAX_EXPENSES) {
    printf("Enter name of expense %d: ", num_expenses + 1);
    scanf("%s", expenses[num_expenses].name);
    printf("Enter amount of expense %d: ", num_expenses + 1);
    scanf("%f", &expenses[num_expenses].amount);
    total_expenses += expenses[num_expenses].amount;
    num_expenses++;
  }

  printf("Enter incomes:\n");
  while (num_incomes < MAX_INCOMES) {
    printf("Enter name of income %d: ", num_incomes + 1);
    scanf("%s", incomes[num_incomes].name);
    printf("Enter amount of income %d: ", num_incomes + 1);
    scanf("%f", &incomes[num_incomes].amount);
    total_income += incomes[num_incomes].amount;
    num_incomes++;
  }

  print_expenses(expenses, num_expenses);
  print_incomes(incomes, num_incomes);
  print_balance(total_income, total_expenses);

  return 0;
}