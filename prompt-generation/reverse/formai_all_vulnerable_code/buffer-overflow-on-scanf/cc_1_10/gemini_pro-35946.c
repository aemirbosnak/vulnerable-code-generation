//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the serenity constant.
#define SERENITY 0

// Define the serenity search function.
int serenity_search(int *array, int size, int target) {
  // Initialize the low and high indices.
  int low = 0;
  int high = size - 1;

  // While the low index is less than or equal to the high index, continue searching.
  while (low <= high) {
    // Calculate the midpoint of the current search range.
    int mid = (low + high) / 2;

    // If the target is equal to the element at the midpoint, return the midpoint.
    if (array[mid] == target) {
      return mid;
    }

    // If the target is less than the element at the midpoint, search the lower half.
    else if (array[mid] > target) {
      high = mid - 1;
    }

    // Otherwise, search the upper half.
    else {
      low = mid + 1;
    }
  }

  // If the target is not found, return serenity.
  return SERENITY;
}

// Define the main function.
int main() {
  // Initialize the array.
  int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

  // Get the size of the array.
  int size = sizeof(array) / sizeof(array[0]);

  // Get the target value.
  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  // Search for the target value.
  int result = serenity_search(array, size, target);

  // If the target value is found, print the index.
  if (result != SERENITY) {
    printf("The target value is found at index %d.\n", result);
  }

  // Otherwise, print that the target value is not found.
  else {
    printf("The target value is not found.\n");
  }

  return 0;
}