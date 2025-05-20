//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(void)
{
  int i, j, k, r, t, ghosts = 0, sound_effect = 0;
  char ch;
  time_t start_time, end_time, elapsed_time;

  // Generate random number of ghosts
  ghosts = rand() % 5 + 1;

  // Set the timer
  start_time = time(NULL);

  // Create a haunted house scenario
  for (i = 0; i < ghosts; i++)
  {
    // Randomly choose a sound effect
    sound_effect = rand() % 3;

    // Play the sound effect
    switch (sound_effect)
    {
      case 0:
        printf("Footsteps...\n");
        break;
      case 1:
        printf("Screams...\n");
        break;
      case 2:
        printf("Gasps...\n");
        break;
    }

    // Flash the lights
    for (j = 0; j < 5; j++)
    {
      printf("The lights flicker...\n");
      sleep(1);
    }

    // Move the ghosts
    for (k = 0; k < ghosts; k++)
    {
      printf("The ghosts move...\n");
      sleep(1);
    }
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the elapsed time
  elapsed_time = end_time - start_time;

  // Print the elapsed time
  printf("You survived for %d seconds!\n", elapsed_time);

  // Prompt the user to press any key to continue
  ch = getchar();
}

int main(void)
{
  haunted_house();

  return 0;
}