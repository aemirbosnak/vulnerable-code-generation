//GEMINI-pro DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  FILE *fp;
  char filename[256];
  int n, i, j, k;
  double a[100][100], b[100][100], c[100][100];

  // Get the input filename from the user
  printf("Enter the name of the input file: ");
  scanf("%s", filename);

  // Read the matrices from the input file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening the input file!\n");
    return 1;
  }
  fscanf(fp, "%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fscanf(fp, "%lf", &a[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fscanf(fp, "%lf", &b[i][j]);
    }
  }
  fclose(fp);

  // Compute the product of the two matrices
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Write the product matrix to the output file
  fp = fopen("output.txt", "w");
  if (fp == NULL) {
    printf("Error opening the output file!\n");
    return 1;
  }
  fprintf(fp, "%d\n", n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fprintf(fp, "%lf ", c[i][j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  return 0;
}