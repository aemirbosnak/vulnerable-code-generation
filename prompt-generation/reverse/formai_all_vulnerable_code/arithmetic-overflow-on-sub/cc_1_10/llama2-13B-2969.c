//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition of the sorting function
void sort_stats(int arr[], int n) {
  int i, j, k, temp;
  clock_t start, end;
  double time_taken;

  // Start the clock
  start = clock();

  // Loop through the array n-1 times
  for (i = 0; i < n - 1; i++) {
    // Find the largest and smallest elements in the unsorted portion of the array
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    // Update the running statistics
    time_taken = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("After %d iterations, the average time taken is %f seconds\n", i, time_taken);

    // Print the sorted portion of the array so far
    for (k = 0; k < i; k++) {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}

int main() {
  int arr[5] = {3, 1, 6, 4, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Sort the array using the sort_stats function
  sort_stats(arr, n);

  // Print the sorted array
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}