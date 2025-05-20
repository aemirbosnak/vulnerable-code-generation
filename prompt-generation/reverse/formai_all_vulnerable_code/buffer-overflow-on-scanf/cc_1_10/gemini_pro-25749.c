//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the search function
int search(int *arr, int size, int target) {
  // Iterate over the array
  for (int i = 0; i < size; i++) {
    // Check if the current element is equal to the target
    if (arr[i] == target) {
      // Return the index of the target
      return i;
    }
  }

  // Return -1 if the target is not found
  return -1;
}

// Define the main function
int main() {
  // Define the array
  int arr[MAX_SIZE];

  // Get the size of the array from the user
  printf("Enter the size of the array: ");
  int size;
  scanf("%d", &size);

  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Get the target value from the user
  printf("Enter the target value: ");
  int target;
  scanf("%d", &target);

  // Search for the target value in the array
  int index = search(arr, size, target);

  // Print the result
  if (index == -1) {
    printf("The target value is not found.\n");
  } else {
    printf("The target value is found at index %d.\n", index);
  }

  return 0;
}