//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: invasive
#include <stdio.h>

int main()
{
  printf("Welcome to the Remote Control Vehicle Simulator\n\n");

  int speed = 0;
  int direction = 0;
  int battery_level = 100;

  while (1)
  {
    printf("Battery Level: %d%%\n", battery_level);
    printf("Current Speed: %d mph\n", speed);
    printf("Current Direction (0-360): %d\n", direction);
    printf("\n");

    // Get user input
    printf("Enter speed (0-100): ");
    scanf("%d", &speed);
    if (speed > 100)
    {
      printf("Invalid speed! Must be between 0 and 100.\n\n");
      continue;
    }

    printf("Enter direction (0-360): ");
    scanf("%d", &direction);
    if (direction > 360)
    {
      printf("Invalid direction! Must be between 0 and 360.\n\n");
      continue;
    }

    // Update battery level based on speed and direction
    int battery_drain = speed / 10;
    if (direction >= 180 && direction <= 270)
    {
      battery_drain += 5;
    }
    battery_level -= battery_drain;
    if (battery_level <= 0)
    {
      printf("*** Battery has died! ***");
      break;
    }

    // Simulate movement
    printf("Vehicle is moving with speed %d at direction %d...\n\n", speed, direction);
  }

  return 0;
}