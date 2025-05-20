//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: protected
// personal_finance_planner.c

#include <stdio.h>
#include <stdlib.h>

// struct to store user inputs
struct user_inputs {
  int income;
  int expenses;
  int savings;
  int debt;
  int retirement;
};

// function to get user inputs
void get_inputs(struct user_inputs *inputs) {
  printf("Enter your monthly income: ");
  scanf("%d", &inputs->income);
  printf("Enter your monthly expenses: ");
  scanf("%d", &inputs->expenses);
  printf("Enter your monthly savings: ");
  scanf("%d", &inputs->savings);
  printf("Enter your monthly debt: ");
  scanf("%d", &inputs->debt);
  printf("Enter your retirement savings goal: ");
  scanf("%d", &inputs->retirement);
}

// function to calculate net income
int calculate_net_income(struct user_inputs *inputs) {
  return inputs->income - inputs->expenses;
}

// function to calculate savings rate
int calculate_savings_rate(struct user_inputs *inputs) {
  return inputs->savings / calculate_net_income(inputs);
}

// function to calculate debt ratio
int calculate_debt_ratio(struct user_inputs *inputs) {
  return inputs->debt / inputs->income;
}

// function to calculate retirement savings
int calculate_retirement_savings(struct user_inputs *inputs) {
  return inputs->retirement / calculate_net_income(inputs);
}

// function to print results
void print_results(struct user_inputs *inputs) {
  printf("Net Income: %d\n", calculate_net_income(inputs));
  printf("Savings Rate: %d\n", calculate_savings_rate(inputs));
  printf("Debt Ratio: %d\n", calculate_debt_ratio(inputs));
  printf("Retirement Savings: %d\n", calculate_retirement_savings(inputs));
}

int main() {
  struct user_inputs inputs;
  get_inputs(&inputs);
  print_results(&inputs);
  return 0;
}