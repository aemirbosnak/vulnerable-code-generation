//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
// Linus Torvalds C Text to ASCII Art Generator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CHARS 256
#define MAX_LINES 100

void print_ascii_art(char* text, int num_lines) {
  int i, j, k, x, y, ascii_val, ascii_char;
  char ascii_chars[MAX_CHARS];
  char ascii_line[MAX_LINES][MAX_CHARS];

  // initialize ascii characters
  for (i = 0; i < MAX_CHARS; i++) {
    ascii_chars[i] = ' ';
  }

  // fill ascii characters with text
  for (i = 0; i < strlen(text); i++) {
    ascii_val = (int) text[i];
    ascii_char = (char) (ascii_val + 65);
    ascii_chars[i] = ascii_char;
  }

  // generate ascii art
  for (i = 0; i < num_lines; i++) {
    for (j = 0; j < strlen(text); j++) {
      ascii_val = (int) ascii_chars[j];
      ascii_char = (char) (ascii_val + i);
      ascii_line[i][j] = ascii_char;
    }
  }

  // print ascii art
  for (i = 0; i < num_lines; i++) {
    for (j = 0; j < strlen(text); j++) {
      printf("%c", ascii_line[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char text[MAX_CHARS];
  int num_lines;

  // get input
  printf("Enter text: ");
  fgets(text, MAX_CHARS, stdin);
  printf("Enter number of lines: ");
  scanf("%d", &num_lines);

  // print ascii art
  print_ascii_art(text, num_lines);

  return 0;
}