//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width of the ASCII art
#define MAX_WIDTH 80

// Define the ASCII character set
char *charset = " .,-~:;=*#%@";

// Function to convert a text string to ASCII art
char *text_to_ascii(char *text) {
  // Allocate memory for the ASCII art
  char *ascii = malloc(strlen(text) * MAX_WIDTH);

  // Convert each character in the text to ASCII art
  for (int i = 0; i < strlen(text); i++) {
    // Get the ASCII code for the character
    int code = text[i];

    // Convert the ASCII code to a character in the charset
    char c = charset[code % strlen(charset)];

    // Append the character to the ASCII art
    strcat(ascii, &c);
  }

  // Return the ASCII art
  return ascii;
}

// Function to print the ASCII art
void print_ascii(char *ascii) {
  // Print the ASCII art to the console
  printf("%s\n", ascii);
}

// Main function
int main() {
  // Get the text to convert to ASCII art from the user
  char *text = malloc(100);
  printf("Enter the text to convert to ASCII art: ");
  scanf("%s", text);

  // Convert the text to ASCII art
  char *ascii = text_to_ascii(text);

  // Print the ASCII art
  print_ascii(ascii);

  // Free the memory allocated for the ASCII art
  free(ascii);

  return 0;
}