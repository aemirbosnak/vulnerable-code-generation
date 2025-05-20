//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: automated
// C Compression Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Compression function
void compress(char* input, char* output) {
  int i, j, count = 1;
  char current, previous;

  for (i = 0; i < strlen(input); i++) {
    current = input[i];
    if (current == previous) {
      count++;
    } else {
      output[j++] = current;
      previous = current;
      count = 1;
    }
  }
}

// Decompression function
void decompress(char* input, char* output) {
  int i, j, count = 1;
  char current, previous;

  for (i = 0; i < strlen(input); i++) {
    current = input[i];
    if (current == previous) {
      count++;
    } else {
      for (int k = 0; k < count; k++) {
        output[j++] = current;
      }
      previous = current;
      count = 1;
    }
  }
}

int main() {
  char input[BUFFER_SIZE];
  char output[BUFFER_SIZE];

  // Get input string
  printf("Enter a string: ");
  fgets(input, BUFFER_SIZE, stdin);

  // Compress input string
  compress(input, output);

  // Decompress output string
  decompress(output, input);

  // Print decompressed string
  printf("Decompressed string: %s\n", input);

  return 0;
}