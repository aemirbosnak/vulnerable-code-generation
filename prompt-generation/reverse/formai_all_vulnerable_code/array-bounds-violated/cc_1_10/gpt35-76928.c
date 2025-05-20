//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

int is_valid_unit(char *unit);
double convert(double value, char *from_unit, char *to_unit);
void print_units();
void get_input(char *input);

/* Conversion data */
double units[][2] = {
  {1.0, 0.0}, /* meters to meters */
  {0.3048, 0.0}, /* feet to meters */
  {3.28084, 0.0}, /* meters to feet */
  {1.0, 0.0}, /* to be continued... */
};

char *unit_names[] = {
  "meters",
  "feet",
  "feet",
  "celsius",
  "fahrenheit",
  "fahrenheit",
};

char *shapeshift(int n) {
  switch(n) {
    case 0: return "meters";
    case 1: return "feet";
    case 2: return "celsius";
    case 3: return "fahrenheit";
    default: return "";
  }
}

int main() {
  double value;
  char from_unit[MAX_INPUT_LENGTH], to_unit[MAX_INPUT_LENGTH], input[MAX_INPUT_LENGTH];

  printf("Welcome to the Shape-Shifting Unit Converter!\n");
  printf("==============================================\n\n");

  print_units();

  printf("\nPlease enter the starting measurement: ");
  get_input(input);
  if (!is_valid_unit(input)) {
    printf("Invalid input. Please try again.\n");
  } else {
    strcpy(from_unit, input);

    printf("Please enter the measurement to convert to: ");
    get_input(input);
    if (!is_valid_unit(input)) {
      printf("Invalid input. Please try again.\n");
    } else {
      strcpy(to_unit, input);

      printf("Please enter the starting value: ");
      scanf("%lf", &value);

      double result = convert(value, from_unit, to_unit);

      printf("%lf %s is equal to %lf %s.\n", value, shapeshift(from_unit), result, shapeshift(to_unit));
    }
  }

  return 0;
}

int is_valid_unit(char *unit) {
  int i, n = sizeof(unit_names) / sizeof(unit_names[0]);
  for (i = 0; i < n; i++) {
    if (strcmp(unit_names[i], unit) == 0) {
      return 1;
    }
  }
  return 0;
}

double convert(double value, char *from_unit, char *to_unit) {
  int i, n = sizeof(unit_names) / sizeof(unit_names[0]);

  int from_idx = -1, to_idx = -1;
  for (i = 0; i < n; i++) {
    if (strcmp(unit_names[i], from_unit) == 0) {
      from_idx = i;
    }
    if (strcmp(unit_names[i], to_unit) == 0) {
      to_idx = i;
    }
    if (from_idx != -1 && to_idx != -1) {
      break;
    }
  }

  if (from_idx == to_idx) {
    return value;
  }

  double conversion_factor = units[from_idx][to_idx];
  if (conversion_factor == 0.0) {
    conversion_factor = 1.0 / units[to_idx][from_idx];
    value = value * conversion_factor;
    conversion_factor = 1.0 / conversion_factor;
  } else {
    value = value * conversion_factor;
  }

  return value;
}

void print_units() {
  int i, j, n = sizeof(unit_names) / sizeof(unit_names[0]);
  for (i = 0; i < n; i++) {
    printf("%s to:\n", shapeshift(i));
    for (j = 0; j < n; j++) {
      if (units[i][j] != 0.0) {
        printf("  %s\n", shapeshift(j));
      }
    }
    printf("\n");
  }
}

void get_input(char *input) {
  fgets(input, MAX_INPUT_LENGTH, stdin);

  /* Remove any trailing newline characters */
  int len = strlen(input);
  if (input[len - 1] == '\n') {
    input[len - 1] = '\0';
  }
}