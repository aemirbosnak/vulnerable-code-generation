//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a function to perform bucket sort
void bucket_sort(float array[], int n) {
  // Initialize an array of buckets
  int i, j;
  int count[n];
  for (i = 0; i < n; i++) {
    count[i] = 0;
  }

  // Calculate which bucket each element belongs to
  for (i = 0; i < n; i++) {
    int bucket_index = n * array[i];
    count[bucket_index]++;
  }

  // Sort the elements in each bucket
  for (i = 0; i < n; i++) {
    int bucket_size = count[i];
    float bucket[bucket_size];
    for (j = 0; j < bucket_size; j++) {
      bucket[j] = 0;
    }
    int k = 0;
    for (j = 0; j < n; j++) {
      int bucket_index = n * array[j];
      if (bucket_index == i) {
        bucket[k++] = array[j];
      }
    }
    // Insertion sort the bucket
    for (j = 1; j < bucket_size; j++) {
      float key = bucket[j];
      int index = j - 1;
      while (index >= 0 && bucket[index] > key) {
        bucket[index + 1] = bucket[index];
        index--;
      }
      bucket[index + 1] = key;
    }
    // Copy the sorted bucket back into the original array
    for (j = 0; j < bucket_size; j++) {
      array[k++] = bucket[j];
    }
  }
}

// A sample main function to test the bucket sort implementation
int main() {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  float array[n];
  int i;
  printf("Enter the elements of the array:\n");
  for (i = 0; i < n; i++) {
    scanf("%f", &array[i]);
  }
  bucket_sort(array, n);
  printf("The sorted array is:\n");
  for (i = 0; i < n; i++) {
    printf("%f ", array[i]);
  }
  return 0;
}