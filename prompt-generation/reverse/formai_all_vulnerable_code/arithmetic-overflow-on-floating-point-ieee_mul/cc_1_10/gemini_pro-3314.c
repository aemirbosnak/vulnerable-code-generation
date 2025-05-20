//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

char *celsiusToFahrenheit(double c) {
  // Convert Celsius to Fahrenheit
  double f = (c * 9 / 5) + 32;

  // Allocate memory for the result string
  char *result = malloc(30);

  // Convert the double to a string
  sprintf(result, "%.2f", f);

  // Return the result string
  return result;
}

char *fahrenheitToCelsius(double f) {
  // Convert Fahrenheit to Celsius
  double c = (f - 32) * 5 / 9;

  // Allocate memory for the result string
  char *result = malloc(30);

  // Convert the double to a string
  sprintf(result, "%.2f", c);

  // Return the result string
  return result;
}

int main() {
  // Get the user's input
  printf("Enter a temperature in Celsius: ");
  double c;
  scanf("%lf", &c);

  // Convert the temperature to Fahrenheit
  char *f = celsiusToFahrenheit(c);

  // Print the result
  printf("%s Fahrenheit\n", f);

  // Convert the temperature back to Celsius
  char *c2 = fahrenheitToCelsius(strtod(f, NULL));

  // Print the result
  printf("%s Celsius\n", c2);

  // Free the memory allocated for the result strings
  free(f);
  free(c2);

  return 0;
}