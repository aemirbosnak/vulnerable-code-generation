//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Function to compress the string
char *compress(char *input) {
  // Create a new string to store the compressed string
  char *compressed = malloc(strlen(input) + 1);

  // Initialize the compressed string to empty
  compressed[0] = '\0';

  // Iterate over the input string
  for (int i = 0; i < strlen(input); i++) {
    // Get the current character
    char c = input[i];

    // Get the count of the current character
    int count = 1;
    while (i + 1 < strlen(input) && input[i + 1] == c) {
      count++;
      i++;
    }

    // Append the current character and its count to the compressed string
    char buffer[10];
    sprintf(buffer, "%c%d", c, count);
    strcat(compressed, buffer);
  }

  // Return the compressed string
  return compressed;
}

// Function to decompress the string
char *decompress(char *compressed) {
  // Create a new string to store the decompressed string
  char *decompressed = malloc(strlen(compressed) + 1);

  // Initialize the decompressed string to empty
  decompressed[0] = '\0';

  // Iterate over the compressed string
  for (int i = 0; i < strlen(compressed); i++) {
    // Get the current character
    char c = compressed[i];

    // Get the count of the current character
    int count = 0;
    while (i + 1 < strlen(compressed) && compressed[i + 1] >= '0' && compressed[i + 1] <= '9') {
      count = count * 10 + compressed[i + 1] - '0';
      i++;
    }

    // Append the current character count times to the decompressed string
    for (int j = 0; j < count; j++) {
      decompressed[strlen(decompressed)] = c;
    }
  }

  // Return the decompressed string
  return decompressed;
}

// Main function
int main() {
  // Get the input string from the user
  char input[MAX_CHARS];
  printf("Enter the string to compress: ");
  scanf("%s", input);

  // Compress the string
  char *compressed = compress(input);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the string
  char *decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory
  free(compressed);
  free(decompressed);

  return 0;
}