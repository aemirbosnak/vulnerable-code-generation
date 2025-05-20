//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double cm_to_inches(double cm) {
  return cm / 2.54;
}

double inches_to_cm(double inches) {
  return inches * 2.54;
}

double kg_to_lbs(double kg) {
  return kg * 2.20462;
}

double lbs_to_kg(double lbs) {
  return lbs / 2.20462;
}

// Define the main function
int main() {
  // Get the user's input
  printf("Enter the value to be converted: ");
  double value;
  scanf("%lf", &value);

  printf("Enter the unit of the value (cm, inches, kg, lbs): ");
  char unit[3];
  scanf("%s", unit);

  // Convert the value to the desired unit
  double converted_value;
  if (strcmp(unit, "cm") == 0) {
    converted_value = cm_to_inches(value);
  } else if (strcmp(unit, "inches") == 0) {
    converted_value = inches_to_cm(value);
  } else if (strcmp(unit, "kg") == 0) {
    converted_value = kg_to_lbs(value);
  } else if (strcmp(unit, "lbs") == 0) {
    converted_value = lbs_to_kg(value);
  } else {
    printf("Invalid unit entered.\n");
    return 1;
  }

  // Print the converted value
  printf("The converted value is: %.2f\n", converted_value);

  return 0;
}