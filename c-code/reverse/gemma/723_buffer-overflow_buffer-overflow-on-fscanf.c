#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k, n, img_size = 28, label_size = 10;
  int **img_data = NULL;
  int **label_data = NULL;
  FILE *fp;

  img_data = (int **)malloc(n * img_size * sizeof(int));
  label_data = (int **)malloc(n * label_size * sizeof(int));

  fp = fopen("mnist.txt", "r");
  fscanf(fp, "%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < img_size; j++) {
      fscanf(fp, "%d ", img_data[i] + j);
    }
    fscanf(fp, "%d ", label_data[i]);
  }

  fclose(fp);

  // Implement neural network logic here

  return 0;
}
