//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Define the character to use for the ASCII art
#define CHAR '*'

// Define the function to generate the ASCII art
void generate_ascii_art(char *text, int width, int height) {
  // Check if the text is too long or too wide
  if (strlen(text) > width * height) {
    printf("Error: The text is too long or too wide.\n");
    return;
  }

  // Create a 2D array to store the ASCII art
  char art[height][width];

  // Initialize the 2D array with spaces
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      art[i][j] = ' ';
    }
  }

  // Convert the text to ASCII art
  int index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (index < strlen(text)) {
        art[i][j] = text[index];
        index++;
      }
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

// Get the user input
char *get_user_input(int *width, int *height) {
  char *text;

  // Get the text from the user
  printf("Enter the text you want to convert to ASCII art: ");
  text = malloc(100);
  scanf("%s", text);

  // Get the width and height from the user
  printf("Enter the width of the ASCII art (max %d): ", MAX_WIDTH);
  scanf("%d", width);
  printf("Enter the height of the ASCII art (max %d): ", MAX_HEIGHT);
  scanf("%d", height);

  return text;
}

// Main function
int main() {
  int width, height;
  char *text;

  // Get the user input
  text = get_user_input(&width, &height);

  // Generate the ASCII art
  generate_ascii_art(text, width, height);

  // Free the allocated memory
  free(text);

  return 0;
}