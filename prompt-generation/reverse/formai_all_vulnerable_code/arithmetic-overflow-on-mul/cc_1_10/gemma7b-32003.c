//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include <stdio.h>
#include <math.h>

void calculate_mortgage(double principal, double rate, int years) {
  double monthly_rate, interest, payment, total_interest, balance;
  int months;

  // Calculate monthly rate
  monthly_rate = rate / 12;

  // Calculate number of months
  months = years * 12;

  // Calculate interest
  interest = principal * monthly_rate * months / 100;

  // Calculate payment
  payment = principal + interest;

  // Calculate total interest
  total_interest = interest;

  // Calculate balance
  balance = principal - payment;

  // Print results
  printf("Total mortgage payment: $%.2f\n", payment);
  printf("Total interest paid: $%.2f\n", total_interest);
  printf("Balance remaining: $%.2f\n", balance);
}

int main() {
  double principal;
  double rate;
  int years;

  // Get mortgage information
  printf("Enter the principal amount: ");
  scanf("%lf", &principal);

  printf("Enter the interest rate (as a decimal): ");
  scanf("%lf", &rate);

  printf("Enter the number of years: ");
  scanf("%d", &years);

  // Calculate mortgage
  calculate_mortgage(principal, rate, years);

  return 0;
}