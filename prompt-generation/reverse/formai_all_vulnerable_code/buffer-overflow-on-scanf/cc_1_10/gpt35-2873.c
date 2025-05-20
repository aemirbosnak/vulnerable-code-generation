//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to print ASCII art
void printArt(char c) {
  // Convert input character to uppercase
  char upperChar = toupper(c);
  // Declare array to hold ASCII art
  char art[5][17];
  // Fill array with ASCII values based on character
  switch(upperChar) {
    case 'A':
      // ASCII art for letter A
      strcpy(art[0], "    /\\");
      strcpy(art[1], "   /  \\");
      strcpy(art[2], "  /____\\");
      strcpy(art[3], " /      \\");
      strcpy(art[4], "/        \\");
      break;
    case 'B':
      // ASCII art for letter B
      strcpy(art[0], " _______");
      strcpy(art[1], "|       \\");
      strcpy(art[2], "|_______/");
      strcpy(art[3], "|       \\");
      strcpy(art[4], "|________\\");
      break;
    case 'C':
      // ASCII art for letter C
      strcpy(art[0], "  _______");
      strcpy(art[1], " /       ");
      strcpy(art[2], "/        ");
      strcpy(art[3], "\\        ");
      strcpy(art[4], " \\_______");
      break;
    // And so on for the rest of the alphabet...
    default:
      printf("Sorry, ASCII art is not available for that character.\n");
      break;
  }
  // Print the ASCII art
  for(int i = 0; i < 5; i++) {
    printf("%s\n", art[i]);
  }
}

// Main function
int main() {
  // Declare variables
  char inputChar;
  // Prompt user for input character
  printf("Enter a character to generate ASCII art: ");
  scanf("%c", &inputChar);
  // Print the ASCII art
  printArt(inputChar);
  return 0;
}