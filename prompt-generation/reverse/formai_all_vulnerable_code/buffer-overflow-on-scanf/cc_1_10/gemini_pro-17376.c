//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a thankful greeting
const char *greeting = "I am grateful for this opportunity to convert text to Morse code!";

// Declare an array of Morse code characters
const char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-....", "--...", "---..", "----.", "-----"};

// Declare an array of corresponding alphabet characters
const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

// Function to convert a character to Morse code
char *charToMorse(char c) {
  // Convert the character to lowercase
  c = tolower(c);

  // Find the index of the character in the alphabet array
  int index = strchr(alphabet, c) - alphabet;

  // Return the corresponding Morse code character from the morseCode array
  return morseCode[index];
}

// Function to convert a string to Morse code
char *stringToMorse(char *str) {
  // Allocate memory for the Morse code string
  char *morseCodeString = malloc(strlen(str) * 5);

  // Convert each character in the string to Morse code and append it to the Morse code string
  for (int i = 0; i < strlen(str); i++) {
    strcat(morseCodeString, charToMorse(str[i]));
  }

  // Return the Morse code string
  return morseCodeString;
}

// Main function
int main() {
  // Print the thankful greeting
  printf("%s\n", greeting);

  // Get the input string from the user
  char *inputString;
  printf("Enter a string to convert to Morse code: ");
  scanf("%s", inputString);

  // Convert the input string to Morse code
  char *morseCodeString = stringToMorse(inputString);

  // Print the Morse code string
  printf("Morse code: %s\n", morseCodeString);

  // Free the memory allocated for the Morse code string
  free(morseCodeString);

  return 0;
}