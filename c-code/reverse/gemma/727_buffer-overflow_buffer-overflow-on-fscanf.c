#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_EXAMPLES 1000
#define IMAGE_SIZE 28

int main() {
  FILE *fp;
  int num_examples = 0;
  int i, j, k;
  int **images = (int **)malloc(MAX_NUM_EXAMPLES * sizeof(int *));
  for (i = 0; i < MAX_NUM_EXAMPLES; i++) {
    images[i] = (int *)malloc(IMAGE_SIZE * sizeof(int));
  }

  fp = fopen("mnist.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fscanf(fp, "%d", &num_examples);

  for (i = 0; i < num_examples; i++) {
    for (j = 0; j < IMAGE_SIZE; j++) {
      fscanf(fp, "%d ", images[i][j]);
    }
  }

  fclose(fp);

  // Train neural network
  // ...

  // Evaluate accuracy
  // ...

  for (i = 0; i < MAX_NUM_EXAMPLES; i++) {
    free(images[i]);
  }
  free(images);

  return 0;
}
