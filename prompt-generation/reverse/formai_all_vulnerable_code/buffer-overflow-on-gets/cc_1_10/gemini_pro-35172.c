//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-....", "--...", "---..", "----", ".-.-.-"};

// Convert a character to Morse code
char *char_to_morse(char c) {
  // Check if the character is in the Morse code table
  if (c >= 'A' && c <= 'Z') {
    return (char *)morse_table[c - 'A'];
  } else if (c >= 'a' && c <= 'z') {
    return (char *)morse_table[c - 'a'];
  } else if (c == ' ') {
    return " ";
  } else {
    return NULL;
  }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
  // Create a buffer to store the Morse code
  char *morse_code = (char *)malloc(strlen(str) * 5);

  // Convert each character to Morse code
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    char *morse = char_to_morse(str[i]);
    if (morse != NULL) {
      strcpy(&morse_code[j], morse);
      j += strlen(morse);
      morse_code[j++] = ' ';
    }
    i++;
  }

  // Add a null terminator to the Morse code
  morse_code[j] = '\0';

  // Return the Morse code
  return morse_code;
}

// Print the Morse code
void print_morse_code(char *morse_code) {
  printf("Morse code: %s\n", morse_code);
}

// Main function
int main() {
  // Get the text input from the user
  char text[100];
  printf("Enter the text to convert to Morse code: ");
  gets(text);

  // Convert the text to Morse code
  char *morse_code = string_to_morse(text);

  // Print the Morse code
  print_morse_code(morse_code);

  // Free the memory allocated for the Morse code
  free(morse_code);

  return 0;
}