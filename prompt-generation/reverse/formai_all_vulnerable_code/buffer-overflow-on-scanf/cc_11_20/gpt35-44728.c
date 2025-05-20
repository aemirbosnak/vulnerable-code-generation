//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
  int xPos = 0;
  int yPos = 0;
  char direction[10] = "north";
  bool grid[10][10] = {false};

  printf("Robot movement control program\n\n");

  while (true)
  {
    char input[10];
    printf("Enter command (up, down, left, right, report, exit): ");
    scanf("%s", input);

    if (strcmp(input, "up") == 0)
    {
      if (yPos < 9)
      {
        ++yPos;
        grid[xPos][yPos] = true;
      }
      else
      {
        printf("Cannot move up, at edge of grid\n");
      }
    }
    else if (strcmp(input, "down") == 0)
    {
      if (yPos > 0)
      {
        --yPos;
        grid[xPos][yPos] = true;
      }
      else
      {
        printf("Cannot move down, at edge of grid\n");
      }
    }
    else if (strcmp(input, "left") == 0)
    {
      if (xPos > 0)
      {
        --xPos;
        grid[xPos][yPos] = true;
      }
      else
      {
        printf("Cannot move left, at edge of grid\n");
      }
    }
    else if (strcmp(input, "right") == 0)
    {
      if (xPos < 9)
      {
        ++xPos;
        grid[xPos][yPos] = true;
      }
      else
      {
        printf("Cannot move right, at edge of grid\n");
      }
    }
    else if (strcmp(input, "report") == 0)
    {
      printf("Current position: (%d, %d) facing %s\n", xPos, yPos, direction);
      printf("Visited squares: ");
      for (int i = 0; i < 10; ++i)
      {
        for (int j = 0; j < 10; ++j)
        {
          if (grid[i][j])
          {
            printf("(%d, %d) ", i, j);
          }
        }
      }
      printf("\n");
    }
    else if (strcmp(input, "exit") == 0)
    {
      break;
    }
    else
    {
      printf("Invalid command\n");
    }
  }

  return 0;
}