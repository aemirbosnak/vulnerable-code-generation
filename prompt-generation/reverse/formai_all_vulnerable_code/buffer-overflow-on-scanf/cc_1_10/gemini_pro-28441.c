//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the maximum width of the ASCII art
#define MAX_WIDTH 80

// Define the characters used to create the ASCII art
char characters[] = " .:-=+*#%@";

// Function to generate ASCII art from a text string
void generate_ascii_art(char *text) {
  // Calculate the length of the text
  int length = strlen(text);

  // Create a 2D array to store the ASCII art
  char art[MAX_WIDTH][length];

  // Initialize the ASCII art array with spaces
  for (int i = 0; i < MAX_WIDTH; i++) {
    for (int j = 0; j < length; j++) {
      art[i][j] = ' ';
    }
  }

  // Iterate over each character in the text
  for (int i = 0; i < length; i++) {
    // Calculate the ASCII value of the character
    int ascii_value = (int)text[i];

    // Calculate the index of the character in the characters array
    int index = (ascii_value - 32) / 4;

    // Iterate over each row in the ASCII art array
    for (int j = 0; j < MAX_WIDTH; j++) {
      // Set the character in the ASCII art array to the corresponding character from the characters array
      art[j][i] = characters[index];
    }
  }

  // Print the ASCII art
  for (int i = 0; i < MAX_WIDTH; i++) {
    for (int j = 0; j < length; j++) {
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

  // Generate the ASCII art
  generate_ascii_art(text);

  return 0;
}