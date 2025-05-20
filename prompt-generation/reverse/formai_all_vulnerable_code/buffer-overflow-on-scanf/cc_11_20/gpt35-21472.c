//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>

#define MAX_COMMAND_LENGTH 10

int main() {
  char command[MAX_COMMAND_LENGTH];

  printf("Welcome to the C Drone Remote Control Program!\n\n");

  while (1) {
    printf("Please enter a command (takeoff, land, up, down, left, right, forward, back, exit): ");
    scanf("%s", command);

    if (strcmp(command, "takeoff") == 0) {
      printf("Command: Takeoff!\n");
    } else if (strcmp(command, "land") == 0) {
      printf("Command: Land!\n");
    } else if (strcmp(command, "up") == 0) {
      int distance;
      printf("Please enter distance (1-100): ");
      scanf("%d", &distance);
      printf("Command: Move Up %d meters!\n", distance);
    } else if (strcmp(command, "down") == 0) {
      int distance;
      printf("Please enter distance (1-100): ");
      scanf("%d", &distance);
      printf("Command: Move Down %d meters!\n", distance);
    } else if (strcmp(command, "left") == 0) {
      int distance;
      printf("Please enter distance (1-100): ");
      scanf("%d", &distance);
      printf("Command: Move Left %d meters!\n", distance);
    } else if (strcmp(command, "right") == 0) {
      int distance;
      printf("Please enter distance (1-100): ");
      scanf("%d", &distance);
      printf("Command: Move Right %d meters!\n", distance);
    } else if (strcmp(command, "forward") == 0) {
      int distance;
      printf("Please enter distance (1-100): ");
      scanf("%d", &distance);
      printf("Command: Move Forward %d meters!\n", distance);
    } else if (strcmp(command, "back") == 0) {
      int distance;
      printf("Please enter distance (1-100): ");
      scanf("%d", &distance);
      printf("Command: Move Back %d meters!\n", distance);
    } else if (strcmp(command, "exit") == 0) {
      printf("Exiting the program!\n");
      break;
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}