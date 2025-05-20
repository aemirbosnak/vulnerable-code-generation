//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void main()
{
  // Define the adventure map
  int map[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  // Initialize the player's position
  int x = 0;
  int y = 0;

  // Start the game loop
  while (1)
  {
    // Print the map
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        printf("%c ", map[i][j]);
      }
      printf("\n");
    }

    // Get the player's input
    char input;
    printf("Enter your move (N, S, E, W): ");
    scanf("%c", &input);

    // Move the player
    switch (input)
    {
      case 'N':
        y--;
        break;
      case 'S':
        y++;
        break;
      case 'E':
        x++;
        break;
      case 'W':
        x--;
        break;
    }

    // Check if the player has won or lost
    if (map[y][x] == 3)
    {
      printf("You have won!");
      break;
    }
    else if (map[y][x] == 2)
    {
      printf("You have lost!");
      break;
    }
  }

  return;
}