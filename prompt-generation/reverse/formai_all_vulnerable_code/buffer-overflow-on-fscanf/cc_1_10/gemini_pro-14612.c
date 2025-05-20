//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Paranoid temperature converter

// Define the input and output file names
#define INPUT_FILE_NAME  "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// Define the temperature conversion formulas
#define CELSIUS_TO_FAHRENHEIT(celsius)  ((celsius * 9) / 5) + 32
#define FAHRENHEIT_TO_CELSIUS(fahrenheit)  ((fahrenheit - 32) * 5) / 9

// Define the error messages
#define INPUT_FILE_ERROR  "Could not open input file"
#define OUTPUT_FILE_ERROR "Could not open output file"
#define INVALID_TEMPERATURE_ERROR  "Invalid temperature"

// Define the main function
int main(void) {
  // Define the input and output files
  FILE *input_file;
  FILE *output_file;

  // Open the input file
  input_file = fopen(INPUT_FILE_NAME, "r");
  if (input_file == NULL) {
    fprintf(stderr, INPUT_FILE_ERROR);
    return EXIT_FAILURE;
  }

  // Open the output file
  output_file = fopen(OUTPUT_FILE_NAME, "w");
  if (output_file == NULL) {
    fprintf(stderr, OUTPUT_FILE_ERROR);
    return EXIT_FAILURE;
  }

  // Read the temperature from the input file
  char temperature_string[10];
  if (fscanf(input_file, "%s", temperature_string) != 1) {
    fprintf(stderr, INVALID_TEMPERATURE_ERROR);
    return EXIT_FAILURE;
  }

  // Convert the temperature to a double
  double temperature = atof(temperature_string);

  // Check if the temperature is valid
  if (temperature < -273.15 || temperature > 573.15) {
    fprintf(stderr, INVALID_TEMPERATURE_ERROR);
    return EXIT_FAILURE;
  }

  // Convert the temperature to Fahrenheit
  double fahrenheit = CELSIUS_TO_FAHRENHEIT(temperature);

  // Write the temperature to the output file
  fprintf(output_file, "The temperature in Fahrenheit is: %f\n", fahrenheit);

  // Close the input and output files
  fclose(input_file);
  fclose(output_file);

  // Return success
  return EXIT_SUCCESS;
}