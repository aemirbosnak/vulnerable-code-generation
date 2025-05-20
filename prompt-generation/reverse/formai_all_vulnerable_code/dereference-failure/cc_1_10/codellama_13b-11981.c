//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
/*
 * C Text to ASCII Art Generator
 *
 * Generates a unique ASCII art based on a given text input.
 *
 * Usage:
 *   $ ./text_to_ascii_art "Hello, World!"
 *
 * Output:
 *   /_/\
 *  ( o.o )
 *   > ^ <
 */

#include <stdio.h>
#include <string.h>

#define ASCII_ART_HEIGHT 3
#define ASCII_ART_WIDTH 10

void print_ascii_art(char *text) {
  char ascii_art[ASCII_ART_HEIGHT][ASCII_ART_WIDTH + 1] = {
    "/_/\\",
    "( o.o )",
    "> ^ <"
  };

  int i, j;
  for (i = 0; i < ASCII_ART_HEIGHT; i++) {
    for (j = 0; j < ASCII_ART_WIDTH; j++) {
      if (j < strlen(text)) {
        ascii_art[i][j] = text[j];
      } else {
        ascii_art[i][j] = ' ';
      }
    }
  }

  for (i = 0; i < ASCII_ART_HEIGHT; i++) {
    printf("%s\n", ascii_art[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return 1;
  }

  print_ascii_art(argv[1]);

  return 0;
}