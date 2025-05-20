//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units of measurement
void convert(double value, char from_unit[20], char to_unit[20]) {
  // Define conversion factors
  double factor = 1;
  if (strcmp(from_unit, "cm") == 0) {
    factor = 10; // Convert cm to m
  } else if (strcmp(from_unit, "m") == 0) {
    factor = 0.1; // Convert m to cm
  } else if (strcmp(from_unit, "km") == 0) {
    factor = 10000; // Convert km to m
  } else if (strcmp(from_unit, "g") == 0) {
    factor = 0.001; // Convert g to kg
  } else if (strcmp(from_unit, "kg") == 0) {
    factor = 1000; // Convert kg to g
  }
  // Apply conversion factor
  value *= factor;
  // Print result
  printf("%.2f %s = %.2f %s\n", value, from_unit, value, to_unit);
}

int main() {
  // Prompt user for input
  printf("Enter a value in cm: ");
  double value;
  scanf("%lf", &value);
  char from_unit[20];
  char to_unit[20];
  
  // Get unit from user
  printf("Enter the unit (cm/m/km): ");
  fgets(from_unit, 20, stdin);
  from_unit[strcspn(from_unit, "\n")] = 0; // Remove newline
  
  // Convert and print result
  convert(value, from_unit, to_unit);
  
  // Ask user for another input
  printf("Enter another value in cm: ");
  scanf("%lf", &value);
  from_unit[0] = 0; // Reset from unit
  to_unit[0] = 0; // Reset to unit
  convert(value, from_unit, to_unit);
  
  return 0;
}