//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
  int n;
  double *x;
} signal;

// Create a new signal
signal* new_signal(int n) {
  signal *s = malloc(sizeof(signal));
  s->n = n;
  s->x = malloc(n * sizeof(double));
  return s;
}

// Free a signal
void free_signal(signal *s) {
  free(s->x);
  free(s);
}

// Read a signal from a file
signal* read_signal(const char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening file");
    return NULL;
  }

  int n;
  fscanf(f, "%d", &n);

  signal *s = new_signal(n);

  for (int i = 0; i < n; i++) {
    fscanf(f, "%lf", &s->x[i]);
  }

  fclose(f);

  return s;
}

// Write a signal to a file
void write_signal(const char *filename, signal *s) {
  FILE *f = fopen(filename, "w");
  if (f == NULL) {
    perror("Error opening file");
    return;
  }

  fprintf(f, "%d\n", s->n);

  for (int i = 0; i < s->n; i++) {
    fprintf(f, "%lf\n", s->x[i]);
  }

  fclose(f);
}

// Plot a signal
void plot_signal(signal *s) {
  for (int i = 0; i < s->n; i++) {
    printf("%d %lf\n", i, s->x[i]);
  }
}

// Convolution
signal* convolve(signal *s1, signal *s2) {
  int n = s1->n + s2->n - 1;
  signal *result = new_signal(n);

  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < s1->n; j++) {
      int k = i - j;
      if (k >= 0 && k < s2->n) {
        sum += s1->x[j] * s2->x[k];
      }
    }
    result->x[i] = sum;
  }

  return result;
}

// Correlation
signal* correlate(signal *s1, signal *s2) {
  int n = s1->n + s2->n - 1;
  signal *result = new_signal(n);

  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < s1->n; j++) {
      int k = i + j - s1->n + 1;
      if (k >= 0 && k < s2->n) {
        sum += s1->x[j] * s2->x[k];
      }
    }
    result->x[i] = sum;
  }

  return result;
}

// Main function
int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input_signal1> <input_signal2> <output_signal>\n", argv[0]);
    return 1;
  }

  signal *s1 = read_signal(argv[1]);
  if (s1 == NULL) {
    return 1;
  }

  signal *s2 = read_signal(argv[2]);
  if (s2 == NULL) {
    free_signal(s1);
    return 1;
  }

  signal *result;

  if (strcmp(argv[3], "convolution") == 0) {
    result = convolve(s1, s2);
  } else if (strcmp(argv[3], "correlation") == 0) {
    result = correlate(s1, s2);
  } else {
    fprintf(stderr, "Invalid output signal type: %s\n", argv[3]);
    free_signal(s1);
    free_signal(s2);
    return 1;
  }

  write_signal(argv[3], result);

  free_signal(s1);
  free_signal(s2);
  free_signal(result);

  return 0;
}