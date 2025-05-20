//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>

// Defines the temperature units and their conversion factors.
typedef enum {
  CELSIUS,
  FAHRENHEIT,
  KELVIN
} temperature_unit;

const double conversion_factors[3][3] = {
  { 1.0, 1.8, 273.15 },
  { 0.5555555555555556, 1.0, 255.37222222222223 },
  { 0.0, 0.00392156862745098, 1.0 }
};

// Converts a temperature value from one unit to another.
double convert_temperature(double value, temperature_unit from_unit, temperature_unit to_unit) {
  return value * conversion_factors[from_unit][to_unit];
}

// Prints a temperature value in a formatted string.
void print_temperature(double value, temperature_unit unit) {
  switch (unit) {
    case CELSIUS:
      printf("%.2f degrees Celsius", value);
      break;
    case FAHRENHEIT:
      printf("%.2f degrees Fahrenheit", value);
      break;
    case KELVIN:
      printf("%.2f Kelvin", value);
      break;
  }
}

// Gets a temperature value from the user.
double get_temperature(temperature_unit unit) {
  double value;
  char buffer[1024];

  printf("Enter a temperature value in %s: ", unit == CELSIUS ? "Celsius" : "Fahrenheit");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%lf", &value);

  return value;
}

// Main function.
int main() {
  // Get the temperature value and unit from the user.
  double value = get_temperature(CELSIUS);
  temperature_unit from_unit = CELSIUS;

  // Convert the temperature to all other units.
  double converted_values[3];
  for (int i = 0; i < 3; i++) {
    converted_values[i] = convert_temperature(value, from_unit, i);
  }

  // Print the converted temperatures.
  printf("\nConverted temperatures:\n");
  for (int i = 0; i < 3; i++) {
    print_temperature(converted_values[i], i);
    printf("\n");
  }

  return 0;
}