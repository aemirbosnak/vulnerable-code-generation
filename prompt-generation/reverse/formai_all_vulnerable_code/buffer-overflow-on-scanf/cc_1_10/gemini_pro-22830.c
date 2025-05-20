//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the conversion factors
  const double inches_per_foot = 12;
  const double feet_per_yard = 3;
  const double yards_per_mile = 1760;
  const double miles_per_kilometer = 1.60934;
  const double kilometers_per_meter = 1000;
  const double meters_per_centimeter = 100;
  const double centimeters_per_millimeter = 10;

  // Get the input value and the unit from the user
  double value;
  char unit;
  printf("Enter a value and a unit (f for feet, y for yards, m for miles, k for kilometers, M for meters, c for centimeters, mm for millimeters): ");
  scanf("%lf %c", &value, &unit);

  // Convert the value to the desired unit
  double converted_value;
  switch (unit) {
    case 'f':
      converted_value = value / inches_per_foot;
      printf("%lf feet is equal to %lf inches\n", value, converted_value);
      break;
    case 'y':
      converted_value = value / feet_per_yard;
      printf("%lf yards is equal to %lf feet\n", value, converted_value);
      break;
    case 'm':
      converted_value = value / yards_per_mile;
      printf("%lf miles is equal to %lf yards\n", value, converted_value);
      break;
    case 'k':
      converted_value = value / miles_per_kilometer;
      printf("%lf kilometers is equal to %lf miles\n", value, converted_value);
      break;
    case 'M':
      converted_value = value / kilometers_per_meter;
      printf("%lf meters is equal to %lf kilometers\n", value, converted_value);
      break;
    case 'c':
      converted_value = value / meters_per_centimeter;
      printf("%lf centimeters is equal to %lf meters\n", value, converted_value);
      break;
    case 'mm':
      converted_value = value / centimeters_per_millimeter;
      printf("%lf millimeters is equal to %lf centimeters\n", value, converted_value);
      break;
    default:
      printf("Invalid unit\n");
  }

  return 0;
}