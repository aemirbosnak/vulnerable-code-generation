//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void introspective_temperature_converter(float, char);

int main()
{
  float temperature;
  char unit;

  printf("Enter the temperature: ");
  scanf("%f", &temperature);

  printf("Enter the unit (C/F/K): ");
  scanf(" %c", &unit);

  introspective_temperature_converter(temperature, unit);

  return 0;
}

void introspective_temperature_converter(float temperature, char unit)
{
  float conversion_factor;
  char target_unit;

  switch (unit)
  {
    case 'C':
      conversion_factor = 1;
      target_unit = 'F';
      break;
    case 'F':
      conversion_factor = 1.8;
      target_unit = 'K';
      break;
    case 'K':
      conversion_factor = 0.5556;
      target_unit = 'C';
      break;
    default:
      printf("Invalid unit.\n");
      return;
  }

  temperature *= conversion_factor;
  target_unit = target_unit;

  printf("The converted temperature is: %.2f %c.\n", temperature, target_unit);
}