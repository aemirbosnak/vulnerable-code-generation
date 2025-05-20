//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the main function
int main() {
  // Let's initialize some variables to make our lives easier
  int n, i, j, k;
  double start, end, elapsed;

  // Ask the user to input the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // Create an array of n integers
  int *arr = (int *)malloc(n * sizeof(int));

  // Initialize the array with random values
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  // Let's start the benchmarking!
  // We'll measure the time it takes to sort the array using three different algorithms: bubble sort, selection sort, and insertion sort

  // Bubble sort
  start = clock();
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        k = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = k;
      }
    }
  }
  end = clock();
  elapsed = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Bubble sort took %f seconds\n", elapsed);

  // Selection sort
  start = clock();
  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    k = arr[i];
    arr[i] = arr[min];
    arr[min] = k;
  }
  end = clock();
  elapsed = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Selection sort took %f seconds\n", elapsed);

  // Insertion sort
  start = clock();
  for (i = 1; i < n; i++) {
    int key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  end = clock();
  elapsed = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Insertion sort took %f seconds\n", elapsed);

  // Free the memory allocated for the array
  free(arr);

  return 0;
}