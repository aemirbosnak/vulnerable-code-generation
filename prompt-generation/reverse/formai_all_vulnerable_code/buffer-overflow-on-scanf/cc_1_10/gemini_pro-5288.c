//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the ASCII character set
char ascii_set[] = " .,-~:;=!%&#*O@WB$";

// Convert a character to ASCII art
char *to_ascii_art(char c) {
  // Find the index of the character in the ASCII character set
  int index = (int)c - 32;
  if (index < 0 || index >= strlen(ascii_set)) {
    return NULL;
  }

  // Return the corresponding ASCII art character
  return &ascii_set[index];
}

// Convert a string to ASCII art
char *to_ascii_art_string(char *str) {
  // Allocate memory for the ASCII art string
  char *ascii_art_str = malloc(strlen(str) * 4 + 1);

  // Convert each character in the string to ASCII art
  for (int i = 0; i < strlen(str); i++) {
    char *ascii_art_char = to_ascii_art(str[i]);
    if (ascii_art_char == NULL) {
      free(ascii_art_str);
      return NULL;
    }

    // Append the ASCII art character to the ASCII art string
    strcat(ascii_art_str, ascii_art_char);
    strcat(ascii_art_str, " ");
  }

  // Return the ASCII art string
  return ascii_art_str;
}

// Print the ASCII art string with a neon effect
void print_neon_ascii_art(char *ascii_art_str) {
  // Print the ASCII art string in green
  printf("\033[32m%s\033[0m", ascii_art_str);

  // Print a neon effect around the ASCII art string
  printf("\033[43m");
  for (int i = 0; i < strlen(ascii_art_str); i++) {
    printf(" ");
  }
  printf("\033[0m\n");
}

// Main function
int main() {
  // Get the input string from the user
  char input_str[100];
  printf("Enter a string to convert to ASCII art: ");
  scanf("%s", input_str);

  // Convert the input string to ASCII art
  char *ascii_art_str = to_ascii_art_string(input_str);
  if (ascii_art_str == NULL) {
    printf("Error: Invalid input string.\n");
    return 1;
  }

  // Print the ASCII art string with a neon effect
  print_neon_ascii_art(ascii_art_str);

  // Free the memory allocated for the ASCII art string
  free(ascii_art_str);

  return 0;
}