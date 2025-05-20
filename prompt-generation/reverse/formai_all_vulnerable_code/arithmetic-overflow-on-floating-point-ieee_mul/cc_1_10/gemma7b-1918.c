//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_ConverTION_LIMIT 500

typedef struct Conversion {
  double value;
  char unit;
  char conversion_type;
} Conversion;

Conversion convert_temperature(double value, char unit, char conversion_type) {
  Conversion conversion;

  switch (conversion_type) {
    case 'C':
      conversion.value = value;
      conversion.unit = 'C';
      conversion.conversion_type = 'C';
      break;
    case 'F':
      conversion.value = (value - 32) * 5 / 9;
      conversion.unit = 'F';
      conversion.conversion_type = 'F';
      break;
    case 'K':
      conversion.value = value + 273.15;
      conversion.unit = 'K';
      conversion.conversion_type = 'K';
      break;
  }

  return conversion;
}

int main() {
  double value;
  char unit, conversion_type;

  printf("Enter the temperature value: ");
  scanf("%lf", &value);

  printf("Enter the unit of the temperature (C, F, K): ");
  scanf(" %c", &unit);

  printf("Enter the conversion type (C, F, K): ");
  scanf(" %c", &conversion_type);

  Conversion conversion = convert_temperature(value, unit, conversion_type);

  printf("The converted temperature is: %.2lf %c", conversion.value, conversion.unit);

  return 0;
}