//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DRONE_SPEED 10
#define DRONE_ROTATION_SPEED 5

int main()
{
  // Initialize the drone
  int speed = DRONE_SPEED;
  int rotationSpeed = DRONE_ROTATION_SPEED;
  int altitude = 0;
  int pitch = 0;
  int roll = 0;
  int yaw = 0;

  // Get input from the user
  char input[100];
  while (1)
  {
    printf("\nEnter a command:\n");
    scanf("%s", input);

    // Parse the input
    if (strcmp(input, "takeoff") == 0)
    {
      // Take off the drone
      altitude = 10;
    }
    else if (strcmp(input, "land") == 0)
    {
      // Land the drone
      altitude = 0;
    }
    else if (strcmp(input, "up") == 0)
    {
      // Increase the altitude
      altitude += 10;
    }
    else if (strcmp(input, "down") == 0)
    {
      // Decrease the altitude
      altitude -= 10;
    }
    else if (strcmp(input, "forward") == 0)
    {
      // Move the drone forward
      pitch = 10;
    }
    else if (strcmp(input, "backward") == 0)
    {
      // Move the drone backward
      pitch = -10;
    }
    else if (strcmp(input, "left") == 0)
    {
      // Move the drone left
      roll = 10;
    }
    else if (strcmp(input, "right") == 0)
    {
      // Move the drone right
      roll = -10;
    }
    else if (strcmp(input, "clockwise") == 0)
    {
      // Rotate the drone clockwise
      yaw = 10;
    }
    else if (strcmp(input, "counterclockwise") == 0)
    {
      // Rotate the drone counterclockwise
      yaw = -10;
    }
    else if (strcmp(input, "quit") == 0)
    {
      // Quit the program
      break;
    }
    else
    {
      // Print an error message
      printf("Invalid command\n");
    }

    // Print the current state of the drone
    printf("\nAltitude: %d\n", altitude);
    printf("Pitch: %d\n", pitch);
    printf("Roll: %d\n", roll);
    printf("Yaw: %d\n", yaw);
  }

  return 0;
}