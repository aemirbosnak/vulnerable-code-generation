//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int choice, suspect, location, is_correct = 0;
  char name[20];

  // Welcome the player to the case
  printf("Welcome to the Case of the Missing Diamond.\n");

  // Get the player's name
  printf("Please enter your name: ");
  scanf("%s", name);

  // Present the suspects and their locations
  printf("There are three suspects in the case:\n");
  printf("1. Mr. Jones - The Study.\n");
  printf("2. Mrs. Smith - The Library.\n");
  printf("3. Mr. Brown - The Dining Hall.\n");

  // Get the player's choice
  printf("Please select a suspect: ");
  scanf("%d", &choice);

  // Check if the player's choice is correct
  if (choice == 1)
  {
    suspect = 1;
    location = 1;
  }
  else if (choice == 2)
  {
    suspect = 2;
    location = 2;
  }
  else if (choice == 3)
  {
    suspect = 3;
    location = 3;
  }
  else
  {
    printf("Invalid choice.\n");
    return 1;
  }

  // Reveal the suspect's location
  printf("The suspect is located in the %d.", location);

  // Check if the player's guess is correct
  if (suspect == 1 && location == 1)
  {
    is_correct = 1;
  }

  // Reveal the result
  if (is_correct)
  {
    printf("Congratulations, %s, you have solved the case!", name);
  }
  else
  {
    printf("Sorry, %s, you have not solved the case.", name);
  }

  return 0;
}