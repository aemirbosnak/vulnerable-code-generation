//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Prototype for the Morse code conversion function
void toMorse(char *text, char *morse);

int main() {
  // Declare variables
  char text[100], morse[200];

  // Get the input text from the user
  printf("Enter a text to convert to Morse code: ");
  gets(text);

  // Convert the text to Morse code
  toMorse(text, morse);

  // Print the Morse code
  printf("Morse code: %s\n", morse);

  return 0;
}

// Function to convert text to Morse code
void toMorse(char *text, char *morse) {
  // Define the Morse code table
  char morseTable[26][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
     "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
  };

  // Loop through each character in the text
  int i = 0;
  while (text[i] != '\0') {
    // Convert the character to uppercase
    char c = toupper(text[i]);

    // If the character is a letter, convert it to Morse code
    if (c >= 'A' && c <= 'Z') {
      strcat(morse, morseTable[c - 'A']);
    }
    // If the character is a space, add a space to the Morse code
    else if (c == ' ') {
      strcat(morse, " ");
    }

    // Move to the next character in the text
    i++;
  }
}