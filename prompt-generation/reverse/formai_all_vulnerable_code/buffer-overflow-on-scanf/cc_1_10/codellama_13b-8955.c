//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
// Unit Converter Example Program
#include <stdio.h>

// Define the conversion factors
#define CM_PER_M 100
#define M_PER_KM 1000
#define KG_PER_TON 1000
#define MIN_PER_HR 60
#define SEC_PER_MIN 60

// Define the conversion functions
double convert_length(double value, char unit) {
  switch (unit) {
    case 'm':
      return value;
    case 'cm':
      return value * CM_PER_M;
    case 'km':
      return value * M_PER_KM;
    default:
      return 0.0;
  }
}

double convert_weight(double value, char unit) {
  switch (unit) {
    case 'kg':
      return value;
    case 'ton':
      return value * KG_PER_TON;
    default:
      return 0.0;
  }
}

double convert_time(double value, char unit) {
  switch (unit) {
    case 'sec':
      return value;
    case 'min':
      return value * MIN_PER_HR;
    case 'hr':
      return value * SEC_PER_MIN;
    default:
      return 0.0;
  }
}

// Define the main function
int main() {
  // Declare variables
  double length, weight, time;
  char unit_length, unit_weight, unit_time;

  // Prompt the user for input
  printf("Enter a length: ");
  scanf("%lf %c", &length, &unit_length);
  printf("Enter a weight: ");
  scanf("%lf %c", &weight, &unit_weight);
  printf("Enter a time: ");
  scanf("%lf %c", &time, &unit_time);

  // Convert the inputs
  length = convert_length(length, unit_length);
  weight = convert_weight(weight, unit_weight);
  time = convert_time(time, unit_time);

  // Print the results
  printf("Length: %.2f cm\n", length);
  printf("Weight: %.2f kg\n", weight);
  printf("Time: %.2f sec\n", time);

  return 0;
}