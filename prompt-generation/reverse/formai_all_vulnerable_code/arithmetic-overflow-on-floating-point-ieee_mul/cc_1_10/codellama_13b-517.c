//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
/*
 * C Mortgage Calculator - Romeo and Juliet Style
 *
 * This program calculates the monthly mortgage payment for a given
 * principal, interest rate, and term. The output is a table with
 * the monthly payment, interest, and principal for each month.
 */

#include <stdio.h>

int main() {
  // Declare variables
  double principal, interest, rate, term, payment;
  int months;

  // Get input from user
  printf("Enter principal: ");
  scanf("%lf", &principal);
  printf("Enter interest rate (%%): ");
  scanf("%lf", &rate);
  printf("Enter term (years): ");
  scanf("%d", &term);

  // Calculate interest
  interest = principal * rate / 100;

  // Calculate payment
  payment = interest / 12;

  // Calculate number of months
  months = term * 12;

  // Print header
  printf("Month\tMonthly Payment\tInterest\tPrincipal\n");

  // Loop through months
  for (int i = 1; i <= months; i++) {
    // Calculate monthly payment
    payment = interest / 12;

    // Calculate interest
    interest = payment * principal * rate / 100;

    // Calculate principal
    principal = principal - payment + interest;

    // Print monthly payment, interest, and principal
    printf("%d\t%f\t%f\t%f\n", i, payment, interest, principal);
  }

  return 0;
}