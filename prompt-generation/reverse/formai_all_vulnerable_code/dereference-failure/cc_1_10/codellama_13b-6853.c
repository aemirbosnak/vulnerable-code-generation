//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
// Bucket Sort Implementation Example Program

#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
  // create an array to hold the buckets
  int *buckets[n];

  // iterate through the input array and place each element in its corresponding bucket
  for (int i = 0; i < n; i++) {
    int index = arr[i] / (n - 1);
    buckets[index] = arr[i];
  }

  // sort each bucket using insertion sort
  for (int i = 0; i < n; i++) {
    int *bucket = buckets[i];
    int *ptr = bucket;
    int *tail = ptr + 1;

    while (tail < bucket + (n - 1)) {
      int tmp = *tail;
      int *ptr2 = tail - 1;

      while (ptr2 >= bucket && *ptr2 > tmp) {
        *(ptr2 + 1) = *ptr2;
        ptr2--;
      }

      *(ptr2 + 1) = tmp;
      tail++;
    }
  }

  // combine the sorted buckets back into the original array
  int k = 0;
  for (int i = 0; i < n; i++) {
    int *bucket = buckets[i];
    for (int j = 0; j < n; j++) {
      arr[k] = bucket[j];
      k++;
    }
  }
}

int main() {
  int arr[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  bucketSort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}