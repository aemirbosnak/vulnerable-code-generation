//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>

// This program generates a fractal pattern that resembles a fern.
// We use the chaos game algorithm to plot points in the pattern.
// The number of points to plot is specified by the user.

int main() {
  // Create variables for the 4 control points of the fern
  float x1 = 0.0, y1 = 0.0;
  float x2 = 0.2, y2 = 0.16;
  float x3 = -0.15, y3 = 0.28;
  float x4 = 0.85, y4 = 0.04;

  // Create variables for position of the current point
  float x = 0.0, y = 0.0;

  // Create variables for randomly selecting a control point
  int r;
  float tx, ty;

  // Create a variable for the number of points to plot
  int n;

  // Get the number of points from the user
  printf("Enter the number of points to plot: ");
  scanf("%d", &n);

  // Seed the random number generator
  srand(23);

  // Plot each point using the chaos game algorithm
  for (int i = 0; i < n; i++) {
    r = rand() % 100;

    if (r <= 1) { // Control point 1
      tx = x1;
      ty = y1;
    } else if (r <= 8) { // Control point 2
      tx = x2;
      ty = y2;
    } else if (r <= 15) { // Control point 3
      tx = x3;
      ty = y3;
    } else { // Control point 4
      tx = x4;
      ty = y4;
    }

    // Calculate the new position of the point
    x = (x + tx) / 2;
    y = (y + ty) / 2;

    // Print out the coordinates of the point
    printf("%f, %f\n", x, y);
  }

  return 0;
}