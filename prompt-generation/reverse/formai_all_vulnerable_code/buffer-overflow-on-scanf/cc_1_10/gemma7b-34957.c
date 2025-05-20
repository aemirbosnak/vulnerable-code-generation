//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main()
{
  float principal, interestRate, years, monthlyPayment, totalPayment, interestCharge, principalReduction;
  int i, mortgageTerm;

  printf("Welcome to the Ultimate Mortgage Calculator!\n");

  // Get the principal amount
  printf("Enter the mortgage principal: ");
  scanf("%f", &principal);

  // Get the interest rate
  printf("Enter the interest rate (%): ");
  scanf("%f", &interestRate);

  // Get the number of years
  printf("Enter the number of years you want to borrow for: ");
  scanf("%d", &years);

  // Calculate the mortgage term
  mortgageTerm = years * 12;

  // Calculate the monthly interest rate
  interestRate /= 100;

  // Calculate the total number of payments
  totalPayment = mortgageTerm * 12;

  // Calculate the interest charge
  interestCharge = principal * interestRate * totalPayment / 100;

  // Calculate the principal reduction
  principalReduction = totalPayment - interestCharge;

  // Print the results
  printf("------------------------------------------------------------------------\n");
  printf("Loan Details:\n");
  printf("Principal: $%.2f\n", principal);
  printf("Interest Rate: %.2f%\n", interestRate);
  printf("Number of Years: %d\n", years);
  printf("Mortgage Term: %d months\n", mortgageTerm);
  printf("Total Number of Payments: %d\n", totalPayment);
  printf("Interest Charge: $%.2f\n", interestCharge);
  printf("Principal Reduction: $%.2f\n", principalReduction);
  printf("------------------------------------------------------------------------\n");

  return 0;
}