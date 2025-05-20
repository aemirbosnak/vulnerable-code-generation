//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the size of the array
#define SIZE 10

// Define the search key
#define KEY 5

// Function to perform a sequential search
int sequential_search(int *arr, int size, int key) {
  // Iterate over the array
  for (int i = 0; i < size; i++) {
    // Check if the current element is equal to the key
    if (arr[i] == key) {
      // Return the index of the key
      return i;
    }
  }

  // Return -1 if the key is not found
  return -1;
}

// Function to perform a binary search
int binary_search(int *arr, int size, int key) {
  // Set the lower and upper bounds
  int low = 0;
  int high = size - 1;

  // While the lower bound is less than or equal to the upper bound
  while (low <= high) {
    // Calculate the midpoint of the array
    int mid = (low + high) / 2;

    // Check if the current element is equal to the key
    if (arr[mid] == key) {
      // Return the index of the key
      return mid;
    }

    // If the current element is less than the key
    else if (arr[mid] < key) {
      // Set the lower bound to the midpoint plus one
      low = mid + 1;
    }

    // Otherwise, the current element is greater than the key
    else {
      // Set the upper bound to the midpoint minus one
      high = mid - 1;
    }
  }

  // Return -1 if the key is not found
  return -1;
}

// Function to test the sequential and binary search algorithms
void test_search_algorithms(int *arr, int size, int key) {
  // Perform a sequential search
  int sequential_index = sequential_search(arr, size, key);

  // Perform a binary search
  int binary_index = binary_search(arr, size, key);

  // Print the results
  printf("Sequential search: ");
  if (sequential_index == -1) {
    printf("Key not found\n");
  } else {
    printf("Key found at index %d\n", sequential_index);
  }

  printf("Binary search: ");
  if (binary_index == -1) {
    printf("Key not found\n");
  } else {
    printf("Key found at index %d\n", binary_index);
  }
}

// Main function
int main() {
  // Create an array of integers
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Get the size of the array
  int size = sizeof(arr) / sizeof(arr[0]);

  // Get the search key
  int key;
  printf("Enter the search key: ");
  scanf("%d", &key);

  // Test the sequential and binary search algorithms
  test_search_algorithms(arr, size, key);

  return 0;
}