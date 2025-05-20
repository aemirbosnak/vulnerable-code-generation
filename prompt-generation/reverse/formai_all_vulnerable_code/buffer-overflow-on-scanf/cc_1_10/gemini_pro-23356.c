//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the bucket structure
typedef struct bucket {
  int *arr;
  int size;
  int capacity;
} bucket;

// Create a new bucket
bucket *create_bucket(int capacity) {
  bucket *b = (bucket *)malloc(sizeof(bucket));
  b->size = 0;
  b->capacity = capacity;
  b->arr = (int *)malloc(sizeof(int) * capacity);
  return b;
}

// Insert an element into the bucket
void insert_into_bucket(bucket *b, int val) {
  if (b->size == b->capacity) {
    b->capacity *= 2;
    b->arr = (int *)realloc(b->arr, sizeof(int) * b->capacity);
  }
  b->arr[b->size++] = val;
}

// Sort the bucket using insertion sort
void sort_bucket(bucket *b) {
  for (int i = 1; i < b->size; i++) {
    int key = b->arr[i];
    int j = i - 1;
    while (j >= 0 && b->arr[j] > key) {
      b->arr[j + 1] = b->arr[j];
      j--;
    }
    b->arr[j + 1] = key;
  }
}

// Perform bucket sort on the given array
void bucket_sort(int *arr, int n, int num_buckets) {
  // Create an array of buckets
  bucket **buckets = (bucket **)malloc(sizeof(bucket *) * num_buckets);
  for (int i = 0; i < num_buckets; i++) {
    buckets[i] = create_bucket(n / num_buckets);
  }

  // Distribute elements into buckets
  for (int i = 0; i < n; i++) {
    int bucket_index = arr[i] / num_buckets;
    insert_into_bucket(buckets[bucket_index], arr[i]);
  }

  // Sort each bucket
  for (int i = 0; i < num_buckets; i++) {
    sort_bucket(buckets[i]);
  }

  // Merge the sorted buckets into the original array
  int k = 0;
  for (int i = 0; i < num_buckets; i++) {
    for (int j = 0; j < buckets[i]->size; j++) {
      arr[k++] = buckets[i]->arr[j];
    }
  }

  // Free the buckets
  for (int i = 0; i < num_buckets; i++) {
    free(buckets[i]->arr);
    free(buckets[i]);
  }
  free(buckets);
}

// Print the array
void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Get the array and the number of elements
  int n, num_buckets;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the number of buckets: ");
  scanf("%d", &num_buckets);

  // Create the array
  int *arr = (int *)malloc(sizeof(int) * n);
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Perform bucket sort on the array
  bucket_sort(arr, n, num_buckets);

  // Print the sorted array
  printf("Sorted array: ");
  print_array(arr, n);

  // Free the array
  free(arr);

  return 0;
}