//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the search function
int search(int arr[], int size, int target) {
  // Iterate over the array
  for (int i = 0; i < size; i++) {
    // Check if the current element is equal to the target
    if (arr[i] == target) {
      // Return the index of the element
      return i;
    }
  }

  // Return -1 if the target is not found
  return -1;
}

// Define the main function
int main() {
  // Get the size of the array from the user
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Check if the size of the array is valid
  if (size <= 0 || size > MAX_SIZE) {
    printf("Invalid size of the array\n");
    return 1;
  }

  // Allocate memory for the array
  int *arr = malloc(sizeof(int) * size);

  // Check if the memory allocation was successful
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Get the target value from the user
  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  // Search for the target value in the array
  int index = search(arr, size, target);

  // Check if the target value was found
  if (index == -1) {
    printf("Target value not found\n");
  } else {
    printf("Target value found at index %d\n", index);
  }

  // Free the memory allocated for the array
  free(arr);

  return 0;
}