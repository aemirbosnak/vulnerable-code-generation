#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  FILE *fp = fopen("mnist.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  int data[1000];
  int i = 0;
  fscanf(fp, "%d ", data);

  fclose(fp);

  for (i = 0; i < 1000; i++) {
    // Train neural network on data[i]
  }

  return 0;
}
