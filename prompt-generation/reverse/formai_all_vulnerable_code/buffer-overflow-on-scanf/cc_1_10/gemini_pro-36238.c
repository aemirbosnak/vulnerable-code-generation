//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a 2D array to store the ASCII art
char art[100][100];

// Function to generate the ASCII art
void generateArt(char *text) {
  int i, j, k;
  int len = strlen(text);

  // Iterate over each character in the text
  for (i = 0; i < len; i++) {
    // Get the ASCII value of the character
    int ascii = text[i];

    // Convert the ASCII value to binary
    char binary[8];
    for (j = 0; j < 8; j++) {
      binary[j] = (ascii & (1 << (7 - j))) ? '1' : '0';
    }

    // Iterate over each row in the 2D array
    for (j = 0; j < 8; j++) {
      // Iterate over each column in the 2D array
      for (k = 0; k < 8; k++) {
        // Set the value in the 2D array to the corresponding bit in the binary representation of the ASCII value
        art[j][k] = binary[j * 8 + k];
      }
    }
  }
}

// Function to print the ASCII art
void printArt() {
  int i, j;

  // Iterate over each row in the 2D array
  for (i = 0; i < 8; i++) {
    // Iterate over each column in the 2D array
    for (j = 0; j < 8; j++) {
      // Print the value in the 2D array
      printf("%c", art[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Get the text from the user
  char text[100];
  printf("Enter the text you want to convert to ASCII art: ");
  scanf("%s", text);

  // Generate the ASCII art
  generateArt(text);

  // Print the ASCII art
  printArt();

  return 0;
}