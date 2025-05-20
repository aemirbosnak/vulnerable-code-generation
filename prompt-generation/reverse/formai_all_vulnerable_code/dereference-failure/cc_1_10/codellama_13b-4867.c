//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: paranoid
// Paranoid C Binary Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input> <output>\n", argv[0]);
    return 1;
  }

  // Read input file
  char *input_file = argv[1];
  FILE *fp = fopen(input_file, "r");
  if (fp == NULL) {
    printf("Error: Unable to open input file %s\n", input_file);
    return 1;
  }

  // Read input data
  char *input_data = (char *)malloc(sizeof(char) * 1024);
  size_t input_size = fread(input_data, sizeof(char), 1024, fp);
  fclose(fp);

  // Check if input data is valid
  if (input_size < 1) {
    printf("Error: Input file %s is empty\n", input_file);
    return 1;
  }

  // Initialize output file
  char *output_file = argv[2];
  FILE *op = fopen(output_file, "w");
  if (op == NULL) {
    printf("Error: Unable to open output file %s\n", output_file);
    return 1;
  }

  // Convert input data to binary
  char *output_data = (char *)malloc(sizeof(char) * 1024);
  size_t output_size = 0;
  for (size_t i = 0; i < input_size; i++) {
    char c = input_data[i];
    if (c == '0') {
      output_data[output_size++] = 0;
    } else if (c == '1') {
      output_data[output_size++] = 1;
    } else {
      printf("Error: Invalid input data\n");
      return 1;
    }
  }

  // Write output data to file
  fwrite(output_data, sizeof(char), output_size, op);
  fclose(op);

  // Clean up
  free(input_data);
  free(output_data);

  return 0;
}