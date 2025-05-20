//FormAI DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100 // Size of array to be searched

int linear_search(int arr[], int size, int elem);

int main() {

  srand(time(NULL)); // Initialize random seed

  // Initialize variables
  int arr[ARRAY_SIZE];
  int elem, result;
  clock_t start, end;
  double cpu_time_used;

  // Initialize array with random integers between 1 and 100
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 100 + 1;
  }

  // Print the array
  printf("Array: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Prompt user for element to search for
  printf("Enter the element you want to search for: ");
  scanf("%d", &elem);

  // Perform linear search on array and time it
  start = clock();
  result = linear_search(arr, ARRAY_SIZE, elem);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Print the result and time taken
  if (result == -1) {
    printf("Element %d was not found in the array.\n", elem);
  } else {
    printf("Element %d was found at index %d in the array.\n", elem, result);
  }
  printf("Time taken to perform search: %f seconds\n", cpu_time_used);

  return 0;
}

// Linear search algorithm that searches for a specific element in an integer array
int linear_search(int arr[], int size, int elem) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == elem) {
      return i;
    }
  }
  return -1;
}