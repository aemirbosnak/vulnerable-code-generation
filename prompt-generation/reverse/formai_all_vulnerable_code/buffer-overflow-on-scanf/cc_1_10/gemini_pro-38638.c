//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>

// constants for temperature conversion
#define CELSIUS_TO_FAHRENHEIT_FACTOR 1.8
#define FAHRENHEIT_TO_CELSIUS_FACTOR (1.0 / CELSIUS_TO_FAHRENHEIT_FACTOR)

// defines the temperature type
typedef enum temperature_type {
  CELSIUS,
  FAHRENHEIT
} temperature_type_t;

// prints a message in a post-apocalyptic style
void print_apocalyptic_message(const char *message) {
  printf("========================================================================\n");
  printf("||                                                                    ||\n");
  printf("|| %s ||\n", message);
  printf("||                                                                    ||\n");
  printf("========================================================================\n");
}

// converts a temperature from one type to another
double convert_temperature(double temperature, temperature_type_t from_type, temperature_type_t to_type) {
  // check if the conversion is valid
  if (from_type == to_type) {
    return temperature;
  }

  // convert the temperature
  if (from_type == CELSIUS) {
    return temperature * CELSIUS_TO_FAHRENHEIT_FACTOR;
  } else if (from_type == FAHRENHEIT) {
    return temperature * FAHRENHEIT_TO_CELSIUS_FACTOR;
  } else {
    print_apocalyptic_message("Invalid temperature type.");
    return 0.0;
  }
}

// main function
int main() {
  // print a welcome message
  print_apocalyptic_message("Welcome to the post-apocalyptic temperature converter.");

  // get the temperature and the conversion type from the user
  double temperature;
  temperature_type_t from_type, to_type;
  printf("Enter the temperature: ");
  scanf("%lf", &temperature);
  printf("Enter the conversion type (C/F): ");
  scanf(" %c", &from_type);
  printf("Enter the target type (C/F): ");
  scanf(" %c", &to_type);

  // convert the temperature
  double converted_temperature = convert_temperature(temperature, from_type, to_type);

  // print the converted temperature
  printf("The converted temperature is: %.2f\n", converted_temperature);

  return 0;
}