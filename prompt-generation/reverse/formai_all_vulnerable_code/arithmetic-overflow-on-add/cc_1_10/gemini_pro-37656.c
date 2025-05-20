//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random color
int randColor() {
  return rand() % 0xFFFFFF;
}

// Function to draw a rectangle
void drawRect(int x, int y, int width, int height, int color) {
  printf("\e[%d;%df", y, x);
  printf("\e[48;2;%d;%d;%dm", (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
  printf("  ");
  printf("\e[0m");
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Set the terminal to raw mode
  system("stty raw");

  // Hide the cursor
  printf("\e[?25l");

  // Set the initial position of the cursor
  printf("\e[0;0f");

  // Generate the Fibonacci sequence
  int fib[100];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 100; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  // Draw the Fibonacci sequence
  for (int i = 0; i < 100; i++) {
    drawRect(i, fib[i], 1, 1, randColor());
  }

  // Wait for the user to press a key
  getchar();

  // Restore the terminal to its original state
  printf("\e[?25h");
  system("stty cooked");

  return 0;
}