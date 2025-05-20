//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
  static char art[MAX_WIDTH * MAX_HEIGHT];

  // Initialize the art array to spaces
  memset(art, ' ', MAX_WIDTH * MAX_HEIGHT);

  // Set the font size
  int font_size = 10;

  // Calculate the starting position of the character
  int start_x = (MAX_WIDTH - font_size) / 2;
  int start_y = (MAX_HEIGHT - font_size) / 2;

  // Draw the character
  for (int i = 0; i < font_size; i++) {
    for (int j = 0; j < font_size; j++) {
      // Get the pixel value for the character
      int pixel = (c >> (font_size - i - 1) & 1) << (font_size - j - 1);

      // Set the pixel in the art array
      art[start_x + i + (start_y + j) * MAX_WIDTH] = pixel ? '#' : ' ';
    }
  }

  // Return the art array
  return art;
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
  // Allocate memory for the art array
  char *art = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));

  // Convert each character in the string to ASCII art
  for (int i = 0; i < strlen(str); i++) {
    char *char_art = char_to_ascii(str[i]);

    // Append the character art to the art array
    strcat(art, char_art);
  }

  // Return the art array
  return art;
}

// Function to print the ASCII art
void print_ascii(char *art) {
  // Print the art array to the console
  for (int i = 0; i < MAX_HEIGHT; i++) {
    printf("%s\n", art + i * MAX_WIDTH);
  }
}

// Main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Convert the string to ASCII art
  char *art = string_to_ascii(str);

  // Print the ASCII art
  print_ascii(art);

  // Free the memory allocated for the art array
  free(art);

  return 0;
}