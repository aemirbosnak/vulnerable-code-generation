//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Define the maximum size of the compressed string
#define MAX_COMPRESSED_SIZE 2 * MAX_INPUT_SIZE

// Function to compress the string using run-length encoding
char *compress(char *input, int *compressed_size) {
  int n = strlen(input);

  // Allocate memory for the compressed string
  char *compressed = malloc(MAX_COMPRESSED_SIZE);

  int j = 0;  // Index to write to the compressed string
  int count = 1;  // Count of consecutive characters

  // Iterate over the input string
  for (int i = 0; i < n; i++) {
    // If the current character is the same as the previous character, increment the count
    if (i > 0 && input[i] == input[i - 1]) {
      count++;
    } else {
      // Otherwise, write the count and the character to the compressed string
      compressed[j++] = count + '0';
      compressed[j++] = input[i];
      count = 1;
    }
  }

  // Null-terminate the compressed string
  compressed[j] = '\0';

  // Update the output parameter with the compressed size
  *compressed_size = j;

  return compressed;
}

// Function to decompress the string using run-length encoding
char *decompress(char *compressed, int compressed_size) {
  int n = compressed_size;

  // Allocate memory for the decompressed string
  char *decompressed = malloc(MAX_INPUT_SIZE);

  int j = 0;  // Index to write to the decompressed string
  int count = 0;  // Count of consecutive characters

  // Iterate over the compressed string
  for (int i = 0; i < n; i++) {
    // If the current character is a digit, update the count
    if (compressed[i] >= '0' && compressed[i] <= '9') {
      count = count * 10 + (compressed[i] - '0');
    } else {
      // Otherwise, write the count times the character to the decompressed string
      for (int k = 0; k < count; k++) {
        decompressed[j++] = compressed[i];
      }
      count = 0;
    }
  }

  // Null-terminate the decompressed string
  decompressed[j] = '\0';

  return decompressed;
}

int main() {
  // Get the input string from the user
  char input[MAX_INPUT_SIZE];
  printf("Enter the string to compress: ");
  scanf("%s", input);

  // Compress the string
  int compressed_size;
  char *compressed = compress(input, &compressed_size);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the string
  char *decompressed = decompress(compressed, compressed_size);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory
  free(compressed);
  free(decompressed);

  return 0;
}