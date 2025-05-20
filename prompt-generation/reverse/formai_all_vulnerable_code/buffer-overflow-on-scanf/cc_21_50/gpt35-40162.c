//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>

int main() {
  int altitude = 0;
  int battery_life = 100;
  int is_flying = 0;
  char command;

  while(1) {
    printf("Enter command:\n");
    scanf(" %c", &command);

    switch(command) {
      case 't':
        if(!is_flying) {
          printf("Taking off...\n");
          is_flying = 1;
          altitude = 1;
        } else {
          printf("Drone is already flying!\n");
        }
        break;
      case 'l':
        if(is_flying) {
          printf("Landing...\n");
          is_flying = 0;
          altitude = 0;
        } else {
          printf("Drone is already landed!\n");
        }
        break;
      case 'u':
        if(is_flying && altitude < 10) {
          printf("Going up...\n");
          altitude++;
        } else if (altitude >= 10) {
          printf("Maximum altitude reached!\n");
        } else {
          printf("Cannot go up when drone is not flying!\n");
        }
        break;
      case 'd':
        if(is_flying && altitude > 0) {
          printf("Going down...\n");
          altitude--;
        } else if (altitude == 0) {
          printf("Drone is already on the ground!\n");
        } else {
          printf("Cannot go down when drone is not flying!\n");
        }
        break;
      case 'r':
        if(is_flying && battery_life > 0) {
          printf("Returning home...\n");
          altitude = 0;
          battery_life -= 5;
        } else if (battery_life == 0) {
          printf("Battery is depleted! Cannot return home.\n");
        } else {
          printf("Cannot return home when drone is not flying!\n");
        }
        break;
      case 'c':
        printf("Current altitude: %d\n", altitude);
        printf("Battery life: %d\n", battery_life);
        printf("Drone is%s flying.\n", is_flying ? "" : " not");
        break;
      case 'e':
        printf("Exiting program...\n");
        return 0;
      default:
        printf("Invalid command!\n");
        break;
    }
  }
  return 0;
}