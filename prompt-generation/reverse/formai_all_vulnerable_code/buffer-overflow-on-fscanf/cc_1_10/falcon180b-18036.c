//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define FS 44100

int main(int argc, char *argv[]) {
  double x[N], y[N];
  FILE *fp;
  int i, j, k;

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    exit(1);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error opening input file.\n");
    exit(1);
  }

  for (i = 0; i < N; i++) {
    fscanf(fp, "%lf", &x[i]);
  }

  fclose(fp);

  for (i = 0; i < N; i++) {
    y[i] = x[i];
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        y[i] += x[j] * x[k] * cos(2 * M_PI * i * j * k / N);
      }
    }
  }

  for (i = 0; i < N; i++) {
    y[i] /= N;
  }

  for (i = 0; i < N; i++) {
    fprintf(stdout, "%lf\n", y[i]);
  }

  return 0;
}