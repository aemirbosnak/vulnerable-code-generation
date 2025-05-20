//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include <stdio.h>

int main() {
  int battery_level = 100;
  int is_flying = 0;
  int altitude = 0;
  int pitch = 0;
  int roll = 0;

  while (1) {
    printf("Enter command (takeoff|land|up|down|left|right|forward|back|stop): ");
    char command[10];
    scanf("%s", command);

    if (strcmp(command, "takeoff") == 0 && !is_flying) {
      printf("Taking off...\n");
      is_flying = 1;
      battery_level -= 5;
    } else if (strcmp(command, "land") == 0 && is_flying) {
      printf("Landing...\n");
      is_flying = 0;
      altitude = 0;
    } else if (strcmp(command, "up") == 0 && is_flying) {
      printf("Going up...\n");
      altitude += 10;
      battery_level -= 1;
    } else if (strcmp(command, "down") == 0 && is_flying) {
      printf("Going down...\n");
      altitude -= 10;
      battery_level -= 1;
    } else if (strcmp(command, "left") == 0 && is_flying) {
      printf("Going left...\n");
      roll -= 10;
      battery_level -= 1;
    } else if (strcmp(command, "right") == 0 && is_flying) {
      printf("Going right...\n");
      roll += 10;
      battery_level -= 1;
    } else if (strcmp(command, "forward") == 0 && is_flying) {
      printf("Going forward...\n");
      pitch += 10;
      battery_level -= 1;
    } else if (strcmp(command, "back") == 0 && is_flying) {
      printf("Going back...\n");
      pitch -= 10;
      battery_level -= 1;
    } else if (strcmp(command, "stop") == 0 && is_flying) {
      printf("Stopping...\n");
      pitch = 0;
      roll = 0;
      battery_level -= 1;
    } else {
      printf("Invalid command or drone is not flying!\n");
      continue;
    }

    if (battery_level < 10 && is_flying) {
      printf("Low battery! Returning to home...\n");
      is_flying = 0;
      altitude = 0;
      pitch = 0;
      roll = 0;
      battery_level = 100;
    }

    printf("Battery level: %d %%\n", battery_level);
    printf("Altitude: %d m\n", altitude);
    printf("Pitch: %d degrees\n", pitch);
    printf("Roll: %d degrees\n", roll);
  }

  return 0;
}