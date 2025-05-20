//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jump_scare(int target)
{
  sleep(target);
  printf("BOO!\n");
  sleep(1);
}

int main()
{
  int i, target_scare, option;
  char name[20];

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Welcome, %s, to the Haunted House of Horrors!\n", name);

  printf("Would you like to enter? (1/2) ");
  scanf("%d", &option);

  if (option == 1)
  {
    printf("You cautiously open the front door...\n");

    target_scare = rand() % 5 + 1;
    jump_scare(target_scare);

    printf("The door slams shut. You hear footsteps approaching...\n");

    target_scare = rand() % 5 + 1;
    jump_scare(target_scare);

    printf("A cold wind whips through the halls, carrying the scent of decay...\n");

    target_scare = rand() % 5 + 1;
    jump_scare(target_scare);

    printf("Suddenly, the lights go out... You are alone in the dark...\n");

    target_scare = rand() % 5 + 1;
    jump_scare(target_scare);

    printf("The sound of your own breathing fills your ears... Are you still alive?\n");

    target_scare = rand() % 5 + 1;
    jump_scare(target_scare);

    printf("You escape the haunted house, forever scarred by your experience...\n");
  }
  else
  {
    printf("You wisely decide to turn around and flee...\n");
  }

  return 0;
}