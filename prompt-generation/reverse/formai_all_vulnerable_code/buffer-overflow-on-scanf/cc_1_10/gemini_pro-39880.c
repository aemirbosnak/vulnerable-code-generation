//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII character set
char *ascii = " .,-~:;!@#$%^&*()_+={}/[]\\\"`-_~;:,.@";

// Convert a character to its ASCII art representation
char *char_to_ascii(char c) {
  int index = (int) c - 32;
  return &ascii[index];
}

// Convert a string to its ASCII art representation
char *string_to_ascii(char *str) {
  int len = strlen(str);
  char *ascii_art = malloc(len * 8 + 1);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < 8; j++) {
      ascii_art[i * 8 + j] = char_to_ascii(str[i])[j];
    }
  }
  ascii_art[len * 8] = '\0';
  return ascii_art;
}

// Print the ASCII art representation of a string
void print_ascii_art(char *ascii_art) {
  int len = strlen(ascii_art);
  for (int i = 0; i < len; i++) {
    if (i % 8 == 0) {
      printf("\n");
    }
    printf("%c", ascii_art[i]);
  }
  printf("\n");
}

// Get the user's input
char *get_input() {
  char *input = malloc(100);
  printf("Enter a string: ");
  scanf("%s", input);
  return input;
}

// Main function
int main() {
  char *input = get_input();
  char *ascii_art = string_to_ascii(input);
  print_ascii_art(ascii_art);
  free(input);
  free(ascii_art);
  return 0;
}