//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, int unit_from, int unit_to)
{
  float conversion_factor;

  switch (unit_from)
  {
    case 1:
      conversion_factor = 1;
      break;
    case 2:
      conversion_factor = 1000;
      break;
    case 3:
      conversion_factor = 16;
      break;
    default:
      printf("Invalid unit conversion.");
      return;
  }

  switch (unit_to)
  {
    case 1:
      conversion_factor = 1;
      break;
    case 2:
      conversion_factor = 1000;
      break;
    case 3:
      conversion_factor = 16;
      break;
    default:
      printf("Invalid unit conversion.");
      return;
  }

  float converted_value = value * conversion_factor;

  printf("%f %s converted to %f %s is %f.", value, unit_from, unit_to, converted_value);
}

int main()
{
  float value;
  int unit_from, unit_to;

  printf("Enter the value:");
  scanf("%f", &value);

  printf("Enter the unit you want to convert from:");
  scanf("%d", &unit_from);

  printf("Enter the unit you want to convert to:");
  scanf("%d", &unit_to);

  UnitConverter(value, unit_from, unit_to);

  return 0;
}