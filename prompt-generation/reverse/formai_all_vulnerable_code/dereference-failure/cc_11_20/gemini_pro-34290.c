//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
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

  // Allocate a 2D array of characters to store the ASCII art
  char **art = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    art[i] = malloc(sizeof(char) * width);
  }

  // Convert the text to ASCII art
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
        art[j][i] = '*';
      } else {
        art[j][i] = text[i - 1];
      }
    }
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }

  // Free the allocated memory
  for (int i = 0; i < height; i++) {
    free(art[i]);
  }
  free(art);

  return EXIT_SUCCESS;
}