//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to ASCII art
char *text_to_ascii(char *text) {
  // Allocate memory for the ASCII art
  char *ascii_art = malloc(strlen(text) * 10);

  // Initialize the ASCII art string
  ascii_art[0] = '\0';

  // Loop through each character in the text
  for (int i = 0; i < strlen(text); i++) {
    // Get the ASCII code for the character
    int ascii_code = text[i];

    // Convert the ASCII code to ASCII art
    char *art = malloc(10);
    sprintf(art, "%c", ascii_code);

    // Append the ASCII art to the ASCII art string
    strcat(ascii_art, art);

    // Free the memory allocated for the ASCII art
    free(art);
  }

  // Return the ASCII art
  return ascii_art;
}

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
  // Print the ASCII art to the console
  printf("%s\n", ascii_art);

  // Free the memory allocated for the ASCII art
  free(ascii_art);
}

// Main function
int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text you want to convert to ASCII art: ");
  scanf("%s", text);

  // Convert the text to ASCII art
  char *ascii_art = text_to_ascii(text);

  // Print the ASCII art
  print_ascii_art(ascii_art);

  return 0;
}