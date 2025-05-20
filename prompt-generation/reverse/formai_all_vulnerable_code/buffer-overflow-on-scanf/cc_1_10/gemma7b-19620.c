//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void unit_converter(int unit_from, int unit_to, double value)
{
  switch (unit_from)
  {
    case 0:
      switch (unit_to)
      {
        case 0:
          printf("The value is the same.\n");
          break;
        case 1:
          printf("The value is doubled.\n");
          break;
        case 2:
          printf("The value is tripled.\n");
          break;
      }
      break;
    case 1:
      switch (unit_to)
      {
        case 0:
          printf("The value is halved.\n");
          break;
        case 1:
          printf("The value is the same.\n");
          break;
        case 2:
          printf("The value is tripled.\n");
          break;
      }
      break;
    case 2:
      switch (unit_to)
      {
        case 0:
          printf("The value is one third.\n");
          break;
        case 1:
          printf("The value is doubled.\n");
          break;
        case 2:
          printf("The value is the same.\n");
          break;
      }
      break;
  }
}

int main()
{
  int unit_from, unit_to;
  double value;

  printf("Enter the unit you want to convert from (0, 1, 2): ");
  scanf("%d", &unit_from);

  printf("Enter the unit you want to convert to (0, 1, 2): ");
  scanf("%d", &unit_to);

  printf("Enter the value you want to convert: ");
  scanf("%lf", &value);

  unit_converter(unit_from, unit_to, value);

  return 0;
}