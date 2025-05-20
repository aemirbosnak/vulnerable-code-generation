//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
// This program generates unique pixel art using C.
// It will prompt the user for a color and the dimensions of the canvas,
// and randomly generate a pixelated image with various shapes and hues.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int width, height, r, g, b;

  // Prompt user for canvas dimensions and color
  printf("Enter canvas width: ");
  scanf("%d", &width);
  printf("Enter canvas height: ");
  scanf("%d", &height);
  printf("Enter pixel color (R G B): ");
  scanf("%d %d %d", &r, &g, &b);

  // Initialize RNG seed
  srand(time(NULL));

  // Generate pixel art
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Randomly determine whether to draw a pixel at this location
      if (rand() % 2 == 0) {
        // Randomly determine shape and size of the pixel
        int shape = rand() % 3; // 0 = square, 1 = circle, 2 = triangle
        int size = rand() % 5 + 1; // 1-5 pixels in size

        // Draw the pixel
        switch (shape) {
          case 0: // Square pixel
            for (int i = 0; i < size; i++) {
              for (int j = 0; j < size; j++) {
                printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b); // Set background color
              }
              printf("\n");
            }
            break;

          case 1: // Circle pixel
            for (int i = -size; i <= size; i++) {
              for (int j = -size; j <= size; j++) {
                if (i * i + j * j <= size * size) {
                  printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b); // Set background color
                } else {
                  printf("  ");
                }
              }
              printf("\n");
            }
            break;

          case 2: // Triangle pixel
            for (int i = 0; i < size; i++) {
              for (int j = 0; j <= i; j++) {
                printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b); // Set background color
              }
              printf("\n");
            }
            break;

          default:
            break;
        }
      } else {
        printf("  "); // Print a blank space
      }
    }
    printf("\n"); // Move to the next row of pixels
  }

  return 0;
}