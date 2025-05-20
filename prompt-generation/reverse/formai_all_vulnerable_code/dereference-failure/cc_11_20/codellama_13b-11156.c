//Code Llama-13B DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
/* Digital signal processing example program in Dennis Ritchie style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main(int argc, char **argv) {
  int i, j;
  int input[MAX_SIZE];
  int output[MAX_SIZE];
  int filter[MAX_SIZE];
  int filter_size;
  int input_size;
  int output_size;

  // Read input and filter from command line
  if (argc != 3) {
    printf("Usage: %s <input_size> <filter_size>\n", argv[0]);
    return 1;
  }

  input_size = atoi(argv[1]);
  filter_size = atoi(argv[2]);

  if (input_size > MAX_SIZE || filter_size > MAX_SIZE) {
    printf("Error: input or filter size is too large\n");
    return 1;
  }

  for (i = 0; i < input_size; i++) {
    input[i] = i * 10;
  }

  for (i = 0; i < filter_size; i++) {
    filter[i] = i * 5;
  }

  // Convolution
  output_size = input_size + filter_size - 1;
  for (i = 0; i < output_size; i++) {
    output[i] = 0;
    for (j = 0; j < filter_size; j++) {
      if (i - j >= 0 && i - j < input_size) {
        output[i] += input[i - j] * filter[j];
      }
    }
  }

  // Print output
  for (i = 0; i < output_size; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");

  return 0;
}