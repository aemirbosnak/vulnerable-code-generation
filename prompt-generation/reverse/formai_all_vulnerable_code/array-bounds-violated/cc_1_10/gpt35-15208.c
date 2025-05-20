//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Function to print ASCII art representation of char input
void printAsciiArt(char letter) {
  // Array of ASCII art letters in order from A-Z (all uppercase)
  char* asciiArtLetters[] = {
    "             _   _     \n\
            | | | |    \n\
 _ __   ___ | |_| |__  \n\
| '_ \\ / _ \\| __| '_   \\\n\
| | | | (_) | |_| | | |\n\
|_| |_|\\___/ \\__|_| |_|\n", // A
    " _____ \n\
|  __ \\\n\
| |__) |\n\
|  _  / \n\
| | \\\n\
|_| |_|\n", // B
    "  _____  \n\
 / ____|  \n\
| (___   ___ _ __ ___ \n\
 \\___ \\ / __| '__/ _ \\\n\
 ____) | (__| | |  __/\n\
|_____/ \\___|_|  \\___|\n", // C
    // ... rest of alphabet
  };

  // Convert input char to uppercase
  letter = toupper(letter);

  // ASCII value of the first letter ('A')
  int asciiBase = 65;

  // Check if input is a valid uppercase letter
  if (letter >= 'A' && letter <= 'Z') {
    // Index in array of the corresponding ASCII art letter
    int index = letter - asciiBase;

    // Print the ASCII art representation
    printf("%s", asciiArtLetters[index]);
  } else {
    // Print a message indicating an invalid input
    printf("Invalid input: %c\n", letter);
  }
}

int main() {
  // Test with some input strings
  printAsciiArt('A');
  printAsciiArt('B');
  printAsciiArt('C');
  printAsciiArt('Z');
  printAsciiArt('a'); // should print an error message
  printAsciiArt('7'); // should print an error message
  
  return 0;
}