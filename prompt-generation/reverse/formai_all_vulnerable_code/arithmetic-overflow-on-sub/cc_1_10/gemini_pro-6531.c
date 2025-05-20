//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a bucket
struct bucket {
  int count;
  int *values;
};

// Function to create a new bucket
struct bucket* create_bucket() {
  struct bucket* bucket = malloc(sizeof(struct bucket));
  bucket->count = 0;
  bucket->values = NULL;
  return bucket;
}

// Function to add a value to a bucket
void add_to_bucket(struct bucket* bucket, int value) {
  bucket->count++;
  bucket->values = realloc(bucket->values, bucket->count * sizeof(int));
  bucket->values[bucket->count - 1] = value;
}

// Function to sort the values in a bucket
void sort_bucket(struct bucket* bucket) {
  for (int i = 0; i < bucket->count - 1; i++) {
    for (int j = i + 1; j < bucket->count; j++) {
      if (bucket->values[i] > bucket->values[j]) {
        int temp = bucket->values[i];
        bucket->values[i] = bucket->values[j];
        bucket->values[j] = temp;
      }
    }
  }
}

// Function to perform bucket sort on an array
void bucket_sort(int* array, int size) {

  int minimum_value = array[0];
  int maximum_value = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] < minimum_value)
      minimum_value = array[i];
    if (array[i] > maximum_value)
      maximum_value = array[i];
  }

  int bucket_count = (maximum_value - minimum_value) / 100 + 1;
  struct bucket** buckets = malloc(bucket_count * sizeof(struct bucket*));
  for (int i = 0; i < bucket_count; i++) {
    buckets[i] = create_bucket();
  }

  for (int i = 0; i < size; i++) {
    int bucket_index = (array[i] - minimum_value) / 100;
    add_to_bucket(buckets[bucket_index], array[i]);
  }

  for (int i = 0; i < bucket_count; i++) {
    sort_bucket(buckets[i]);
  }

  int index = 0;
  for (int i = 0; i < bucket_count; i++) {
    for (int j = 0; j < buckets[i]->count; j++) {
      array[index++] = buckets[i]->values[j];
    }
    free(buckets[i]->values);
    free(buckets[i]);
  }
  free(buckets);
}

int main() {
  int array[] = {5, 3, 1, 7, 4, 9, 2, 8, 6};
  int size = sizeof(array) / sizeof(array[0]);

  bucket_sort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}