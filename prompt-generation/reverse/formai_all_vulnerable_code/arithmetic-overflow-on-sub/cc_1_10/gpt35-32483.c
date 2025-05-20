//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_double() {
  return ((double)rand() / (double)RAND_MAX);
}

void fill_array(double *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand_double();
  }
}

void selection_sort(double *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    if (min != i) {
      double temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }
  }
}

void array_statistics(double *array, int size, double *mean, double *variance) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  *mean = sum / size;

  double sum_squares = 0.0;
  for (int i = 0; i < size; i++) {
    double diff = array[i] - *mean;
    sum_squares += diff * diff;
  }
  *variance = sum_squares / (size - 1);
}

int main(int argc, char **argv) {
  int size = atoi(argv[1]);
  double *array = (double *)malloc(sizeof(double) * size);

  fill_array(array, size);
  clock_t selection_sort_time = clock();
  selection_sort(array, size);
  selection_sort_time = clock() - selection_sort_time;

  double mean, variance;
  array_statistics(array, size, &mean, &variance);

  printf("Size: %d\n", size);
  printf("Mean: %lf\n", mean);
  printf("Variance: %lf\n", variance);
  printf("Selection Sort Time: %ld\n", selection_sort_time);

  free(array);
  return 0;
}