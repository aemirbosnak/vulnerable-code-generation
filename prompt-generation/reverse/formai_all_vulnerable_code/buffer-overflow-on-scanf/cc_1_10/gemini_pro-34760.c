//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the ASCII character set
char *ascii_chars = " .,:;i1tfLCG08@";

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Define the function to convert a text string to ASCII art
char *text_to_ascii(char *text) {
  // Allocate memory for the ASCII art
  char *ascii_art = malloc(MAX_WIDTH * MAX_HEIGHT);

  // Initialize the ASCII art to empty
  for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
    ascii_art[i] = ' ';
  }

  // Convert the text to ASCII art
  int x = 0;
  int y = 0;
  for (int i = 0; text[i] != '\0'; i++) {
    // Get the ASCII value of the character
    int ascii_value = (int)text[i];

    // Convert the ASCII value to an index in the ASCII character set
    int index = ascii_value - 32;

    // Draw the character at the current position
    ascii_art[x + y * MAX_WIDTH] = ascii_chars[index];

    // Increment the x and y coordinates
    x++;
    if (x >= MAX_WIDTH) {
      x = 0;
      y++;
    }
  }

  // Return the ASCII art
  return ascii_art;
}

// Define the main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text you want to convert to ASCII art: ");
  scanf("%s", text);

  // Convert the text to ASCII art
  char *ascii_art = text_to_ascii(text);

  // Print the ASCII art to the console
  printf("\n%s", ascii_art);

  // Free the memory allocated for the ASCII art
  free(ascii_art);

  return 0;
}