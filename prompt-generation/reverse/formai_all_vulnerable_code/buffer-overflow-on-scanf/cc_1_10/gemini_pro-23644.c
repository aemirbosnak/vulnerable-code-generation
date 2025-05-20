//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Declare the array of integers to be searched
int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
// Size of the array
int size = sizeof(arr) / sizeof(arr[0]);

// Define the search function
int search(int key) {
  // Start from the first element of the array
  int start = 0;
  // End at the last element of the array
  int end = size - 1;
  // While the start index is less than or equal to the end index
  while (start <= end) {
    // Find the middle index of the current search space
    int mid = (start + end) / 2;
    // If the key is equal to the middle element, return its index
    if (arr[mid] == key) {
      return mid;
    }
    // If the key is less than the middle element, search in the left half
    else if (arr[mid] > key) {
      end = mid - 1;
    }
    // If the key is greater than the middle element, search in the right half
    else {
      start = mid + 1;
    }
  }
  // If the key is not found, return -1
  return -1;
}

// Main function
int main() {
  // Get the key to be searched from the user
  int key;
  printf("Enter the key to be searched: ");
  scanf("%d", &key);

  // Call the search function to find the index of the key
  int index = search(key);

  // Print the result
  if (index == -1) {
    printf("Key not found in the array.\n");
  } else {
    printf("Key found at index %d.\n", index);
  }

  return 0;
}