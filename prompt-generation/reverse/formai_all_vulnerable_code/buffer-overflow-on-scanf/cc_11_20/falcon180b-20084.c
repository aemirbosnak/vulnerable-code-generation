//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[50];
  char unit[10];
  float temperature, converted;
  int i, j;

  // Prompt the user to enter the temperature and unit of measurement
  printf("Enter temperature: ");
  scanf("%s", input);
  printf("Enter unit of measurement (C, F, K): ");
  scanf("%s", unit);

  // Convert the input string to lowercase
  for (i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
  }

  // Convert the unit of measurement to lowercase
  for (i = 0; i < strlen(unit); i++) {
    unit[i] = tolower(unit[i]);
  }

  // Check if the unit of measurement is valid
  if (strcmp(unit, "c")!= 0 && strcmp(unit, "f")!= 0 && strcmp(unit, "k")!= 0) {
    printf("Invalid unit of measurement. Please enter C, F, or K.\n");
    return 1;
  }

  // Convert the temperature to the appropriate unit
  if (strcmp(unit, "c") == 0) {
    temperature = strtof(input, &j);
    if (j == strlen(input)) {
      printf("Invalid temperature.\n");
      return 1;
    }
    converted = (temperature * 9/5) + 32;
    printf("%.2f C is %.2f F or %.2f K.\n", temperature, converted, temperature + 273.15);
  } else if (strcmp(unit, "f") == 0) {
    temperature = strtof(input, &j);
    if (j == strlen(input)) {
      printf("Invalid temperature.\n");
      return 1;
    }
    converted = (temperature - 32) * 5/9;
    printf("%.2f F is %.2f C or %.2f K.\n", temperature, converted, temperature + 459.67);
  } else if (strcmp(unit, "k") == 0) {
    temperature = strtof(input, &j);
    if (j == strlen(input)) {
      printf("Invalid temperature.\n");
      return 1;
    }
    converted = temperature - 273.15;
    printf("%.2f K is %.2f C or %.2f F.\n", temperature, converted, temperature * 9/5 + 32);
  }

  return 0;
}