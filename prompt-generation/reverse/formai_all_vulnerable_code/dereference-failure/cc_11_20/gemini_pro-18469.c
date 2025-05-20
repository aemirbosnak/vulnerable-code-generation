//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <text>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *text = argv[1];
  int width = strlen(text);
  int height = 1;

  // Create a 2D array to store the ASCII art
  char **art = (char **)malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    art[i] = (char *)malloc(width * sizeof(char));
  }

  // Fill the 2D array with spaces
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      art[i][j] = ' ';
    }
  }

  // Convert the text to ASCII art
  int x = 0;
  int y = 0;
  for (int i = 0; i < strlen(text); i++) {
    char c = text[i];
    switch (c) {
      case ' ':
        x++;
        break;
      case '\n':
        y++;
        x = 0;
        break;
      default:
        art[y][x] = c;
        x++;
        break;
    }
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the 2D array
  for (int i = 0; i < height; i++) {
    free(art[i]);
  }
  free(art);

  return EXIT_SUCCESS;
}