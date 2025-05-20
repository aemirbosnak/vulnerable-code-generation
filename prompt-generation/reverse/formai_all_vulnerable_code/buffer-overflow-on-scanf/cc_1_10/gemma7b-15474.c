//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void unit_converter(int from_unit, int to_unit, float value)
{
  switch (from_unit)
  {
    case 1:
      switch (to_unit)
      {
        case 2:
          value *= 2;
          break;
        case 3:
          value *= 3;
          break;
        case 4:
          value *= 4;
          break;
        default:
          printf("Invalid conversion");
          break;
      }
      break;
    case 2:
      switch (to_unit)
      {
        case 1:
          value *= 0.5;
          break;
        case 3:
          value *= 1.5;
          break;
        case 4:
          value *= 2;
          break;
        default:
          printf("Invalid conversion");
          break;
      }
      break;
    case 3:
      switch (to_unit)
      {
        case 1:
          value *= 0.3333;
          break;
        case 2:
          value *= 0.6666;
          break;
        case 4:
          value *= 3;
          break;
        default:
          printf("Invalid conversion");
          break;
      }
      break;
    default:
      printf("Invalid conversion");
      break;
  }

  printf("Converted value: %.2f", value);
}

int main()
{
  int from_unit, to_unit;
  float value;

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &from_unit);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &to_unit);

  printf("Enter the value you want to convert: ");
  scanf("%f", &value);

  unit_converter(from_unit, to_unit, value);

  return 0;
}