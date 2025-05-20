//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

typedef struct Conv_Table {
  char unit_from[MAX_CONVERT];
  char unit_to[MAX_CONVERT];
  double conversion_factor;
} Conv_Table_t;

Conv_Table_t conv_table[] = {
  {"kg", "g", 1000.0},
  {"L", "ml", 1000.0},
  {"km", "m", 1000.0},
  {"km/h", "m/s", 3.6},
  {"°C", "°F", (double) 1.8 + 32.0}
};

int main()
{
  double value;
  char unit_from, unit_to;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the unit you are converting from: ");
  scanf(" %c", &unit_from);

  printf("Enter the unit you are converting to: ");
  scanf(" %c", &unit_to);

  for (int i = 0; i < MAX_CONVERT; i++)
  {
    if (conv_table[i].unit_from[0] == unit_from && conv_table[i].unit_to[0] == unit_to)
    {
      double conversion_factor = conv_table[i].conversion_factor;
      double converted_value = value * conversion_factor;

      printf("The converted value is: %.2lf %s", converted_value, conv_table[i].unit_to);
      break;
    }
  }

  if (unit_from == '\0' || unit_to == '\0')
  {
    printf("Invalid unit input");
  }

  return 0;
}