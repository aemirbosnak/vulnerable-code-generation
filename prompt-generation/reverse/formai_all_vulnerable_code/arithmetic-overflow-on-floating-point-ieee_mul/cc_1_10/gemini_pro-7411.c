//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Introspection functions
void print_intro(void);
void print_help(void);
void print_error(char *msg);

// Mortgage calculation functions
double calculate_monthly_payment(double principal, double interest_rate, int loan_term);
void print_mortgage_summary(double principal, double interest_rate, int loan_term, double monthly_payment);

int main(int argc, char *argv[]) {
  // Print intro message
  print_intro();

  // Check for help flag
  if (argc > 1 && strcmp(argv[1], "--help") == 0) {
    print_help();
    return 0;
  }

  // Check for correct number of arguments
  if (argc != 5) {
    print_error("Invalid number of arguments. Usage: mortgagecalc <principal> <interest_rate> <loan_term> <monthly_payment>");
    return 1;
  }

  // Parse arguments
  double principal = atof(argv[1]);
  double interest_rate = atof(argv[2]);
  int loan_term = atoi(argv[3]);
  double monthly_payment = atof(argv[4]);

  // Calculate monthly payment
  double calculated_monthly_payment = calculate_monthly_payment(principal, interest_rate, loan_term);

  // Print mortgage summary
  print_mortgage_summary(principal, interest_rate, loan_term, monthly_payment);

  return 0;
}

void print_intro(void) {
  printf("Welcome to the Mortgage Calculator!\n\n");
  printf("This program will help you calculate your monthly mortgage payment and provide a summary of your loan details.\n\n");
  printf("Please enter the following information:\n");
}

void print_help(void) {
  printf("Usage: mortgagecalc <principal> <interest_rate> <loan_term> <monthly_payment>\n");
  printf("\n");
  printf("Arguments:\n");
  printf("  principal: The amount of money you are borrowing\n");
  printf("  interest_rate: The annual interest rate on your loan (e.g., 3.5)\n");
  printf("  loan_term: The number of years you have to repay your loan\n");
  printf("  monthly_payment: The amount of money you will pay each month towards your loan\n");
  printf("\n");
  printf("Example:\n");
  printf("  mortgagecalc 100000 3.5 30 500\n");
}

void print_error(char *msg) {
  printf("Error: %s\n", msg);
}

double calculate_monthly_payment(double principal, double interest_rate, int loan_term) {
  double monthly_interest_rate = interest_rate / 12 / 100;
  double num_payments = loan_term * 12;

  return (monthly_interest_rate * principal) /
         (1 - pow(1 + monthly_interest_rate, -num_payments));
}

void print_mortgage_summary(double principal, double interest_rate, int loan_term, double monthly_payment) {
  printf("\n");
  printf("Mortgage Summary:\n");
  printf("  Principal:              $%0.2f\n", principal);
  printf("  Interest Rate:          %0.2f%%\n", interest_rate);
  printf("  Loan Term:              %d years\n", loan_term);
  printf("  Monthly Payment:        $%0.2f\n", monthly_payment);
  printf("  Total Amount Paid:      $%0.2f\n", monthly_payment * loan_term * 12);
  printf("  Total Interest Paid:    $%0.2f\n", monthly_payment * loan_term * 12 - principal);
}