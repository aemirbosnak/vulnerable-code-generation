//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
float usd_to_gbp(float usd) {
  return usd * 0.84;
}

float euro_to_gbp(float euro) {
  return euro * 0.88;
}

float yen_to_gbp(float yen) {
  return yen * 0.76;
}

int main() {
  // Get the currency and amount from the user
  char currency;
  float amount;

  // Display the available currencies
  printf("Available currencies: USD, EUR, Yen\n");

  // Get the currency and amount
  printf("Enter currency: ");
  scanf("%c", &currency);

  printf("Enter amount: ");
  scanf("%f", &amount);

  // Convert the currency to GBP
  float converted_amount = 0;

  switch (currency) {
    case 'u':
    case 'U':
      converted_amount = usd_to_gbp(amount);
      break;
    case 'e':
    case 'E':
      converted_amount = euro_to_gbp(amount);
      break;
    case 'y':
    case 'Y':
      converted_amount = yen_to_gbp(amount);
      break;
    default:
      printf("Invalid currency.\n");
  }

  // Display the converted amount
  if (converted_amount) {
    printf("Converted amount: %.2f GBP\n", converted_amount);
  } else {
    printf("Error converting currency.\n");
  }

  return 0;
}