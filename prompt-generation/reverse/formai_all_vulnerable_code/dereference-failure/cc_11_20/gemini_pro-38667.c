//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define paranoia 1

int main(int argc, char *argv[])
{
  int i, j, k;
  float *x, *y, *z;
  char *buffer;
  int length;

  if (argc != 4) {
    printf("Usage: %s input.txt output.txt buffer_size\n", argv[0]);
    return 1;
  }

  length = atoi(argv[3]);
  if (length <= 0) {
    printf("Invalid buffer size: %d\n", length);
    return 1;
  }

  x = (float *)malloc(length * sizeof(float));
  if (x == NULL) {
    printf("Failed to allocate memory for x\n");
    return 1;
  }

  y = (float *)malloc(length * sizeof(float));
  if (y == NULL) {
    printf("Failed to allocate memory for y\n");
    return 1;
  }

  z = (float *)malloc(length * sizeof(float));
  if (z == NULL) {
    printf("Failed to allocate memory for z\n");
    return 1;
  }

  buffer = (char *)malloc(length * sizeof(char));
  if (buffer == NULL) {
    printf("Failed to allocate memory for buffer\n");
    return 1;
  }

  FILE *input = fopen(argv[1], "r");
  if (input == NULL) {
    printf("Failed to open input file: %s\n", argv[1]);
    return 1;
  }

  FILE *output = fopen(argv[2], "w");
  if (output == NULL) {
    printf("Failed to open output file: %s\n", argv[2]);
    return 1;
  }

  while (fgets(buffer, length, input) != NULL) {
    for (i = 0; i < length; i++) {
      sscanf(buffer + i * paranoia, "%f ", &x[i]);
    }

    for (j = 0; j < length; j++) {
      sscanf(buffer + j * paranoia, "%f ", &y[j]);
    }

    for (k = 0; k < length; k++) {
      z[k] = x[k] + y[k];
      fprintf(output, "%f ", z[k]);
    }

    fprintf(output, "\n");
  }

  fclose(input);
  fclose(output);

  free(x);
  free(y);
  free(z);
  free(buffer);

  return 0;
}