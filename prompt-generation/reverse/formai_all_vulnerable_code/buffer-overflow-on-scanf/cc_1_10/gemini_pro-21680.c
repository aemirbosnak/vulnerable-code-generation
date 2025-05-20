//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONVERTERS 3

typedef struct {
  char *name;
  double (*convert)(double);
} converter_t;

double to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

double to_kelvin(double celsius) {
  return celsius + 273.15;
}

converter_t converters[] = {
  { "Celsius to Fahrenheit", to_fahrenheit },
  { "Fahrenheit to Celsius", to_celsius },
  { "Celsius to Kelvin", to_kelvin },
};

int main() {
  int choice;
  double value;
  char input[100];

  printf("Welcome to the dynamic unit converter!\n\n");
  printf("Available conversions:\n");

  for (int i = 0; i < CONVERTERS; i++) {
    printf("%d. %s\n", i + 1, converters[i].name);
  }

  printf("\nEnter your choice (1-%d): ", CONVERTERS);
  scanf("%d", &choice);

  printf("\nEnter the value to convert: ");
  scanf("%lf", &value);

  if (choice >= 1 && choice <= CONVERTERS) {
    double result = converters[choice - 1].convert(value);
    printf("\nResult: %.2lf\n", result);
  } else {
    printf("\nInvalid choice. Please enter a number between 1 and %d.\n", CONVERTERS);
  }

  printf("\nPress any key to exit...");
  getchar();
  getchar();

  return 0;
}