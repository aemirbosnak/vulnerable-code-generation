//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the character used to represent the ASCII art
#define ASCII_CHAR '*'

// Define the function to generate the ASCII art
void generate_ascii_art(char *text, int width, int height) {
  // Create a 2D array to store the ASCII art
  char ascii_art[MAX_HEIGHT][MAX_WIDTH];

  // Initialize the ASCII art array to spaces
  for (int i = 0; i < MAX_HEIGHT; i++) {
    for (int j = 0; j < MAX_WIDTH; j++) {
      ascii_art[i][j] = ' ';
    }
  }

  // Calculate the number of characters per line
  int chars_per_line = width / strlen(text);

  // Iterate over the lines of the ASCII art
  for (int i = 0; i < height; i++) {
    // Calculate the starting column for the line
    int start_col = (width - (chars_per_line * strlen(text))) / 2;

    // Iterate over the characters in the line
    for (int j = 0; j < chars_per_line * strlen(text); j++) {
      // Calculate the character index
      int char_index = j / chars_per_line;

      // Calculate the column index
      int col_index = start_col + (j % chars_per_line);

      // Set the character in the ASCII art array
      ascii_art[i][col_index] = text[char_index];
    }
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii_art[i][j]);
    }
    printf("\n");
  }
}

// Define the main function
int main() {
  // Get the text from the user
  char text[MAX_WIDTH];
  printf("Enter the text to convert to ASCII art: ");
  scanf("%s", text);

  // Get the width and height of the ASCII art
  int width, height;
  printf("Enter the width of the ASCII art: ");
  scanf("%d", &width);
  printf("Enter the height of the ASCII art: ");
  scanf("%d", &height);

  // Generate the ASCII art
  generate_ascii_art(text, width, height);

  return 0;
}