//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPixel(char pix) {
  switch(pix) {
    case 0:
      printf(" ");
      break;
    case 1:
      printf("*");
      break;
    case 2:
      printf(".");
      break;
    case 3:
      printf("o");
      break;
    case 4:
      printf("+");
      break;
    case 5:
      printf("#");
      break;
    case 6:
      printf("x");
      break;
    case 7:
      printf("O");
      break;
    case 8:
      printf("-");
      break;
    case 9:
      printf("|");
      break;
    case 10:
      printf("s");
      break;
  }
}

int main() {
  srand(time(NULL));  // Set seed for random number generator

  // User input for width and height
  int width, height;
  printf("Enter width and height of pixel art (max 30x30):\n");
  scanf("%d %d", &width, &height);

  // Limit maximum size to 30x30
  if(width > 30) width = 30;
  if(height > 30) height = 30;

  int pixelArt[height][width];  // 2D array to hold pixel art data

  // Generate random pixel art
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      pixelArt[i][j] = rand() % 11;  // Random number between 0-10
    }
  }

  // Print pixel art
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      printPixel(pixelArt[i][j]);
    }
    printf("\n");
  }

  return 0;
}