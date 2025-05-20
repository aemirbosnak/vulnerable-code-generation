//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  // Define the input and output buffers
  char input_buffer[MAX_BUFFER_SIZE];
  char output_buffer[MAX_BUFFER_SIZE];

  // Get the input data from the user
  printf("Enter data: ");
  scanf("%s", input_buffer);

  // Compress the data
  int compressed_size = compress(input_buffer, output_buffer);

  // Print the compressed data
  printf("Compressed data: ");
  for (int i = 0; i < compressed_size; i++) {
    printf("%c ", output_buffer[i]);
  }

  printf("\n");

  return 0;
}

int compress(char *input_buffer, char *output_buffer) {
  // Calculate the number of repeated characters in the input buffer
  int repeat_count = 0;
  char current_character = '\0';
  int i = 0;
  for (i = 0; input_buffer[i] != '\0'; i++) {
    if (input_buffer[i] == current_character) {
      repeat_count++;
    } else {
      if (repeat_count > 0) {
        output_buffer[i - repeat_count] = repeat_count - 1;
      }
      current_character = input_buffer[i];
      repeat_count = 1;
    }
  }

  // Add the end-of-file marker to the output buffer
  output_buffer[i - repeat_count] = '\0';

  // Return the size of the compressed data
  return i - repeat_count;
}