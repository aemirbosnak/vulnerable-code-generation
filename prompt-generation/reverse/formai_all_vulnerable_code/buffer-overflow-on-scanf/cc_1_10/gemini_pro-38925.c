//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

int main() {
  // Define the conversion factors
  float fahrenheit_to_celsius = 5.0 / 9.0;
  float celsius_to_fahrenheit = 9.0 / 5.0;
  float miles_to_kilometers = 1.60934;
  float kilometers_to_miles = 0.621371;
  float pounds_to_kilograms = 0.453592;
  float kilograms_to_pounds = 2.20462;

  // Get the user's input
  printf("Enter the value to be converted: ");
  float value;
  scanf("%f", &value);

  printf("Enter the unit of the value (f for Fahrenheit, c for Celsius, m for miles, km for kilometers, lb for pounds, kg for kilograms): ");
  char unit;
  scanf(" %c", &unit);

  // Convert the value to the desired unit
  float converted_value;
  switch (unit) {
    case 'f':
      converted_value = value * fahrenheit_to_celsius;
      printf("%.2f Fahrenheit is %.2f Celsius\n", value, converted_value);
      break;
    case 'c':
      converted_value = value * celsius_to_fahrenheit;
      printf("%.2f Celsius is %.2f Fahrenheit\n", value, converted_value);
      break;
    case 'm':
      converted_value = value * miles_to_kilometers;
      printf("%.2f miles is %.2f kilometers\n", value, converted_value);
      break;
    case 'k':
      converted_value = value * kilometers_to_miles;
      printf("%.2f kilometers is %.2f miles\n", value, converted_value);
      break;
    case 'l':
      converted_value = value * pounds_to_kilograms;
      printf("%.2f pounds is %.2f kilograms\n", value, converted_value);
      break;
    case 'g':
      converted_value = value * kilograms_to_pounds;
      printf("%.2f kilograms is %.2f pounds\n", value, converted_value);
      break;
    default:
      printf("Invalid unit\n");
  }

  return 0;
}