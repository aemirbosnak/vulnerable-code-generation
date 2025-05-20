//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: future-proof
// Unit Converter Program
// Future-Proof Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare global variables
char input[80];
double num;
char unit1[10];
char unit2[10];
double conv_factor;

int main() {
  // Initialize global variables
  num = 0.0;
  strcpy(unit1, "");
  strcpy(unit2, "");
  conv_factor = 0.0;

  // Get input from user
  printf("Enter a number and the unit of measurement: ");
  scanf("%lf %s", &num, unit1);

  // Convert unit to uppercase
  for (int i = 0; i < strlen(unit1); i++) {
    unit1[i] = toupper(unit1[i]);
  }

  // Check if unit is supported
  if (strcmp(unit1, "KILOMETERS") == 0) {
    conv_factor = 1000.0;
  } else if (strcmp(unit1, "METERS") == 0) {
    conv_factor = 1.0;
  } else if (strcmp(unit1, "CENTIMETERS") == 0) {
    conv_factor = 0.01;
  } else if (strcmp(unit1, "MILLIMETERS") == 0) {
    conv_factor = 0.001;
  } else {
    printf("Invalid unit of measurement\n");
    return 1;
  }

  // Convert number to target unit
  num = num * conv_factor;

  // Get target unit from user
  printf("Enter target unit of measurement: ");
  scanf("%s", unit2);

  // Convert target unit to uppercase
  for (int i = 0; i < strlen(unit2); i++) {
    unit2[i] = toupper(unit2[i]);
  }

  // Check if target unit is supported
  if (strcmp(unit2, "KILOMETERS") == 0) {
    conv_factor = 1.0 / 1000.0;
  } else if (strcmp(unit2, "METERS") == 0) {
    conv_factor = 1.0;
  } else if (strcmp(unit2, "CENTIMETERS") == 0) {
    conv_factor = 100.0;
  } else if (strcmp(unit2, "MILLIMETERS") == 0) {
    conv_factor = 1000.0;
  } else {
    printf("Invalid target unit of measurement\n");
    return 1;
  }

  // Convert number to target unit
  num = num * conv_factor;

  // Print result
  printf("Result: %lf %s\n", num, unit2);

  return 0;
}