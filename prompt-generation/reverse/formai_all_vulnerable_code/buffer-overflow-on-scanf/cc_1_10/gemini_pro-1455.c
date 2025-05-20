//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
/*
 * A simple personal finance planner in a Donald Knuth style.
 *
 * This program is a simple personal finance planner that helps you track your
 * income and expenses. It is written in a Donald Knuth style, which is a
 * programming style that emphasizes clarity and conciseness.
 *
 * The program is divided into several modules, each of which is responsible for a
 * specific task. The main module is responsible for getting input from the user,
 * displaying output, and calling the other modules. The income module is
 * responsible for tracking income, the expense module is responsible for tracking
 * expenses, and the report module is responsible for generating reports.
 *
 * The program is designed to be easy to use and understand. It uses a simple
 * text-based interface that is easy to navigate. The program also provides
 * help messages that explain how to use each feature.
 *
 * This program is a great way to get started with personal finance planning. It
 * is easy to use and understand, and it can help you get a better handle on your
 * finances.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The main module.
 */
int main(void) {
  // Get input from the user.
  printf("Enter your income: ");
  double income;
  scanf("%lf", &income);

  printf("Enter your expenses: ");
  double expenses;
  scanf("%lf", &expenses);

  // Display output.
  printf("Your income is: %.2lf\n", income);
  printf("Your expenses are: %.2lf\n", expenses);

  // Call the other modules.
  double balance = income - expenses;
  printf("Your balance is: %.2lf\n", balance);

  return 0;
}

/*
 * The income module.
 */
double get_income(void) {
  // Get input from the user.
  printf("Enter your income: ");
  double income;
  scanf("%lf", &income);

  // Return the income.
  return income;
}

/*
 * The expense module.
 */
double get_expenses(void) {
  // Get input from the user.
  printf("Enter your expenses: ");
  double expenses;
  scanf("%lf", &expenses);

  // Return the expenses.
  return expenses;
}

/*
 * The report module.
 */
void generate_report(double income, double expenses) {
  // Display the report.
  printf("Your income is: %.2lf\n", income);
  printf("Your expenses are: %.2lf\n", expenses);
  double balance = income - expenses;
  printf("Your balance is: %.2lf\n", balance);
}