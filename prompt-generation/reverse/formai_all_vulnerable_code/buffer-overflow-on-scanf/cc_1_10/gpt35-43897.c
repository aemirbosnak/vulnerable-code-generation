//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
  // Prompt user for desired conversion from metric to imperial or vice versa
  printf("Greetings! Would you like to convert from Metric to Imperial or Imperial to Metric? (Enter 'M' for Metric, 'I' for Imperial)\n");
  char conversion_type;
  scanf("%c", &conversion_type);

  // Prompt user for input value and unit of measurement
  printf("What value would you like to convert?\n");
  double input_value;
  scanf("%lf", &input_value);

  printf("What is the unit of measurement? (e.g. 'km', 'm', 'ft', etc.)\n");
  char input_unit[10];
  scanf("%s", input_unit);

  // Perform conversion based on user input
  double output_value;
  char output_unit[10];

  if (conversion_type == 'M') {
    // Conversion from metric to imperial
    if (strcmp(input_unit, "km") == 0) {
      output_value = input_value * 0.621371;
      strcpy(output_unit, "mi");
    } else if (strcmp(input_unit, "m") == 0) {
      output_value = input_value * 3.28084;
      strcpy(output_unit, "ft");
    } else if (strcmp(input_unit, "cm") == 0) {
      output_value = input_value * 0.393701;
      strcpy(output_unit, "in");
    } else {
      printf("Invalid unit of measurement!\n");
      return 1;
    }
  } else if (conversion_type == 'I') {
    // Conversion from imperial to metric
    if (strcmp(input_unit, "mi") == 0) {
      output_value = input_value * 1.60934;
      strcpy(output_unit, "km");
    } else if (strcmp(input_unit, "ft") == 0) {
      output_value = input_value * 0.3048;
      strcpy(output_unit, "m");
    } else if (strcmp(input_unit, "in") == 0) {
      output_value = input_value * 2.54;
      strcpy(output_unit, "cm");
    } else {
      printf("Invalid unit of measurement!\n");
      return 1;
    }
  } else {
    printf("Invalid input!\n");
    return 1;
  }

  // Output result to user
  printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, output_value, output_unit);

  return 0;
}