//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed for random number generation

  int battery = 100; // initial battery level is 100%
  int distance = 0; // initial distance is 0 meters
  int speed = 0; // initial speed is 0 meters/second

  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  printf("Battery: %d%%\tDistance: %dm\tSpeed: %dm/s\n", battery, distance, speed);

  while (battery > 0 && distance < 500) { // simulate until battery runs out or distance reaches 500 meters
    int choice;
    printf("What would you like to do?\n");
    printf("1. Increase speed\n");
    printf("2. Decrease speed\n");
    printf("3. Drive forward\n");
    printf("4. Check battery level\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        speed += rand() % 5 + 1; // increase speed by a random amount between 1 and 5 meters/second
        printf("Speed increased to %dm/s\n", speed);
        break;
      case 2:
        if (speed > 0) { // speed cannot be negative
          speed -= rand() % 5 + 1; // decrease speed by a random amount between 1 and 5 meters/second
          printf("Speed decreased to %dm/s\n", speed);
        } else {
          printf("Cannot decrease speed further\n");
        }
        break;
      case 3:
        if (speed == 0) { // vehicle must be moving to drive forward
          printf("Vehicle is not moving\n");
        } else {
          int remaining_battery = battery - (rand() % 5 + 1); // driving forward consumes some battery
          if (remaining_battery < 0) { // battery cannot be negative
            printf("Battery drained, cannot drive forward\n");
          } else {
            battery = remaining_battery;
            int distance_travelled = speed * (rand() % 10 + 1); // driving forward covers a random distance between 1 and 10 meters
            distance += distance_travelled;
            printf("Distance travelled: %dm\n", distance_travelled);
            printf("Battery: %d%%\tDistance: %dm\tSpeed: %dm/s\n", battery, distance, speed);
          }
        }
        break;
      case 4:
        printf("Battery: %d%%\n", battery);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  if (battery <= 0) { // battery ran out
    printf("Battery drained, simulation ended\n");
  } else { // distance reached 500 meters
    printf("Distance of 500m reached, simulation ended\n");
  }

  return 0;
}