//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <math.h>

int main()
{
  int choice;
  float num;
  char unit_from, unit_to;

  printf("Welcome to the Celestial Conversion Chamber.\n");
  printf("Please choose an option:\n");
  printf("1. Convert Fahrenheit to Celsius\n");
  printf("2. Convert Celsius to Fahrenheit\n");
  printf("3. Convert meters to miles\n");
  printf("4. Convert miles to meters\n");

  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      printf("Enter the temperature in Fahrenheit:");
      scanf("%f", &num);
      unit_from = 'F';
      unit_to = 'C';
      break;
    case 2:
      printf("Enter the temperature in Celsius:");
      scanf("%f", &num);
      unit_from = 'C';
      unit_to = 'F';
      break;
    case 3:
      printf("Enter the distance in meters:");
      scanf("%f", &num);
      unit_from = 'M';
      unit_to = 'M';
      break;
    case 4:
      printf("Enter the distance in miles:");
      scanf("%f", &num);
      unit_from = 'M';
      unit_to = 'L';
      break;
    default:
      printf("Invalid choice.\n");
  }

  if (unit_from != unit_to)
  {
    float converted_num = 0;

    switch (unit_from)
    {
      case 'F':
        converted_num = (num - 32) * 5 / 9;
        break;
      case 'C':
        converted_num = (num * 9 / 5) + 32;
        break;
      case 'M':
        converted_num = num * 1609.344;
        break;
      case 'L':
        converted_num = num * 1609.344;
        break;
    }

    printf("The converted temperature is: %.2f %s.\n", converted_num, unit_to);
  }
  else
  {
    printf("No conversion necessary.\n");
  }

  return 0;
}