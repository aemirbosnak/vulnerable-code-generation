//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Morse code table.
char *morse_table[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.--.-", ".-.-.-",
};

// Declare the alphabet table.
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to convert a character to Morse code.
char *to_morse(char c) {
  // Convert the character to uppercase.
  c = toupper(c);

  // Find the index of the character in the alphabet table.
  int index = strcspn(alphabet, &c);

  // Return the corresponding Morse code from the table.
  return morse_table[index];
}

// Function to convert a string to Morse code.
char *to_morse_string(char *str) {
  // Allocate memory for the Morse code string.
  char *morse_string = malloc(strlen(str) * 5);

  // Convert each character in the string to Morse code.
  for (int i = 0; i < strlen(str); i++) {
    strcat(morse_string, to_morse(str[i]));
    strcat(morse_string, " ");
  }

  // Return the Morse code string.
  return morse_string;
}

// Main function.
int main() {
  // Get the input string from the user.
  char str[100];
  printf("Enter a string to convert to Morse code: ");
  scanf("%s", str);

  // Convert the string to Morse code.
  char *morse_string = to_morse_string(str);

  // Print the Morse code string.
  printf("Morse code: %s\n", morse_string);

  // Free the memory allocated for the Morse code string.
  free(morse_string);

  return 0;
}