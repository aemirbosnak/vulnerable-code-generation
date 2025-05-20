//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

char *art_chars = " .:-=+*#%@";

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <text>\n", argv[0]);
    return 1;
  }

  char *text = argv[1];
  int width = strlen(text);
  int height = 1;

  // Calculate the height of the art
  for (int i = 0; i < width; i++) {
    if (text[i] == '\n') {
      height++;
    }
  }

  // Create a 2D array to store the art
  char **art = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    art[i] = malloc(sizeof(char) * width);
  }

  // Fill the art array with spaces
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      art[i][j] = ' ';
    }
  }

  // Convert the text to ASCII art
  int x = 0;
  int y = 0;
  for (int i = 0; i < width; i++) {
    if (text[i] == '\n') {
      x = 0;
      y++;
    } else {
      art[y][x] = art_chars[rand() % strlen(art_chars)];
      x++;
    }
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the art array
  for (int i = 0; i < height; i++) {
    free(art[i]);
  }
  free(art);

  return 0;
}