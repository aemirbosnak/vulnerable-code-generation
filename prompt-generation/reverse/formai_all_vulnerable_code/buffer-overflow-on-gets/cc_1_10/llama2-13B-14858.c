//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units to convert from and to
#define FROM_UNITS "cm,m,km"
#define TO_UNITS "in,ft,yd"

// Define the conversion factors
#define CM_TO_IN 0.3937007874015748
#define M_TO_IN 39.37007874015748
#define KM_TO_IN 0.03937007874015748
#define IN_TO_CM 2.54
#define IN_TO_FT 12
#define IN_TO_YD 36

// Function to convert a value from one unit to another
void convert_unit(double value, char from_unit[], char to_unit[]) {
  double factor;

  // Check if the input value is negative
  if (value < 0) {
    printf("Error: Negative values are not supported.\n");
    return;
  }

  // Check if the from unit is valid
  if (strchr(from_unit, ' ') != NULL) {
    printf("Error: From unit cannot contain spaces.\n");
    return;
  }

  // Check if the to unit is valid
  if (strchr(to_unit, ' ') != NULL) {
    printf("Error: To unit cannot contain spaces.\n");
    return;
  }

  // Determine the conversion factor based on the from and to units
  if (strcmp(from_unit, "cm") == 0) {
    factor = CM_TO_IN;
  } else if (strcmp(from_unit, "m") == 0) {
    factor = M_TO_IN;
  } else if (strcmp(from_unit, "km") == 0) {
    factor = KM_TO_IN;
  } else {
    printf("Error: Unsupported from unit.\n");
    return;
  }

  // Perform the conversion
  value *= factor;

  // Convert the result to the desired unit
  if (strcmp(to_unit, "in") == 0) {
    value /= IN_TO_CM;
  } else if (strcmp(to_unit, "ft") == 0) {
    value /= IN_TO_FT;
  } else if (strcmp(to_unit, "yd") == 0) {
    value /= IN_TO_YD;
  } else {
    printf("Error: Unsupported to unit.\n");
    return;
  }

  // Print the result
  printf("Result: %f %s\n", value, to_unit);
}

int main() {
  double value;
  char from_unit[50];
  char to_unit[50];

  // Get the input value and units from the user
  printf("Enter a value: ");
  scanf("%lf", &value);
  gets(from_unit);
  gets(to_unit);

  // Convert the value to the desired unit
  convert_unit(value, from_unit, to_unit);

  return 0;
}