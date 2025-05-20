//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: Romeo and Juliet
// A tale of two benchmarks, fair Verona lays the scene

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Mercutio, the swift and agile
void mercutio(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      asm volatile("" ::: "memory");
    }
  }
}

// Romeo, the passionate and eloquent
void romeo(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a = rand() % n;
      int b = rand() % n;
      int c = a + b;
    }
  }
}

// Juliet, the fair and gentle
void juliet(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double a = (double)rand() / RAND_MAX;
      double b = (double)rand() / RAND_MAX;
      double c = a * b;
    }
  }
}

// Capulet, the wealthy and powerful
void capulet(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double *a = (double *)malloc(sizeof(double));
      double *b = (double *)malloc(sizeof(double));
      *a = (double)rand() / RAND_MAX;
      *b = (double)rand() / RAND_MAX;
      double c = *a * *b;
      free(a);
      free(b);
    }
  }
}

// The benchmark duel
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s n\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  clock_t start, end;

  // Mercutio, the swift and agile
  start = clock();
  mercutio(n);
  end = clock();
  printf("Mercutio: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  // Romeo, the passionate and eloquent
  start = clock();
  romeo(n);
  end = clock();
  printf("Romeo: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  // Juliet, the fair and gentle
  start = clock();
  juliet(n);
  end = clock();
  printf("Juliet: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  // Capulet, the wealthy and powerful
  start = clock();
  capulet(n);
  end = clock();
  printf("Capulet: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}