//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the type of the element in the array
typedef int element_type;

// Declare the array
element_type array[MAX_SIZE];

// Define the function to search for an element in the array
int search(element_type key) {
  // Initialize the index of the element to be found
  int index = 0;

  // Iterate over the array until the element is found or the end of the array is reached
  while (index < MAX_SIZE && array[index] != key) {
    // Increment the index
    index++;
  }

  // Return the index of the element if it was found, or -1 if it was not found
  return index < MAX_SIZE ? index : -1;
}

// Define the main function
int main() {
  // Initialize the array with some values
  for (int i = 0; i < MAX_SIZE; i++) {
    array[i] = i;
  }

  // Get the key to search for from the user
  element_type key;
  printf("Enter the key to search for: ");
  scanf("%d", &key);

  // Search for the key in the array
  int index = search(key);

  // Print the result of the search
  if (index >= 0) {
    printf("The key was found at index %d\n", index);
  } else {
    printf("The key was not found\n");
  }

  return 0;
}