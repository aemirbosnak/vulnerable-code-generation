//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void moonstone_converter(int);

int main()
{
  int choice;

  printf("Welcome to the Mystical Moonstone Converter!\n");
  printf("Please select an option:\n");
  printf("1. Convert kilograms to moons\n");
  printf("2. Convert moons to kilograms\n");
  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      moonstone_converter(1);
      break;
    case 2:
      moonstone_converter(2);
      break;
    default:
      printf("Invalid selection. Please try again.\n");
  }

  return 0;
}

void moonstone_converter(int direction)
{
  int moons, kilograms;
  double conversion_factor = 0.001;

  printf("Please enter the number of moons you want to convert:** ");
  scanf("%d", &moons);

  switch (direction)
  {
    case 1:
      kilograms = moons * conversion_factor;
      printf("The number of kilograms is: %d\n", kilograms);
      break;
    case 2:
      kilograms = moons * conversion_factor;
      printf("The number of kilograms is: %d\n", kilograms);
      break;
    default:
      printf("Invalid conversion direction. Please try again.\n");
  }
}