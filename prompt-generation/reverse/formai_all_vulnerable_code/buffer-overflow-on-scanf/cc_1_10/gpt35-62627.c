//FormAI DATASET v1.0 Category: Robot movement control ; Style: genious
#include<stdio.h>

int main()
{
  int i, j, k;
  char direction[4] = {'N', 'S', 'E', 'W'}; 
  int x_pos = 0, y_pos = 0; // robot's initial position
  int x_move = 0, y_move = 0; // movement inputs
  int facing = 0; // initial facing direction (0 = North)

  printf("Welcome to Robot Movement Control Program\n\n");
  printf("Enter movement coordinates (x y): ");
  scanf("%d %d", &x_move, &y_move);

  printf("\nRobot Movement Log:\n");
  printf("Initial Position: (%d, %d), facing %c\n", x_pos, y_pos, direction[facing]);

  if(y_move > 0)
  {
    for(i = 0; i < y_move; i++)
    {
      y_pos++;
      printf("Moved North. Current Position: (%d, %d), facing %c\n", x_pos, y_pos, direction[facing]);
    }
  }
  else if(y_move < 0)
  {
    for(i = 0; i > y_move; i--)
    {
      y_pos--;
      printf("Moved South. Current Position: (%d, %d), facing %c\n", x_pos, y_pos, direction[facing]);
    }
  }
  
  if(x_move > 0)
  {
    facing = 2;
    for(j = 0; j < x_move; j++)
    {
      x_pos++;
      printf("Moved East. Current Position: (%d, %d), facing %c\n", x_pos, y_pos, direction[facing]);
    }
  }
  else if(x_move < 0)
  {
    facing = 3;
    for(j = 0; j > x_move; j--)
    {
      x_pos--;
      printf("Moved West. Current Position: (%d, %d), facing %c\n", x_pos, y_pos, direction[facing]);
    }
  }

  printf("\nFinal Position: (%d, %d), facing %c\n", x_pos, y_pos, direction[facing]);
  printf("\nThank you for using Robot Movement Control Program.\n");

  return 0;
}