//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void unit_converter(double value, int from_unit, int to_unit)
{
  switch (from_unit)
  {
    case 1:
      switch (to_unit)
      {
        case 2:
          printf("%f liters is equal to %f gallons.\n", value, value * 1.05669);
          break;
        case 3:
          printf("%f liters is equal to %f quarts.\n", value, value * 1.05669 * 4);
          break;
        case 4:
          printf("%f liters is equal to %f pints.\n", value, value * 1.05669 * 4 * 2);
          break;
      }
      break;
    case 2:
      switch (to_unit)
      {
        case 1:
          printf("%f gallons is equal to %f liters.\n", value, value * 1.05669);
          break;
        case 3:
          printf("%f gallons is equal to %f quarts.\n", value, value * 1.05669 * 4);
          break;
        case 4:
          printf("%f gallons is equal to %f pints.\n", value, value * 1.05669 * 4 * 2);
          break;
      }
      break;
    case 3:
      switch (to_unit)
      {
        case 1:
          printf("%f quarts is equal to %f liters.\n", value, value * 1.05669 * 4);
          break;
        case 2:
          printf("%f quarts is equal to %f gallons.\n", value, value * 1.05669 * 4);
          break;
        case 4:
          printf("%f quarts is equal to %f pints.\n", value, value * 1.05669 * 4 * 2);
          break;
      }
      break;
    case 4:
      switch (to_unit)
      {
        case 1:
          printf("%f pints is equal to %f liters.\n", value, value * 1.05669 * 4 * 2);
          break;
        case 2:
          printf("%f pints is equal to %f gallons.\n", value, value * 1.05669 * 4 * 2);
          break;
        case 3:
          printf("%f pints is equal to %f quarts.\n", value, value * 1.05669 * 4 * 2);
          break;
      }
      break;
  }
}

int main()
{
  double value;
  int from_unit, to_unit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit (1 - liter, 2 - gallon, 3 - quart, 4 - pint): ");
  scanf("%d", &from_unit);

  printf("Enter the to unit (1 - liter, 2 - gallon, 3 - quart, 4 - pint): ");
  scanf("%d", &to_unit);

  unit_converter(value, from_unit, to_unit);

  return 0;
}