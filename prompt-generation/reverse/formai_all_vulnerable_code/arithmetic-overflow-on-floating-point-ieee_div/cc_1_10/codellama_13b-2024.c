//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
/*
 * A simple C program to calculate mortgage payments
 *
 * This program takes in the following inputs:
 * - Principal amount
 * - Interest rate
 * - Number of years
 * - Down payment
 *
 * It then calculates the total interest paid and the total amount paid
 * over the life of the loan.
 */
#include <stdio.h>

int main() {
  // Get input from user
  double principal;
  double interest_rate;
  double years;
  double down_payment;

  printf("Enter principal amount: ");
  scanf("%lf", &principal);
  printf("Enter interest rate: ");
  scanf("%lf", &interest_rate);
  printf("Enter number of years: ");
  scanf("%lf", &years);
  printf("Enter down payment: ");
  scanf("%lf", &down_payment);

  // Calculate monthly payment
  double monthly_payment = principal / (years * 12);

  // Calculate total interest paid
  double total_interest = 0;
  for (int i = 0; i < years * 12; i++) {
    total_interest += principal * interest_rate / 12;
    principal -= monthly_payment;
  }

  // Calculate total amount paid
  double total_amount = principal + total_interest;

  // Print results
  printf("Monthly payment: $%.2f\n", monthly_payment);
  printf("Total interest paid: $%.2f\n", total_interest);
  printf("Total amount paid: $%.2f\n", total_amount);

  return 0;
}