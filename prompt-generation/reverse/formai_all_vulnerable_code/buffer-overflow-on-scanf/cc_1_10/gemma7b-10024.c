//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int);

int main()
{
  int choice;

  // Seed the random number generator
  srand(time(NULL));

  // Create a haunted house
  haunt(1);

  // Display the haunted house
  printf("You have entered the haunted house.\n");
  printf("The air is thick with the scent of decay and desperation.\n");
  printf("You hear the sound of your own breathing echoing through the halls.\n");
  printf("Suddenly, a cold wind blows through the house, extinguishing the candles.\n");
  printf("You feel a presence brushing against your skin.\n");

  // Prompt the user to make a choice
  printf("What do you want to do? (1) Run, (2) Hide, (3) Fight\n");
  scanf("%d", &choice);

  // Respond to the user's choice
  switch (choice)
  {
    case 1:
      printf("You ran out of the haunted house.\n");
      break;
    case 2:
      printf("You hid in a room. The haunted house stood still.\n");
      break;
    case 3:
      printf("You fought back against the presence. It retreated.\n");
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}

void haunt(int number)
{
  // Create a haunted room
  for (int i = 0; i < number; i++)
  {
    printf("Room %d:\n", i + 1);
    printf("There is a sense of dread in the air.\n");
    printf("You hear the sound of footsteps echoing through the hallway.\n");
    printf("Suddenly, the lights go out.\n");
  }
}