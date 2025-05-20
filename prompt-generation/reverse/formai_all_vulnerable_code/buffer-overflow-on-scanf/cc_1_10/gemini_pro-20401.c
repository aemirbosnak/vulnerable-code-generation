//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Sherlock's vehicle simulator
int main() {
  // Declare variables
  double x, y, theta, v, w;
  char command;

  // Initialize variables
  x = 0.0;
  y = 0.0;
  theta = 0.0;
  v = 0.0;
  w = 0.0;

  // Main loop
  while (1) {
    // Get command
    printf("Enter command (f/b/l/r/q): ");
    scanf(" %c", &command);

    // Execute command
    switch (command) {
      case 'f':
        x += v * cos(theta) * 0.1;
        y += v * sin(theta) * 0.1;
        break;
      case 'b':
        x -= v * cos(theta) * 0.1;
        y -= v * sin(theta) * 0.1;
        break;
      case 'l':
        theta -= w * 0.1;
        break;
      case 'r':
        theta += w * 0.1;
        break;
      case 'q':
        return 0;
    }

    // Print status
    printf("x = %f, y = %f, theta = %f, v = %f, w = %f\n", x, y, theta, v, w);
  }

  return 0;
}