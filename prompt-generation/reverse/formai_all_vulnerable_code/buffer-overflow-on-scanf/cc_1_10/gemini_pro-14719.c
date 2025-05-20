//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array.
#define MAX_SIZE 100

// Define the type of the search algorithm.
typedef enum {
  LINEAR_SEARCH,
  BINARY_SEARCH
} search_algorithm;

// Define the type of the search result.
typedef enum {
  NOT_FOUND,
  FOUND
} search_result;

// Perform a linear search on the given array.
search_result linear_search(int *array, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      return FOUND;
    }
  }

  return NOT_FOUND;
}

// Perform a binary search on the given array.
search_result binary_search(int *array, int size, int target) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (array[mid] == target) {
      return FOUND;
    } else if (array[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return NOT_FOUND;
}

// Print the result of the search.
void print_search_result(search_result result) {
  switch (result) {
    case NOT_FOUND:
      printf("The target was not found.\n");
      break;
    case FOUND:
      printf("The target was found.\n");
      break;
  }
}

// Get the search algorithm from the user.
search_algorithm get_search_algorithm(void) {
  int algorithm;

  printf("Enter the search algorithm (1 for linear, 2 for binary): ");
  scanf("%d", &algorithm);

  switch (algorithm) {
    case 1:
      return LINEAR_SEARCH;
    case 2:
      return BINARY_SEARCH;
    default:
      printf("Invalid search algorithm.\n");
      exit(EXIT_FAILURE);
  }
}

// Get the target from the user.
int get_target(void) {
  int target;

  printf("Enter the target: ");
  scanf("%d", &target);

  return target;
}

// Get the array from the user.
int *get_array(int size) {
  int *array = malloc(size * sizeof(int));

  printf("Enter the array elements:\n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  return array;
}

// Free the allocated memory.
void free_array(int *array) {
  free(array);
}

// Main function.
int main(void) {
  // Get the search algorithm.
  search_algorithm algorithm = get_search_algorithm();

  // Get the target.
  int target = get_target();

  // Get the array.
  int *array = get_array(MAX_SIZE);

  // Perform the search.
  search_result result;
  switch (algorithm) {
    case LINEAR_SEARCH:
      result = linear_search(array, MAX_SIZE, target);
      break;
    case BINARY_SEARCH:
      result = binary_search(array, MAX_SIZE, target);
      break;
  }

  // Print the result.
  print_search_result(result);

  // Free the allocated memory.
  free_array(array);

  return EXIT_SUCCESS;
}