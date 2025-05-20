//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: modular
/*
 * mortgage_calculator.c
 *
 * A modular C program to calculate a mortgage payment.
 *
 * Usage:
 *  $ gcc -o mortgage_calculator mortgage_calculator.c
 *  $ ./mortgage_calculator
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

// Function prototypes
double get_mortgage_amount();
double get_interest_rate();
double get_mortgage_term();
double calculate_monthly_payment(double amount, double interest_rate, double term);

// Main function
int main() {
  double amount = get_mortgage_amount();
  double interest_rate = get_interest_rate();
  double term = get_mortgage_term();

  double payment = calculate_monthly_payment(amount, interest_rate, term);

  printf("Mortgage Payment: %.2f\n", payment);

  return 0;
}

// Function definitions
double get_mortgage_amount() {
  double amount;

  printf("Enter the mortgage amount: ");
  scanf("%lf", &amount);

  return amount;
}

double get_interest_rate() {
  double interest_rate;

  printf("Enter the interest rate (%%): ");
  scanf("%lf", &interest_rate);

  return interest_rate / 100;
}

double get_mortgage_term() {
  double term;

  printf("Enter the mortgage term (years): ");
  scanf("%lf", &term);

  return term * 12;
}

double calculate_monthly_payment(double amount, double interest_rate, double term) {
  double monthly_interest_rate = interest_rate / 12;
  double monthly_payment = 0;

  for (int i = 0; i < term; i++) {
    double interest = amount * monthly_interest_rate;
    double principal = amount - interest;

    monthly_payment += principal;
    amount = principal;
  }

  return monthly_payment;
}