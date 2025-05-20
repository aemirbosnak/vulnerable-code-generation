//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: statistical
#include <stdio.h>
#include <math.h>

int main() {
  // input variables
  float loan_amount, interest_rate, monthly_payment, principal, interest, balance;

  // get user input for loan amount
  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);

  // get user input for interest rate
  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);

  // convert interest rate to monthly rate
  float monthly_rate = interest_rate / (12 * 100);

  // calculate monthly payment
  printf("Enter the monthly payment: ");
  scanf("%f", &monthly_payment);

  // calculate number of months to pay off loan
  float num_months = (-1) * log10(1 - ((monthly_rate * loan_amount) / monthly_payment)) / log10(1 + monthly_rate);

  // print number of months
  printf("\nNumber of months to pay off loan: %.0f months\n", num_months);

  // print table of payments
  printf("Month\tPrincipal Payment\tInterest Payment\tBalance\n");

  for(int i = 1; i <= num_months; i++) {
    // calculate principal payment
    principal = monthly_payment - (loan_amount * monthly_rate);

    // calculate interest payment
    interest = loan_amount * monthly_rate;

    // calculate remaining balance
    balance = loan_amount - principal;

    // print table row
    printf("%d\t%f\t%f\t%f\n", i, principal, interest, balance);

    // set loan amount to remaining balance for next iteration
    loan_amount = balance;
  }

  return 0;
}