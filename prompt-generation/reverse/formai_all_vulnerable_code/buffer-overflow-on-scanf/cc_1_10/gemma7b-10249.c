//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int);

int main()
{
  int i, choice;

  printf("Welcome to the Haunted House Simulator!\n");
  printf("Please select an option:\n");
  printf("1. Enter the house\n");
  printf("2. Exit\n");

  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      haunted_house(1);
      break;
    case 2:
      exit(0);
  }

  return 0;
}

void haunted_house(int level)
{
  int i, j, sound, jump_scare;

  if (level == 1)
  {
    printf("You have entered the haunted house. The door slams shut.\n");
  }
  else if (level == 2)
  {
    printf("You hear footsteps in the hallway.\n");
  }
  else if (level == 3)
  {
    printf("You see a ghostly figure hovering over you.\n");
  }

  sound = rand() % 3;
  jump_scare = rand() % 2;

  if (sound == 0)
  {
    printf("You hear a creepy whisper.\n");
  }
  else if (sound == 1)
  {
    printf("You hear a door slamming shut.\n");
  }
  else if (sound == 2)
  {
    printf("You hear a scream.\n");
  }

  if (jump_scare == 0)
  {
    printf("Suddenly, a gust of wind blows through the house.\n");
  }
  else if (jump_scare == 1)
  {
    printf("A ghostly hand reaches out to grab you.\n");
  }

  haunted_house(level + 1);
}