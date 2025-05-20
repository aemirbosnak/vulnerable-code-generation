//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
  // Declare variables
  char input[MAX_INPUT_SIZE];
  char output[MAX_INPUT_SIZE];
  int input_length, output_length;

  // Get user input
  printf("Enter a string to compress: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Calculate the length of the input string
  input_length = strlen(input);

  // Compress the string
  output_length = compress(input, output);

  // Print the compressed string
  printf("Compressed string: %s\n", output);

  // Decompress the string
  decompress(output, input);

  // Print the decompressed string
  printf("Decompressed string: %s\n", input);

  return 0;
}

int compress(char *input, char *output) {
  int i, j, k;
  char current_char, next_char;

  // Initialize the output string
  output[0] = '\0';

  // Iterate over the input string
  for (i = 0, j = 0; i < strlen(input); i++) {
    // Get the current character
    current_char = input[i];

    // Get the next character
    next_char = input[i + 1];

    // If the current character is the same as the next character, increment the count
    if (current_char == next_char) {
      j++;
    }
    // Otherwise, add the current character and count to the output string
    else {
      output[j++] = current_char;
      output[j++] = j - k;
      k = j;
    }
  }

  // Return the length of the compressed string
  return j;
}

int decompress(char *input, char *output) {
  int i, j, k;
  char current_char, next_char;

  // Initialize the output string
  output[0] = '\0';

  // Iterate over the input string
  for (i = 0, j = 0; i < strlen(input); i++) {
    // Get the current character
    current_char = input[i];

    // Get the next character
    next_char = input[i + 1];

    // If the next character is a number, repeat the current character that many times
    if (next_char >= '0' && next_char <= '9') {
      for (k = 0; k < next_char - '0'; k++) {
        output[j++] = current_char;
      }
      i++;
    }
    // Otherwise, add the current character to the output string
    else {
      output[j++] = current_char;
    }
  }

  // Return the length of the decompressed string
  return j;
}