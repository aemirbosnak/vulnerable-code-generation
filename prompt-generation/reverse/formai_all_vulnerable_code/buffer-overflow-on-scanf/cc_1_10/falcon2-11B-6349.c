//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

float convert_unit(float value, char* from_unit, char* to_unit);

int main() {
  float value, converted_value;

  printf("Enter a value: ");
  scanf("%f", &value);

  printf("Enter a unit to convert from: ");
  char from_unit[10];
  scanf("%s", from_unit);

  printf("Enter a unit to convert to: ");
  char to_unit[10];
  scanf("%s", to_unit);

  converted_value = convert_unit(value, from_unit, to_unit);

  printf("Converted value: %.2f %s\n", converted_value, to_unit);

  return 0;
}

float convert_unit(float value, char* from_unit, char* to_unit) {
  float conversion_factor;
  float converted_value;

  if (strcmp(from_unit, "celsius") == 0 && strcmp(to_unit, "fahrenheit") == 0) {
    conversion_factor = 1.8f;
  } else if (strcmp(from_unit, "celsius") == 0 && strcmp(to_unit, "kelvin") == 0) {
    conversion_factor = 273.15f;
  } else if (strcmp(from_unit, "fahrenheit") == 0 && strcmp(to_unit, "celsius") == 0) {
    conversion_factor = (1.8f - 32) / 1.8f;
  } else if (strcmp(from_unit, "fahrenheit") == 0 && strcmp(to_unit, "kelvin") == 0) {
    conversion_factor = (1.8f + 459.67f) / 1.8f;
  } else if (strcmp(from_unit, "kelvin") == 0 && strcmp(to_unit, "celsius") == 0) {
    conversion_factor = -273.15f;
  } else if (strcmp(from_unit, "kelvin") == 0 && strcmp(to_unit, "fahrenheit") == 0) {
    conversion_factor = (1.8f + 459.67f) / 1.8f;
  } else {
    printf("Invalid unit combination.\n");
    return 0;
  }

  converted_value = value * conversion_factor;

  return converted_value;
}