//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
// Text to ASCII Art Generator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII art characters
char* ascii_art[] = {
  "@   @",
  "@ @@",
  "@@@@",
  "@ @@",
  "@   @"
};

// Function to convert text to ASCII art
void text_to_ascii_art(char* text) {
  int i, j;
  char* line;
  char* ascii_text;

  // Allocate memory for the ASCII text
  ascii_text = (char*)malloc(strlen(text) * 5 + 1);

  // Iterate over each character in the text
  for (i = 0; i < strlen(text); i++) {
    // Get the character at position i
    char c = text[i];

    // Convert the character to uppercase
    c = toupper(c);

    // Get the corresponding ASCII art character
    line = ascii_art[c - 'A'];

    // Add the ASCII art character to the ASCII text
    strcat(ascii_text, line);
  }

  // Print the ASCII text
  printf("%s\n", ascii_text);

  // Free the memory allocated for the ASCII text
  free(ascii_text);
}

// Driver code
int main() {
  // Text to convert
  char* text = "Hello World!";

  // Convert the text to ASCII art
  text_to_ascii_art(text);

  return 0;
}