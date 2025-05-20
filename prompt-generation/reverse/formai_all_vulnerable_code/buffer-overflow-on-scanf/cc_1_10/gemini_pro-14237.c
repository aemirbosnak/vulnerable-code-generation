//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to create the ASCII art
char characters[] = " .:-=+*#%@" ;

// Function to convert a text string to ASCII art
void text_to_ascii(char *text, int width, int height) {
  // Check if the text is too long or too wide
  if (strlen(text) > width * height) {
    printf("Error: Text is too long or too wide.\n");
    return;
  }

  // Create a 2D array to store the ASCII art
  char art[height][width];

  // Initialize the ASCII art array with spaces
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
        art[i][j] = characters[(int) ((text[index] - '!') / 16.0 * (sizeof(characters) - 1))];
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

// Main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text to convert to ASCII art: ");
  scanf("%s", text);

  // Get the width and height of the ASCII art
  int width, height;
  printf("Enter the width of the ASCII art: ");
  scanf("%d", &width);
  printf("Enter the height of the ASCII art: ");
  scanf("%d", &height);

  // Convert the text to ASCII art
  text_to_ascii(text, width, height);

  return 0;
}