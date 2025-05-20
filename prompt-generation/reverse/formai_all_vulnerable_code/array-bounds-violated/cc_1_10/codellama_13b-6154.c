//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
// ASCII Art Text to Image Generator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ASCII Art Image
#define WIDTH 80
#define HEIGHT 25
char image[HEIGHT][WIDTH];

// Text to convert to ASCII Art
char text[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";

// ASCII Art Character Map
char map[] = " .:-=+*#%@";

// Main function
int main() {
  // Initialize image with blank characters
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      image[i][j] = ' ';
    }
  }

  // Convert text to ASCII Art
  int x = 0;
  int y = 0;
  for (int i = 0; i < strlen(text); i++) {
    // Get ASCII Art character
    int index = text[i] - 32;
    char c = map[index];

    // Print character to image
    image[y][x] = c;

    // Move cursor to next position
    x++;
    if (x >= WIDTH) {
      x = 0;
      y++;
    }
  }

  // Print image
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", image[i][j]);
    }
    printf("\n");
  }

  return 0;
}