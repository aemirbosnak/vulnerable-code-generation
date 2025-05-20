//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>

// Define the maximum speed of the drone
#define MAX_SPEED 100

int main() {
  int speed = 0;
  int altitude = 0;
  char input;

  printf("Welcome to your drone remote control.\n");

  while(1) {
    printf("Current Speed: %d\n", speed);
    printf("Current Altitude: %d\n", altitude);

    printf("Enter command: ");
    scanf(" %c", &input);

    switch(input) {
      case 'q':
        // Quit the program
        printf("Exiting program.\n");
        return 0;
      case 't':
        // Takeoff the drone
        if(altitude == 0) {
          printf("Drone is taking off.\n");
          altitude += 10;
        }
        else {
          printf("Drone is already in the air.\n");
        }
        break;
      case 'l':
        // Land the drone
        if(altitude > 0) {
          printf("Drone is landing.\n");
          altitude = 0;
        }
        else {
          printf("Drone is already on the ground.\n");
        }
        break;
      case 'u':
        // Increase altitude
        if(altitude > 0) {
          printf("Increasing altitude.\n");
          altitude += 10;
        }
        else {
          printf("Drone needs to takeoff first.\n");
        }
        break;
      case 'd':
        // Decrease altitude
        if(altitude > 0) {
          printf("Decreasing altitude.\n");
          altitude -= 10;
          if(altitude < 0) {
            altitude = 0;
          }
        }
        else {
          printf("Drone is already on the ground.\n");
        }
        break;
      case 'f':
        // Increase speed
        if(speed < MAX_SPEED) {
          printf("Increasing speed.\n");
          speed += 10;
          if(speed > MAX_SPEED) {
            speed = MAX_SPEED;
          }
        }
        else {
          printf("Maximum speed already reached.\n");
        }
        break;
      case 's':
        // Decrease speed
        if(speed > 0) {
          printf("Decreasing speed.\n");
          speed -= 10;
          if(speed < 0) {
            speed = 0;
          }
        }
        else {
          printf("Drone is already stopped.\n");
        }
        break;
      default:
        printf("Invalid command.\n");
        break;
    }
  }

  return 0;
}