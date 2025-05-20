//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

int main()
{
  int num, unit, target_unit, conversion_factor;
  float result;

  printf("Enter the number you want to convert: ");
  scanf("%d", &num);

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &unit);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &target_unit);

  switch (unit)
  {
    case 1:
      conversion_factor = 1000;
      break;
    case 2:
      conversion_factor = 1000000;
      break;
    case 3:
      conversion_factor = 1000000000;
      break;
    default:
      printf("Invalid unit.\n");
      exit(1);
  }

  switch (target_unit)
  {
    case 1:
      conversion_factor = 1000;
      break;
    case 2:
      conversion_factor = 1000000;
      break;
    case 3:
      conversion_factor = 1000000000;
      break;
    default:
      printf("Invalid target unit.\n");
      exit(1);
  }

  result = (float)num * conversion_factor / conversion_factor;

  printf("The result is: %.2f %s.\n", result, target_unit);

  return 0;
}