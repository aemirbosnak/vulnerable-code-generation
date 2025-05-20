//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the character used to represent the text
#define TEXT_CHAR '*'

// Define the character used to represent the background
#define BG_CHAR ' '

// Declare the function to generate the ASCII art
void generate_ascii_art(char *text, int width, int height);

// Main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text: ");
  scanf("%s", text);

  // Get the width and height of the ASCII art
  int width;
  int height;
  printf("Enter the width of the ASCII art: ");
  scanf("%d", &width);
  printf("Enter the height of the ASCII art: ");
  scanf("%d", &height);

  // Generate the ASCII art
  generate_ascii_art(text, width, height);

  return 0;
}

// Function to generate the ASCII art
void generate_ascii_art(char *text, int width, int height) {
  // Create a 2D array to represent the ASCII art
  char art[MAX_HEIGHT][MAX_WIDTH];

  // Initialize the ASCII art with the background character
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      art[i][j] = BG_CHAR;
    }
  }

  // Calculate the starting position of the text
  int start_x = (width - strlen(text)) / 2;
  int start_y = (height - 1) / 2;

  // Draw the text on the ASCII art
  for (int i = 0; i < strlen(text); i++) {
    art[start_y][start_x + i] = TEXT_CHAR;
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }
}