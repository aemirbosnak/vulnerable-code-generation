//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the type of the array
typedef int array_type;

// Define the function to search for an element in the array
int search(array_type arr[], int size, array_type element) {
  // Iterate over the array
  for (int i = 0; i < size; i++) {
    // Check if the current element is equal to the element we are looking for
    if (arr[i] == element) {
      // Return the index of the element
      return i;
    }
  }

  // Return -1 if the element is not found
  return -1;
}

// Define the main function
int main() {
  // Create an array of integers
  array_type arr[MAX_SIZE];

  // Initialize the array with random values
  for (int i = 0; i < MAX_SIZE; i++) {
    arr[i] = rand() % 100;
  }

  // Print the array
  printf("Array: ");
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Get the element to search for from the user
  printf("Enter the element to search for: ");
  array_type element;
  scanf("%d", &element);

  // Search for the element in the array
  int index = search(arr, MAX_SIZE, element);

  // Print the result of the search
  if (index == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", index);
  }

  return 0;
}