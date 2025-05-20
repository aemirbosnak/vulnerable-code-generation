//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

// Function to compress the input string using run-length encoding
char* compress(char* input) {
  // Allocate memory for the output string
  char* output = malloc(MAX_OUTPUT_LENGTH);

  // Initialize the output string
  int output_index = 0;

  // Iterate over the input string
  int input_index = 0;
  while (input[input_index] != '\0') {
    // Count the number of consecutive occurrences of the current character
    int count = 1;
    while (input[input_index + count] == input[input_index]) {
      count++;
    }

    // Store the character and its count in the output string
    output[output_index++] = input[input_index];
    output[output_index++] = (char)count;

    // Advance the input index to the next character
    input_index += count;
  }

  // Add the null terminator to the output string
  output[output_index] = '\0';

  // Return the output string
  return output;
}

// Function to decompress the input string using run-length encoding
char* decompress(char* input) {
  // Allocate memory for the output string
  char* output = malloc(MAX_OUTPUT_LENGTH);

  // Initialize the output string
  int output_index = 0;

  // Iterate over the input string
  int input_index = 0;
  while (input[input_index] != '\0') {
    // Get the character and its count from the input string
    char character = input[input_index++];
    int count = (int)input[input_index++];

    // Repeat the character count number of times in the output string
    for (int i = 0; i < count; i++) {
      output[output_index++] = character;
    }
  }

  // Add the null terminator to the output string
  output[output_index] = '\0';

  // Return the output string
  return output;
}

// Main function
int main() {
  // Get the input string from the user
  char input[MAX_INPUT_LENGTH];
  printf("Enter the input string: ");
  scanf("%s", input);

  // Compress the input string using run-length encoding
  char* compressed = compress(input);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the compressed string using run-length encoding
  char* decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory
  free(compressed);
  free(decompressed);

  return 0;
}