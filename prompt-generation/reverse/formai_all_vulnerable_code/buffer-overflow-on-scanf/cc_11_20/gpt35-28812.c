//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  // Seed random number generator
  srand(time(NULL));

  // Define pixel character
  const char PIXEL = '*';

  // Declare variables for picture size
  int width, height;

  // Prompt user for picture size
  printf("Enter picture width (1-50): ");
  scanf("%d", &width);
  printf("Enter picture height (1-50): ");
  scanf("%d", &height);

  // Check input validity
  if (width < 1 || width > 50 || height < 1 || height > 50) {
    printf("Invalid input.");
    return 1;
  }

  // Create pixel art
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      // Generate random number between 0 and 3
      int randNum = rand() % 4;

      // Determine pixel color based on random number
      switch (randNum) {
        case 0:
          printf("\033[0;31m"); // Red
          break;
        case 1:
          printf("\033[0;32m"); // Green
          break;
        case 2:
          printf("\033[0;33m"); // Yellow
          break;
        case 3:
          printf("\033[0;34m"); // Blue
          break;
      }

      // Print pixel character
      printf("%c ", PIXEL);
    }

    // Print newline character to start new row
    printf("\n");
  }

  return 0;
}