//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // You are in a mysterious forest clearing. There is a towering oak tree in the center.
  // You have no idea how you got here.

  // The clearing is 5x5 squares. You are at (0, 0).
  char map[5][5] = {
    {'O', '.', '.', '.', '.'},
    {'.', 'T', '.', '.', '.'},
    {'.', '.', 'O', '.', '.'},
    {'.', '.', '.', 'O', '.'},
    {'.', '.', '.', '.', '.'}
  };

  // What do you want to do? (N, S, E, W)
  char direction;

  // Loop until the player chooses a direction.
  while (direction == '\0')
  {
    printf("Enter your direction (N, S, E, W): ");
    scanf(" %c", &direction);

    // Check if the direction is valid.
    if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W')
    {
      printf("Invalid direction.\n");
    }
  }

  // Move in the direction the player chose.
  switch (direction)
  {
    case 'N':
      map[0][0] = 'P';
      break;
    case 'S':
      map[4][0] = 'P';
      break;
    case 'E':
      map[0][4] = 'P';
      break;
    case 'W':
      map[0][1] = 'P';
      break;
  }

  // Print the updated map.
  for (int r = 0; r < 5; r++)
  {
    for (int c = 0; c < 5; c++)
    {
      printf("%c ", map[r][c]);
    }
    printf("\n");
  }

  // You have reached the top of the oak tree. You see a mysterious box.

  // What do you want to do with the box? (Open, Close)
  char box_action;

  // Loop until the player chooses an action.
  while (box_action == '\0')
  {
    printf("Enter your action (Open, Close): ");
    scanf(" %c", &box_action);

    // Check if the action is valid.
    if (box_action != 'O' && box_action != 'C')
    {
      printf("Invalid action.\n");
    }
  }

  // Carry out the player's action.
  switch (box_action)
  {
    case 'O':
      printf("You opened the box and found a treasure!\n");
      break;
    case 'C':
      printf("You closed the box.\n");
      break;
  }

  return 0;
}