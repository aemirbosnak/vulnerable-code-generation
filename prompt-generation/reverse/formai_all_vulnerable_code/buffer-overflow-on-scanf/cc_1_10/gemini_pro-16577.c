//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>

// Define the unit conversion functions
double convert_inches_to_feet(double inches) {
  return inches / 12;
}

double convert_feet_to_inches(double feet) {
  return feet * 12;
}

double convert_miles_to_kilometers(double miles) {
  return miles * 1.60934;
}

double convert_kilometers_to_miles(double kilometers) {
  return kilometers / 1.60934;
}

double convert_pounds_to_kilograms(double pounds) {
  return pounds * 0.453592;
}

double convert_kilograms_to_pounds(double kilograms) {
  return kilograms / 0.453592;
}

double convert_gallons_to_liters(double gallons) {
  return gallons * 3.78541;
}

double convert_liters_to_gallons(double liters) {
  return liters / 3.78541;
}

// Define the main function
int main() {
  // Get the user's input
  printf("Enter the value to be converted: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit of the value: ");
  char unit[20];
  scanf("%s", unit);

  // Convert the value to the desired unit
  double converted_value;
  if (strcmp(unit, "in") == 0) {
    converted_value = convert_inches_to_feet(value);
    printf("%lf inches is equal to %lf feet.\n", value, converted_value);
  } else if (strcmp(unit, "ft") == 0) {
    converted_value = convert_feet_to_inches(value);
    printf("%lf feet is equal to %lf inches.\n", value, converted_value);
  } else if (strcmp(unit, "mi") == 0) {
    converted_value = convert_miles_to_kilometers(value);
    printf("%lf miles is equal to %lf kilometers.\n", value, converted_value);
  } else if (strcmp(unit, "km") == 0) {
    converted_value = convert_kilometers_to_miles(value);
    printf("%lf kilometers is equal to %lf miles.\n", value, converted_value);
  } else if (strcmp(unit, "lb") == 0) {
    converted_value = convert_pounds_to_kilograms(value);
    printf("%lf pounds is equal to %lf kilograms.\n", value, converted_value);
  } else if (strcmp(unit, "kg") == 0) {
    converted_value = convert_kilograms_to_pounds(value);
    printf("%lf kilograms is equal to %lf pounds.\n", value, converted_value);
  } else if (strcmp(unit, "gal") == 0) {
    converted_value = convert_gallons_to_liters(value);
    printf("%lf gallons is equal to %lf liters.\n", value, converted_value);
  } else if (strcmp(unit, "l") == 0) {
    converted_value = convert_liters_to_gallons(value);
    printf("%lf liters is equal to %lf gallons.\n", value, converted_value);
  } else {
    printf("Invalid unit.\n");
  }

  return 0;
}