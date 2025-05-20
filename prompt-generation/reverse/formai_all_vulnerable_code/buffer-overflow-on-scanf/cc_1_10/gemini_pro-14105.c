//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
#define NUM_INTEGERS 10
#define NUM_FLOATS 10
#define NUM_STRINGS 10

// Function prototypes
int paranoid_integer_sum(int *integers, int num_integers);
double paranoid_float_sum(double *floats, int num_floats);
char *paranoid_string_concat(char **strings, int num_strings);

// Main function
int main() {
  // Declare and initialize variables
  int integers[NUM_INTEGERS];
  double floats[NUM_FLOATS];
  char *strings[NUM_STRINGS];

  // Get input from the user
  printf("Enter %d integers: ", NUM_INTEGERS);
  for (int i = 0; i < NUM_INTEGERS; i++) {
    scanf("%d", &integers[i]);
  }

  printf("Enter %d floats: ", NUM_FLOATS);
  for (int i = 0; i < NUM_FLOATS; i++) {
    scanf("%lf", &floats[i]);
  }

  printf("Enter %d strings: ", NUM_STRINGS);
  for (int i = 0; i < NUM_STRINGS; i++) {
    strings[i] = malloc(100);
    scanf("%s", strings[i]);
  }

  // Calculate the sum of the integers
  int integer_sum = paranoid_integer_sum(integers, NUM_INTEGERS);

  // Calculate the sum of the floats
  double float_sum = paranoid_float_sum(floats, NUM_FLOATS);

  // Concatenate the strings
  char *string_concat = paranoid_string_concat(strings, NUM_STRINGS);

  // Print the results
  printf("The sum of the integers is: %d\n", integer_sum);
  printf("The sum of the floats is: %.2lf\n", float_sum);
  printf("The concatenated string is: %s\n", string_concat);

  // Free the allocated memory
  for (int i = 0; i < NUM_STRINGS; i++) {
    free(strings[i]);
  }
  free(string_concat);

  return 0;
}

// Function to calculate the sum of an array of integers
int paranoid_integer_sum(int *integers, int num_integers) {
  // Check if the array is NULL
  if (integers == NULL) {
    printf("Error: The array of integers is NULL.\n");
    exit(EXIT_FAILURE);
  }

  // Check if the number of integers is valid
  if (num_integers <= 0) {
    printf("Error: The number of integers must be greater than 0.\n");
    exit(EXIT_FAILURE);
  }

  // Calculate the sum of the integers
  int sum = 0;
  for (int i = 0; i < num_integers; i++) {
    sum += integers[i];
  }

  // Return the sum
  return sum;
}

// Function to calculate the sum of an array of floats
double paranoid_float_sum(double *floats, int num_floats) {
  // Check if the array is NULL
  if (floats == NULL) {
    printf("Error: The array of floats is NULL.\n");
    exit(EXIT_FAILURE);
  }

  // Check if the number of floats is valid
  if (num_floats <= 0) {
    printf("Error: The number of floats must be greater than 0.\n");
    exit(EXIT_FAILURE);
  }

  // Calculate the sum of the floats
  double sum = 0.0;
  for (int i = 0; i < num_floats; i++) {
    sum += floats[i];
  }

  // Return the sum
  return sum;
}

// Function to concatenate an array of strings
char *paranoid_string_concat(char **strings, int num_strings) {
  // Check if the array is NULL
  if (strings == NULL) {
    printf("Error: The array of strings is NULL.\n");
    exit(EXIT_FAILURE);
  }

  // Check if the number of strings is valid
  if (num_strings <= 0) {
    printf("Error: The number of strings must be greater than 0.\n");
    exit(EXIT_FAILURE);
  }

  // Calculate the total length of the concatenated string
  int total_length = 0;
  for (int i = 0; i < num_strings; i++) {
    total_length += strlen(strings[i]);
  }

  // Allocate memory for the concatenated string
  char *string_concat = malloc(total_length + 1);
  if (string_concat == NULL) {
    printf("Error: Could not allocate memory for the concatenated string.\n");
    exit(EXIT_FAILURE);
  }

  // Concatenate the strings
  strcpy(string_concat, "");
  for (int i = 0; i < num_strings; i++) {
    strcat(string_concat, strings[i]);
  }

  // Return the concatenated string
  return string_concat;
}