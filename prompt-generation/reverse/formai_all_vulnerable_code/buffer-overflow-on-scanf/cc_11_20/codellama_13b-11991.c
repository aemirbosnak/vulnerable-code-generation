//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: cheerful
/*
 * 🎉 C Unit Converter 🎉
 *
 * Enter a number and choose a unit to convert it to:
 *
 * 1. Celsius (°C)
 * 2. Fahrenheit (°F)
 * 3. Kelvin (K)
 * 4. Rankine (°R)
 * 5. Newton (N)
 * 6. Pound (lb)
 * 7. Ounce (oz)
 * 8. Gram (g)
 * 9. Milligram (mg)
 * 10. Microgram (μg)
 *
 * Example: "20 celsius"
 */

#include <stdio.h>

int main() {
  char input[256];
  int choice;
  double num, result;

  printf("🎉 C Unit Converter 🎉\n");
  printf("Enter a number and choose a unit to convert it to:\n");
  printf("1. Celsius (°C)\n");
  printf("2. Fahrenheit (°F)\n");
  printf("3. Kelvin (K)\n");
  printf("4. Rankine (°R)\n");
  printf("5. Newton (N)\n");
  printf("6. Pound (lb)\n");
  printf("7. Ounce (oz)\n");
  printf("8. Gram (g)\n");
  printf("9. Milligram (mg)\n");
  printf("10. Microgram (μg)\n");
  printf("Example: \"20 celsius\"\n");

  scanf("%s", input);
  num = atof(input);
  choice = atoi(input + 3);

  switch (choice) {
    case 1: // Celsius
      result = num;
      break;
    case 2: // Fahrenheit
      result = (num - 32) * 5 / 9;
      break;
    case 3: // Kelvin
      result = num + 273.15;
      break;
    case 4: // Rankine
      result = num * 9 / 5;
      break;
    case 5: // Newton
      result = num / 9.80665;
      break;
    case 6: // Pound
      result = num * 0.453592;
      break;
    case 7: // Ounce
      result = num * 0.0283495;
      break;
    case 8: // Gram
      result = num * 1000;
      break;
    case 9: // Milligram
      result = num * 1000000;
      break;
    case 10: // Microgram
      result = num * 1000000000;
      break;
    default:
      printf("Invalid unit!\n");
      return 1;
  }

  printf("Result: %lf\n", result);

  return 0;
}