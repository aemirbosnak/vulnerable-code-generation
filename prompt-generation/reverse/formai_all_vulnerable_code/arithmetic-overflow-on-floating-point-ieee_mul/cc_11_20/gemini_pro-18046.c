//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>
#include <math.h>

int main() {
  // Define the canvas and its dimensions
  int width = 800;
  int height = 600;
  int canvas[width][height];

  // Define the colors
  int black = 0;
  int white = 255;

  // Draw a circle
  int radius = 100;
  int center_x = width / 2;
  int center_y = height / 2;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      if (sqrt(pow(x - center_x, 2) + pow(y - center_y, 2)) <= radius) {
        canvas[x][y] = white;
      } else {
        canvas[x][y] = black;
      }
    }
  }

  // Draw a line
  int x1 = 100;
  int y1 = 100;
  int x2 = 500;
  int y2 = 500;
  for (int x = x1; x <= x2; x++) {
    for (int y = y1; y <= y2; y++) {
      canvas[x][y] = white;
    }
  }

  // Draw a triangle
  int x3 = 100;
  int y3 = 500;
  int x4 = 500;
  int y4 = 100;
  for (int x = x3; x <= x4; x++) {
    for (int y = y3; y <= y4; y++) {
      canvas[x][y] = white;
    }
  }

  // Draw a rectangle
  int x5 = 100;
  int y5 = 100;
  int x6 = 500;
  int y6 = 500;
  for (int x = x5; x <= x6; x++) {
    for (int y = y5; y <= y6; y++) {
      canvas[x][y] = white;
    }
  }

  // Draw an ellipse
  int rx = 100;
  int ry = 50;
  int cx = width / 2;
  int cy = height / 2;
  for (int x = cx - rx; x <= cx + rx; x++) {
    for (int y = cy - ry; y <= cy + ry; y++) {
      if (pow(x - cx, 2) / pow(rx, 2) + pow(y - cy, 2) / pow(ry, 2) <= 1) {
        canvas[x][y] = white;
      } else {
        canvas[x][y] = black;
      }
    }
  }

  // Draw a polygon
  int n = 5;
  int x7[n];
  int y7[n];
  for (int i = 0; i < n; i++) {
    x7[i] = 100 + 100 * i;
    y7[i] = 100 + 100 * i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        canvas[x7[i]][y7[i]] = white;
      } else {
        canvas[x7[i]][y7[j]] = black;
      }
    }
  }

  // Draw a bezier curve
  int x8[4] = {100, 200, 300, 400};
  int y8[4] = {100, 200, 300, 400};
  for (int t = 0; t <= 100; t++) {
    float tt = t / 100.0;
    int x = pow(1 - tt, 3) * x8[0] + 3 * tt * pow(1 - tt, 2) * x8[1] + 3 * tt * tt * (1 - tt) * x8[2] + pow(tt, 3) * x8[3];
    int y = pow(1 - tt, 3) * y8[0] + 3 * tt * pow(1 - tt, 2) * y8[1] + 3 * tt * tt * (1 - tt) * y8[2] + pow(tt, 3) * y8[3];
    canvas[x][y] = white;
  }

  // Write the output to a file
  FILE *file = fopen("output.ppm", "wb");
  fprintf(file, "P3\n%d %d\n255\n", width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      fprintf(file, "%d %d %d ", canvas[x][y], canvas[x][y], canvas[x][y]);
    }
    fprintf(file, "\n");
  }
  fclose(file);

  return 0;
}