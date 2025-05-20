//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10

int main()
{
  int speed = 0;
  int direction = 1;
  char key;

  while (1)
  {
    printf("Press 'w' to accelerate, 'a' to decelerate, 's' to steer, 'q' to quit: ");
    scanf(" %c", &key);

    switch (key)
    {
      case 'w':
        if (speed < MAX_SPEED)
        {
          speed++;
          printf("Car is moving forward at %d km/h.\n", speed);
        }
        else
        {
          printf("Car is already moving at maximum speed.\n");
        }
        break;

      case 'a':
        if (speed > 0)
        {
          speed--;
          printf("Car is moving forward at %d km/h.\n", speed);
        }
        else
        {
          printf("Car is already stopped.\n");
        }
        break;

      case 's':
        printf("Please enter the direction you want to steer (left or right): ");
        scanf(" %c", &direction);

        if (direction == 'l')
        {
          printf("Car is turning left.\n");
        }
        else if (direction == 'r')
        {
          printf("Car is turning right.\n");
        }
        else
        {
          printf("Invalid direction.\n");
        }
        break;

      case 'q':
        printf("Goodbye!\n");
        exit(0);
        break;

      default:
        printf("Invalid key.\n");
        break;
    }
  }

  return 0;
}