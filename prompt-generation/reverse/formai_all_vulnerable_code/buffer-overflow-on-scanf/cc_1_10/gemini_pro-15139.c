//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the character set
char charset[] = " .,:;i1tfLCG08@";

// Define the maximum width and height of the art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Convert a text string to ASCII art
void text_to_ascii(char *text, int width, int height) {
  // Create a 2D array to store the ASCII art
  char art[MAX_HEIGHT][MAX_WIDTH];

  // Clear the art array
  for (int i = 0; i < MAX_HEIGHT; i++) {
    for (int j = 0; j < MAX_WIDTH; j++) {
      art[i][j] = ' ';
    }
  }

  // Convert the text to ASCII art
  int x = 0;
  int y = 0;
  for (int i = 0; i < strlen(text); i++) {
    // Get the ASCII value of the character
    int value = text[i];

    // Convert the ASCII value to a character in the character set
    char character = charset[value % strlen(charset)];

    // Place the character in the art array
    art[y][x] = character;

    // Increment the x and y coordinates
    x++;
    if (x >= width) {
      x = 0;
      y++;
    }
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Get the text to convert to ASCII art
  char text[100];
  printf("Enter the text to convert to ASCII art: ");
  scanf("%s", text);

  // Convert the text to ASCII art
  text_to_ascii(text, 100, 100);

  return 0;
}