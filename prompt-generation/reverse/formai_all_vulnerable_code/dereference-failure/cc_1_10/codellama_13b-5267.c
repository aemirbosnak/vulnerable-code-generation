//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: surprised
// A unique C compression algorithm example program in a surprised style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];
  char *input, *output;
  int input_size, output_size;

  // Get input from user
  printf("Enter the string to compress: ");
  fgets(buffer, BUFFER_SIZE, stdin);
  input_size = strlen(buffer);

  // Allocate memory for output
  output = malloc(input_size * 2);

  // Compress the input
  int i, j;
  for (i = 0, j = 0; i < input_size; i++, j++) {
    if (buffer[i] != buffer[i + 1]) {
      output[j] = buffer[i];
    } else {
      output[j] = buffer[i];
      output[j + 1] = buffer[i + 1];
      j++;
    }
  }
  output_size = j;

  // Print the compressed output
  printf("Compressed output: ");
  for (i = 0; i < output_size; i++) {
    printf("%c", output[i]);
  }
  printf("\n");

  // Decompress the output
  int k;
  for (i = 0, j = 0, k = 0; i < output_size; i++, j++) {
    if (output[i] == output[i + 1]) {
      j--;
      k++;
    } else {
      buffer[j] = output[i];
      if (k > 0) {
        buffer[j + 1] = '*';
        buffer[j + 2] = k + '0';
        j += 2;
        k = 0;
      }
    }
  }
  buffer[j] = '\0';

  // Print the decompressed output
  printf("Decompressed output: %s\n", buffer);

  return 0;
}