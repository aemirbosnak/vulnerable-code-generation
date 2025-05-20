//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the sentinel value
#define SENTINEL -1

// Define the search function
int search(int *arr, int size, int target) {
  // Initialize the index to the first element in the array
  int index = 0;

  // While the index is less than the size of the array and the element at the index is not the target
  while (index < size && arr[index] != target) {
    // Increment the index
    index++;
  }

  // If the index is less than the size of the array, then the target was found
  if (index < size) {
    // Return the index of the target
    return index;
  } else {
    // Return the sentinel value to indicate that the target was not found
    return SENTINEL;
  }
}

// Define the main function
int main() {
  // Get the size of the array from the user
  printf("Enter the size of the array: ");
  int size;
  scanf("%d", &size);

  // Check if the size of the array is valid
  if (size <= 0 || size > MAX_SIZE) {
    printf("Invalid size\n");
    return EXIT_FAILURE;
  }

  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  int arr[size];
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Get the target value from the user
  printf("Enter the target value: ");
  int target;
  scanf("%d", &target);

  // Search for the target value in the array
  int index = search(arr, size, target);

  // If the target value was found, print its index
  if (index != SENTINEL) {
    printf("The target value was found at index %d\n", index);
  } else {
    // If the target value was not found, print that it was not found
    printf("The target value was not found\n");
  }

  return EXIT_SUCCESS;
}