//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the sentinel value
#define SENTINEL -1

// Define the brave search function
int brave_search(int arr[], int n, int target) {
  // Initialize the index to the first element of the array
  int index = 0;

  // Loop through the array until the sentinel value is reached
  while (arr[index] != SENTINEL) {
    // Check if the current element is equal to the target
    if (arr[index] == target) {
      // Return the index of the target element
      return index;
    } else {
      // Increment the index to move to the next element
      index++;
    }
  }

  // Return -1 if the target element is not found
  return -1;
}

// Define the main function
int main() {
  // Create an array of integers
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, SENTINEL};

  // Get the size of the array
  int n = sizeof(arr) / sizeof(arr[0]);

  // Get the target value from the user
  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  // Search for the target value in the array using the brave search function
  int index = brave_search(arr, n, target);

  // Check if the target value was found
  if (index != -1) {
    // Print the index of the target value
    printf("The target value was found at index %d\n", index);
  } else {
    // Print that the target value was not found
    printf("The target value was not found\n");
  }

  return 0;
}