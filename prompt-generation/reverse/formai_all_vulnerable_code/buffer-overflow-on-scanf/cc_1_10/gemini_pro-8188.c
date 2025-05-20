//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the happy searching algorithm
int happy_search(int *arr, int n, int target) {
  // Initialize the index to -1
  int index = -1;

  // Iterate over the array
  for (int i = 0; i < n; i++) {
    // If the current element is equal to the target
    if (arr[i] == target) {
      // Set the index to the current index
      index = i;

      // Break out of the loop
      break;
    }
  }

  // Return the index
  return index;
}

// Main function
int main() {
  // Initialize the array
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Get the size of the array
  int n = sizeof(arr) / sizeof(arr[0]);

  // Get the target value
  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  // Search for the target value
  int index = happy_search(arr, n, target);

  // Print the result
  if (index == -1) {
    printf("Target value not found!\n");
  } else {
    printf("Target value found at index %d!\n", index);
  }

  return 0;
}