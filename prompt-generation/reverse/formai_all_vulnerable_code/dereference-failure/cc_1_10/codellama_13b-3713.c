//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
/*
 * text_to_ascii_art.c
 *
 * This program generates ASCII art from text input.
 *
 * Usage:
 *  - Provide text input on the command line or through standard input.
 *  - The output will be ASCII art generated from the input text.
 *
 * Example:
 *  $ ./text_to_ascii_art "Hello, world!"
 *  /_/\
 * ( o.o )
 * > ^ <
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100

void generate_ascii_art(char *text);

int main(int argc, char *argv[]) {
  char text[MAX_CHARS];

  if (argc == 2) {
    strcpy(text, argv[1]);
  } else {
    printf("Enter text: ");
    fgets(text, MAX_CHARS, stdin);
    text[strcspn(text, "\n")] = 0;
  }

  generate_ascii_art(text);

  return 0;
}

void generate_ascii_art(char *text) {
  int i;
  char ch;

  for (i = 0; i < strlen(text); i++) {
    ch = text[i];
    if (ch == 'a') {
      printf(" /_/\\\n");
    } else if (ch == 'e') {
      printf("( o.o )\n");
    } else if (ch == 'i') {
      printf("> ^ <\n");
    } else {
      printf(" %c\n", ch);
    }
  }
}