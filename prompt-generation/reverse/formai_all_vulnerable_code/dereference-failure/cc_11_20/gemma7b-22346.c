//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  // Seed the RNG with the current time
  srand(time(NULL));

  // Create a pool of potential suspects
  char **suspects = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++)
  {
    suspects[i] = malloc(20 * sizeof(char));
  }

  // Populate the suspects with random names and traits
  for (int i = 0; i < 10; i++)
  {
    sprintf(suspects[i], "Suspect %d", i + 1);
    switch (rand() % 3)
    {
      case 0:
        strcat(suspects[i], " is a cunning mastermind.");
        break;
      case 1:
        strcat(suspects[i], " is a loyal lieutenant.");
        break;
      case 2:
        strcat(suspects[i], " is a suspicious character.");
        break;
    }
  }

  // Create a list of potential motives
  char **motivations = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++)
  {
    motivations[i] = malloc(20 * sizeof(char));
  }

  // Populate the motivations with random reasons
  for (int i = 0; i < 5; i++)
  {
    sprintf(motivations[i], "Motivation %d", i + 1);
    switch (rand() % 3)
    {
      case 0:
        strcat(motivations[i], " is greed.");
        break;
      case 1:
        strcat(motivations[i], " is revenge.");
        break;
      case 2:
        strcat(motivations[i], " is ideology.");
        break;
    }
  }

  // Generate the conspiracy theory
  char *conspiracy_theory = malloc(200 * sizeof(char));
  sprintf(conspiracy_theory, "The plot unfolds as a web of deceit, woven by a sinister force. Among the suspects, %s is the mastermind behind this treacherous act, driven by their %s.", suspects[rand() % 10], motivations[rand() % 5]);

  // Print the conspiracy theory
  printf("%s\n", conspiracy_theory);

  // Free the memory allocated for the suspects and motivations
  for (int i = 0; i < 10; i++)
  {
    free(suspects[i]);
  }
  free(suspects);

  for (int i = 0; i < 5; i++)
  {
    free(motivations[i]);
  }
  free(motivations);

  free(conspiracy_theory);

  return 0;
}