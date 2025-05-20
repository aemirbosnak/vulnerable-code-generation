//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *charToArt(char c) {
  // Array of ASCII art characters
  char *art[] = {
    "  _  _ ",
    " | || |",
    " | || |",
    " | || |",
    "  \\|/",
    "   |   ",
    " _|_|_ ",
    "   |   ",
    "   |   ",
    "   |   ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    " |   | ",
    "  ---  ",
    "  ---  ",
    " |   | ",
    " |   | ",
    " |___| ",
    "  ---  ",
    "  ---  ",
    " |---| ",
    " |   | ",
    " |   | ",
    "  ---  ",
    " |   | ",
    " |   | ",
    "   |   ",
    "   |   ",
    "   |   ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    " |   | ",
    "  ---  ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    " |   | ",
    "  ---  ",
    "  ---  ",
    " |---| ",
    " |   | ",
    " |___| ",
    "  ---  ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    " |___| ",
    "   |   ",
    "   |   ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    " |___| ",
    "   |   ",
    "   |   ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    "  ---  ",
    "  ---  ",
    " |   | ",
    " |   | ",
    " |___| ",
    " _|_|_ ",
    " |   | ",
    " |   | ",
    " |___| ",
    "   |   ",
    "   |   ",
    " _|_|_ "
  };

  // Return the ASCII art for the character
  return art[c - 'A'];
}

// Function to print a string in ASCII art
void printArt(char *str) {
  // Loop through the string
  for (int i = 0; i < strlen(str); i++) {
    // Convert the character to ASCII art
    char *art = charToArt(str[i]);

    // Print the ASCII art
    for (int j = 0; j < 7; j++) {
      printf("%s\n", art[j]);
    }

    // Print a newline
    printf("\n");
  }
}

// Main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Print the string in ASCII art
  printArt(str);

  return 0;
}