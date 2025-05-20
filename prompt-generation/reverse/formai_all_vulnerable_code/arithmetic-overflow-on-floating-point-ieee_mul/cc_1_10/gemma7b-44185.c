//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void unit_converter(int unit_from, int unit_to, float value)
{
  switch (unit_from)
  {
    case 1:
      switch (unit_to)
      {
        case 2:
          value *= 2;
          break;
        case 3:
          value *= 3;
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 2:
      switch (unit_to)
      {
        case 1:
          value *= 0.5;
          break;
        case 3:
          value *= 1.5;
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 3:
      switch (unit_to)
      {
        case 1:
          value *= 0.3333;
          break;
        case 2:
          value *= 0.6666;
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    default:
      printf("Invalid unit conversion.\n");
      break;
  }
  printf("The converted value is: %.2f\n", value);
}

int main()
{
  int unit_from, unit_to;
  float value;

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &unit_from);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &unit_to);

  printf("Enter the value you want to convert: ");
  scanf("%f", &value);

  unit_converter(unit_from, unit_to, value);

  return 0;
}