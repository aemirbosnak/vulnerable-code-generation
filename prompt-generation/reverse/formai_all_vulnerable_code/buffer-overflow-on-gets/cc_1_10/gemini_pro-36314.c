//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our surprise C compression algorithm!
char *compress(char *input) {
  // Allocate memory for the compressed string.
  char *output = malloc(strlen(input) + 1);

  // Initialize the output string.
  strcpy(output, "");

  // Iterate over the input string.
  for (int i = 0; i < strlen(input); i++) {
    // Get the current character.
    char current = input[i];

    // Get the length of the current run of characters.
    int run = 1;
    while (i + run < strlen(input) && input[i + run] == current) {
      run++;
    }

    // Add the run to the output string.
    char run_str[10];
    sprintf(run_str, "%d%c", run, current);
    strcat(output, run_str);

    // Increment the index.
    i += run - 1;
  }

  // Return the compressed string.
  return output;
}

// Decompress a compressed string.
char *decompress(char *input) {
  // Allocate memory for the decompressed string.
  char *output = malloc(strlen(input) * 2 + 1);

  // Initialize the output string.
  strcpy(output, "");

  // Iterate over the input string.
  for (int i = 0; i < strlen(input); i++) {
    // Get the number of times to repeat the current character.
    int run = atoi(&input[i]);

    // Repeat the current character the specified number of times.
    for (int j = 0; j < run; j++) {
      strcat(output, &input[i + 1]);
    }

    // Increment the index.
    i += 2;
  }

  // Return the decompressed string.
  return output;
}

int main() {
  // Get the input string from the user.
  char input[100];
  printf("Enter the string to compress: ");
  gets(input);

  // Compress the input string.
  char *compressed = compress(input);

  // Print the compressed string.
  printf("Compressed string: %s\n", compressed);

  // Decompress the compressed string.
  char *decompressed = decompress(compressed);

  // Print the decompressed string.
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory.
  free(compressed);
  free(decompressed);

  return 0;
}