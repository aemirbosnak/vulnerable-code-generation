//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input string length
#define MAX_INPUT_LENGTH 1024

// Create a custom compression algorithm
int compress(char *input, char *output) {
  // Create a dictionary to store the unique characters in the input string
  char dictionary[MAX_INPUT_LENGTH];
  int dictionary_size = 0;

  // Iterate over the input string and add unique characters to the dictionary
  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];
    int found = 0;

    // Check if the character is already in the dictionary
    for (int j = 0; j < dictionary_size; j++) {
      if (c == dictionary[j]) {
        found = 1;
        break;
      }
    }

    // If the character is not in the dictionary, add it
    if (!found) {
      dictionary[dictionary_size] = c;
      dictionary_size++;
    }
  }

  // Initialize the output string
  output[0] = '\0';

  // Iterate over the input string and replace each character with its corresponding code in the dictionary
  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];

    // Find the character's code in the dictionary
    int code = -1;
    for (int j = 0; j < dictionary_size; j++) {
      if (c == dictionary[j]) {
        code = j;
        break;
      }
    }

    // Append the character's code to the output string
    char code_string[10];
    sprintf(code_string, "%d", code);
    strcat(output, code_string);
  }

  // Return the length of the compressed string
  return strlen(output);
}

// Create a custom decompression algorithm
int decompress(char *input, char *output) {
  // Create a dictionary to store the unique characters in the input string
  char dictionary[MAX_INPUT_LENGTH];
  int dictionary_size = 0;

  // Iterate over the input string and add unique characters to the dictionary
  int pos = 0;
  while (input[pos] != '\0') {
    char code_string[10];

    // Extract the character's code from the input string
    int i = 0;
    while (input[pos + i] != '\0' && input[pos + i] != ' ') {
      code_string[i] = input[pos + i];
      i++;
    }
    code_string[i] = '\0';
    pos += i + 1;

    // Convert the character's code to an integer
    int code = atoi(code_string);

    // Add the character to the dictionary
    if (code >= dictionary_size) {
      dictionary[dictionary_size] = input[pos - i - 1];
      dictionary_size++;
    }
  }

  // Initialize the output string
  output[0] = '\0';

  // Iterate over the input string and replace each character's code with its corresponding character from the dictionary
  pos = 0;
  while (input[pos] != '\0') {
    char code_string[10];

    // Extract the character's code from the input string
    int i = 0;
    while (input[pos + i] != '\0' && input[pos + i] != ' ') {
      code_string[i] = input[pos + i];
      i++;
    }
    code_string[i] = '\0';
    pos += i + 1;

    // Convert the character's code to an integer
    int code = atoi(code_string);

    // Append the character to the output string
    char c = dictionary[code];
    strcat(output, &c);
  }

  // Return the length of the decompressed string
  return strlen(output);
}

// Main function
int main() {
  // Get the input string from the user
  char input[MAX_INPUT_LENGTH];
  printf("Enter the string to compress: ");
  gets(input);

  // Compress the string
  char compressed[MAX_INPUT_LENGTH];
  int compressed_length = compress(input, compressed);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the string
  char decompressed[MAX_INPUT_LENGTH];
  int decompressed_length = decompress(compressed, decompressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  return 0;
}