//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("Welcome! I am your new robot friend. Let's play a game.\n");

  int i, j, moves, position, direction;
  char choice;
  srand(time(0)); // seed random number generator

  printf("First, let's choose a random starting position.\n");
  position = rand() % 100 + 1; // choose random number between 1 and 100
  printf("Starting position: %d\n", position);

  printf("Now, let's choose a random direction to move in (left or right).\n");
  direction = rand() % 2; // choose random number either 0 or 1
  if (direction == 0)
    printf("Moving left...\n");
  else
    printf("Moving right...\n");

  printf("How many moves would you like to take?\n");
  scanf("%d", &moves);

  // move robot
  for (i = 1; i <= moves; i++)
  {
    if (direction == 0)
      position--; // move left
    else
      position++; // move right
    printf("Position after move %d: %d\n", i, position);
  }

  // ask user if they want to play again
  printf("Game over. Would you like to play again? (y/n)\n");
  scanf(" %c", &choice);

  while (choice == 'y')
  {
    printf("Great! Let's play again.\n");

    // choose new random starting position and direction
    position = rand() % 100 + 1;
    direction = rand() % 2;
    if (direction == 0)
      printf("Moving left...\n");
    else
      printf("Moving right...\n");

    printf("How many moves would you like to take?\n");
    scanf("%d", &moves);

    printf("Let's go!\n");

    // move robot
    for (j = 1; j <= moves; j++)
    {
      if (direction == 0)
        position--;
      else
        position++;
      printf("Position after move %d: %d\n", j, position);
    }

    // ask user if they want to play again
    printf("Game over. Would you like to play again? (y/n)\n");
    scanf(" %c", &choice);
  }

  printf("Thanks for playing with me! Goodbye.\n");
  return 0;
}