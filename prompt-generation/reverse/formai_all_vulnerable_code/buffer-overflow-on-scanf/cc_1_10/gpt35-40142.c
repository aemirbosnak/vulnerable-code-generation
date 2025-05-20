//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  int drone_power = 0;
  int drone_direction = 0;
  int drone_altitude = 0;
  int command = 0;

  printf("Welcome to RC Drone Remote Control!\n");

  while (command != 5) {
    printf("\nWhat would you like to do?\n");
    printf("1. Increase drone power\n");
    printf("2. Decrease drone power\n");
    printf("3. Change drone direction\n");
    printf("4. Change drone altitude\n");
    printf("5. Quit\n");

    scanf("%d", &command);

    switch (command) {
      case 1:
        if (drone_power == 100) {
          printf("Drone power is already at maximum!\n");
        } else {
          drone_power += 10;
          printf("Drone power increased to %d\n", drone_power);
        }
        break;
      case 2:
        if (drone_power == 0) {
          printf("Drone power is already at minimum!\n");
        } else {
          drone_power -= 10;
          printf("Drone power decreased to %d\n", drone_power);
        }
        break;
      case 3:
        printf("Enter a new direction (in degrees):\n");
        scanf("%d", &drone_direction);
        printf("Drone direction set to %d degrees\n", drone_direction);
        break;
      case 4:
        printf("Enter a new altitude (in meters):\n");
        scanf("%d", &drone_altitude);
        printf("Drone altitude set to %d meters\n", drone_altitude);
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid command. Please try again.\n");
        break;
    }
  }

  return 0;
}