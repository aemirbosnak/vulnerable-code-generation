//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declare the Morse code table.
const char *morse_code_table[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
  "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-",
  ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
  " ", ".-.-", "---.", "-.-.-", "-.--", "-..-", "-.--.", "-....-", "-....", "-...-", "-...", "---",
  "-.--", "-.-.-", "-....-"
};

// Declare the alphabet.
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

// Declare the Morse code conversion function.
char *text_to_morse(const char *text) {
  // Allocate memory for the Morse code string.
  char *morse_code = malloc(strlen(text) * 5);

  // Convert the text to Morse code.
  int i = 0;
  while (text[i]) {
    // Get the index of the character in the alphabet.
    int index = strchr(alphabet, toupper(text[i])) - alphabet;

    // Append the Morse code for the character to the Morse code string.
    strcat(morse_code, morse_code_table[index]);

    // Increment the index.
    i++;
  }

  // Return the Morse code string.
  return morse_code;
}

// Declare the main function.
int main() {
  // Get the text from the user.
  char text[100];
  printf("Enter the text to convert to Morse code: ");
  scanf("%s", text);

  // Convert the text to Morse code.
  char *morse_code = text_to_morse(text);

  // Print the Morse code.
  printf("The Morse code for \"%s\" is: %s\n", text, morse_code);

  // Free the memory allocated for the Morse code string.
  free(morse_code);

  return 0;
}