//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
// Ada Lovelace's Coded Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode a character
char encode(char c) {
  char encodedChar = (c - 'a' + 3) % 26 + 'a';
  return encodedChar;
}

// Function to decode a character
char decode(char c) {
  char decodedChar = (c - 'a' - 3 + 26) % 26 + 'a';
  return decodedChar;
}

// Function to encode a string
char *encodeString(char *str) {
  char *encodedString = malloc(strlen(str) + 1);
  for (int i = 0; i < strlen(str); i++) {
    encodedString[i] = encode(str[i]);
  }
  encodedString[strlen(str)] = '\0';
  return encodedString;
}

// Function to decode a string
char *decodeString(char *str) {
  char *decodedString = malloc(strlen(str) + 1);
  for (int i = 0; i < strlen(str); i++) {
    decodedString[i] = decode(str[i]);
  }
  decodedString[strlen(str)] = '\0';
  return decodedString;
}

// Main function
int main() {
  // Get the input string
  char str[100];
  printf("Enter the string to be encoded: ");
  gets(str);

  // Encode the string
  char *encodedString = encodeString(str);

  // Print the encoded string
  printf("Encoded string: %s\n", encodedString);

  // Decode the encoded string
  char *decodedString = decodeString(encodedString);

  // Print the decoded string
  printf("Decoded string: %s\n", decodedString);

  // Free the allocated memory
  free(encodedString);
  free(decodedString);

  return 0;
}