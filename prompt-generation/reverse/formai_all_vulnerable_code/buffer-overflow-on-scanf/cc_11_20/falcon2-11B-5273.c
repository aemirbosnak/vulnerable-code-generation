//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>

int main() {
  // Initial drone position
  int x = 0;
  int y = 0;
  int z = 0;
  int vx = 0;
  int vy = 0;
  int vz = 0;

  // Variables for user input
  char command;
  int speed;

  while (1) {
    // Read user command
    printf("Enter command (up/down/left/right/forward/backward/quit): ");
    scanf(" %c", &command);

    // Process command
    switch (command) {
      case 'u': // Up
        vx = -1;
        break;
      case 'd': // Down
        vx = 1;
        break;
      case 'l': // Left
        vy = -1;
        break;
      case 'r': // Right
        vy = 1;
        break;
      case 'f': // Forward
        vz = 1;
        break;
      case 'b': // Backward
        vz = -1;
        break;
      case 'q': // Quit
        exit(0);
        break;
      default:
        printf("Invalid command.\n");
        break;
    }

    // Update drone position
    x += vx;
    y += vy;
    z += vz;

    // Limit speed and altitude
    if (vz > 2) {
      vz = 2;
    }
    if (vx > 2) {
      vx = 2;
    }
    if (vy > 2) {
      vy = 2;
    }

    // Print drone position
    printf("X: %d, Y: %d, Z: %d, VX: %d, VY: %d, VZ: %d\n", x, y, z, vx, vy, vz);
  }

  return 0;
}