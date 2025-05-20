//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <math.h>

double convert_unit(double value, int from_unit, int to_unit)
{
  double conversion_factor;

  switch (from_unit)
  {
    case 0:
      conversion_factor = 1;
      break;
    case 1:
      conversion_factor = 1000;
      break;
    case 2:
      conversion_factor = 1000000;
      break;
    default:
      printf("Invalid unit conversion.\n");
      return -1;
  }

  switch (to_unit)
  {
    case 0:
      conversion_factor = 1;
      break;
    case 1:
      conversion_factor = 1000;
      break;
    case 2:
      conversion_factor = 1000000;
      break;
    default:
      printf("Invalid unit conversion.\n");
      return -1;
  }

  return value * conversion_factor * conversion_factor;
}

int main()
{
  double value;
  int from_unit, to_unit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit (0, 1, 2): ");
  scanf("%d", &from_unit);

  printf("Enter the to unit (0, 1, 2): ");
  scanf("%d", &to_unit);

  double converted_value = convert_unit(value, from_unit, to_unit);

  if (converted_value != -1)
  {
    printf("The converted value is: %.2lf\n", converted_value);
  }

  return 0;
}