//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // The master detective's case file
  char caseFile[1000];

  // Holmes' trusty magnifying glass
  char *magnifyingGlass;

  // Watson's keen observations
  char observations[1000];

  // The enigmatic clue
  char clue[] = "The dog did nothing in the night-time.";

  // Holmes begins his investigation
  printf("My dear Watson, let us examine this case file.\n");
  gets(caseFile);

  // Holmes uses his magnifying glass to search for clues
  magnifyingGlass = strstr(caseFile, clue);

  if (magnifyingGlass != NULL)
  {
    printf("Ah, Watson! I have found a clue.\n");
    strncpy(observations, magnifyingGlass, strlen(clue));
  }
  else
  {
    printf("It appears this case file contains no clues, Watson.\n");
  }

  // Holmes analyzes the clue
  char *dog = strstr(observations, "dog");
  char *night = strstr(observations, "night");

  if (dog != NULL && night != NULL)
  {
    printf("Curious, Watson. The dog did nothing in the night-time.\n");

    // Holmes uses his deductive reasoning to solve the case
    printf("I believe the dog was not barking, which means there was no intruder in the night-time.\n");
  }
  else
  {
    printf("The clue is incomplete, Watson. I cannot deduce a solution.\n");
  }

  return 0;
}