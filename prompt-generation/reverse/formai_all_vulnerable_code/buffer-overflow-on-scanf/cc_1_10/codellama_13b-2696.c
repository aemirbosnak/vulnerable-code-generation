//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
/*
 * Unique C Compression Algorithm Example Program
 * Interoperable Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MIN_MATCH 3
#define MAX_MATCH 255
#define MIN_LENGTH 100
#define MAX_LENGTH 1000

typedef struct {
  char symbol;
  int length;
} Code;

void compress(char *input, char *output) {
  int input_size = strlen(input);
  int output_size = 0;

  Code codes[256];
  for (int i = 0; i < 256; i++) {
    codes[i].symbol = input[i];
    codes[i].length = 0;
  }

  for (int i = 0; i < input_size; i++) {
    char symbol = input[i];
    if (codes[symbol].length == 0) {
      codes[symbol].length = 1;
    } else {
      codes[symbol].length++;
    }
  }

  for (int i = 0; i < 256; i++) {
    char symbol = codes[i].symbol;
    int length = codes[i].length;
    if (length >= MIN_MATCH) {
      int j = 0;
      while (j < length) {
        output[output_size++] = symbol;
        j++;
      }
    } else {
      output[output_size++] = symbol;
    }
  }

  output[output_size] = '\0';
}

void decompress(char *input, char *output) {
  int input_size = strlen(input);
  int output_size = 0;

  Code codes[256];
  for (int i = 0; i < 256; i++) {
    codes[i].symbol = input[i];
    codes[i].length = 0;
  }

  for (int i = 0; i < input_size; i++) {
    char symbol = input[i];
    if (codes[symbol].length == 0) {
      codes[symbol].length = 1;
    } else {
      codes[symbol].length++;
    }
  }

  for (int i = 0; i < 256; i++) {
    char symbol = codes[i].symbol;
    int length = codes[i].length;
    if (length >= MIN_MATCH) {
      int j = 0;
      while (j < length) {
        output[output_size++] = symbol;
        j++;
      }
    } else {
      output[output_size++] = symbol;
    }
  }

  output[output_size] = '\0';
}

int main() {
  char input[BUFFER_SIZE];
  char output[BUFFER_SIZE];

  // Get input from user
  printf("Enter a string: ");
  scanf("%s", input);

  // Compress the input
  compress(input, output);

  // Print the compressed string
  printf("Compressed string: %s\n", output);

  // Decompress the compressed string
  decompress(output, input);

  // Print the decompressed string
  printf("Decompressed string: %s\n", input);

  return 0;
}