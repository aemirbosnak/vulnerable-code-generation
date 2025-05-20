//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_range(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to generate a random color in RGB format
int random_color() {
  return random_range(0, 255) << 16 | random_range(0, 255) << 8 | random_range(0, 255);
}

// Function to draw a pixel on the screen
void draw_pixel(int x, int y, int color) {
  // Set the pixel color
  *((int *)0xA0000000 + x + y * 240) = color;
}

// Function to draw a line on the screen
void draw_line(int x0, int y0, int x1, int y1, int color) {
  // Calculate the slope of the line
  float slope = (float)(y1 - y0) / (x1 - x0);

  // Iterate over the pixels along the line
  for (int x = x0; x <= x1; x++) {
    // Calculate the corresponding y-coordinate
    int y = y0 + (x - x0) * slope;

    // Draw the pixel
    draw_pixel(x, y, color);
  }
}

// Function to draw the Fibonacci sequence
void draw_fibonacci(int n) {
  // Initialize the first two Fibonacci numbers
  int f0 = 0;
  int f1 = 1;

  // Iterate over the remaining Fibonacci numbers
  for (int i = 2; i <= n; i++) {
    // Calculate the next Fibonacci number
    int f2 = f0 + f1;

    // Update the previous Fibonacci numbers
    f0 = f1;
    f1 = f2;

    // Draw a line representing the Fibonacci number
    draw_line(i - 2, f0, i - 1, f1, random_color());
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Draw the Fibonacci sequence
  draw_fibonacci(100);

  // Keep the program running
  while (1) {};

  return 0;
}