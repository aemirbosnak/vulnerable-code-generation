//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_STR_LEN 1024

// Define the maximum number of characters that can be repeated in a row
#define MAX_REPEAT_LEN 128

// Define the maximum number of repeated characters that can be stored in a single byte
#define MAX_STORED_REPEAT_LEN 31

// Define the maximum number of bytes that can be used to store the compressed string
#define MAX_COMPRESSED_LEN (MAX_STR_LEN * 2)

// Compress the given string using the run-length encoding algorithm
int compress(char *input, char *output) {
  int input_len = strlen(input);
  int output_len = 0;

  // Iterate over the input string
  for (int i = 0; i < input_len; i++) {
    // Get the current character and its count
    char c = input[i];
    int count = 1;
    while ((i + 1 < input_len) && (input[i + 1] == c)) {
      count++;
      i++;
    }

    // If the count is less than or equal to MAX_STORED_REPEAT_LEN, store it as a single byte
    if (count <= MAX_STORED_REPEAT_LEN) {
      output[output_len++] = count;
    } else {
      // Otherwise, store the count as two bytes: the first byte is MAX_STORED_REPEAT_LEN, and the second byte is the remaining count
      output[output_len++] = MAX_STORED_REPEAT_LEN;
      output[output_len++] = count - MAX_STORED_REPEAT_LEN;
    }

    // Store the character
    output[output_len++] = c;
  }

  // Return the length of the compressed string
  return output_len;
}

// Decompress the given string using the run-length encoding algorithm
int decompress(char *input, char *output) {
  int input_len = strlen(input);
  int output_len = 0;

  // Iterate over the input string
  for (int i = 0; i < input_len; i++) {
    // Get the current byte
    unsigned char b = input[i];

    // If the byte is less than or equal to MAX_STORED_REPEAT_LEN, it represents the count of the next character
    if (b <= MAX_STORED_REPEAT_LEN) {
      for (int j = 0; j < b; j++) {
        output[output_len++] = input[i + 1];
      }
      i++;
    } else {
      // Otherwise, the byte is MAX_STORED_REPEAT_LEN, and the next byte represents the remaining count
      unsigned char count = input[i + 1];
      for (int j = 0; j < MAX_STORED_REPEAT_LEN + count; j++) {
        output[output_len++] = input[i + 2];
      }
      i += 2;
    }
  }

  // Return the length of the decompressed string
  return output_len;
}

int main() {
  // Get the input string from the user
  char input[MAX_STR_LEN];
  printf("Enter the string to be compressed: ");
  scanf("%s", input);

  // Compress the input string
  char compressed[MAX_COMPRESSED_LEN];
  int compressed_len = compress(input, compressed);

  // Print the compressed string
  printf("Compressed string: ");
  for (int i = 0; i < compressed_len; i++) {
    printf("%02X ", compressed[i]);
  }
  printf("\n");

  // Decompress the compressed string
  char decompressed[MAX_STR_LEN];
  int decompressed_len = decompress(compressed, decompressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  return 0;
}