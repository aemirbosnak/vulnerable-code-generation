//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int);

int main()
{
  int choice = 0;

  printf("Welcome to the Haunted House Simulator!\n");
  printf("Please make a choice:\n");
  printf("1. Enter the house\n");
  printf("2. Leave the house\n");

  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      haunted_house(1);
      break;
    case 2:
      printf("Thank you for visiting the Haunted House Simulator.\n");
      break;
    default:
      printf("Invalid input.\n");
  }

  return 0;
}

void haunted_house(int level)
{
  int i, j, k, random_number;

  printf("You have entered the haunted house.\n");

  for (i = 0; i < level; i++)
  {
    for (j = 0; j < level; j++)
    {
      for (k = 0; k < level; k++)
      {
        random_number = rand() % 2;

        if (random_number == 0)
        {
          printf("Boo!\n");
        }
      }
    }
  }

  printf("You have escaped the haunted house.\n");
}