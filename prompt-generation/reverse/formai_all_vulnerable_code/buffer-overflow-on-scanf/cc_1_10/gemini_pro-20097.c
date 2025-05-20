//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compress a string using run-length encoding.
char *compress(char *str) {
  // Count the length of the compressed string.
  int compressed_length = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    int count = 1;
    while (str[i] == str[i + 1]) {
      count++;
      i++;
    }
    compressed_length += snprintf(NULL, 0, "%d%c", count, str[i]);
  }

  // Allocate memory for the compressed string.
  char *compressed_str = malloc(compressed_length + 1);

  // Compress the string.
  int compressed_index = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    int count = 1;
    while (str[i] == str[i + 1]) {
      count++;
      i++;
    }
    compressed_index += snprintf(compressed_str + compressed_index, compressed_length - compressed_index, "%d%c", count, str[i]);
  }

  // Return the compressed string.
  return compressed_str;
}

// Decompress a string compressed using run-length encoding.
char *decompress(char *str) {
  // Count the length of the decompressed string.
  int decompressed_length = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    int count = 0;
    while (str[i] >= '0' && str[i] <= '9') {
      count = count * 10 + str[i] - '0';
      i++;
    }
    decompressed_length += count;
  }

  // Allocate memory for the decompressed string.
  char *decompressed_str = malloc(decompressed_length + 1);

  // Decompress the string.
  int decompressed_index = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    int count = 0;
    while (str[i] >= '0' && str[i] <= '9') {
      count = count * 10 + str[i] - '0';
      i++;
    }
    for (int j = 0; j < count; j++) {
      decompressed_str[decompressed_index++] = str[i];
    }
  }

  // Return the decompressed string.
  return decompressed_str;
}

int main() {
  // Get the input string.
  char *str = malloc(100);
  printf("Enter the string to compress: ");
  scanf("%s", str);

  // Compress the string.
  char *compressed_str = compress(str);

  // Print the compressed string.
  printf("Compressed string: %s\n", compressed_str);

  // Decompress the string.
  char *decompressed_str = decompress(compressed_str);

  // Print the decompressed string.
  printf("Decompressed string: %s\n", decompressed_str);

  // Free the allocated memory.
  free(str);
  free(compressed_str);
  free(decompressed_str);

  return 0;
}