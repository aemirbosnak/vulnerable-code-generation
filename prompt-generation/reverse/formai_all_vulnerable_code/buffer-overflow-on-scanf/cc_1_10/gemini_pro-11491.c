//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

// Function to search for an element in an array using binary search
int binary_search(int *arr, int size, int element) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == element) {
      return mid;
    } else if (arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

// Main function
int main() {
  // Initialize an array of integers
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int size = sizeof(arr) / sizeof(arr[0]);

  // Sort the array in ascending order
  qsort(arr, size, sizeof(int), compare);

  // Get the element to search for from the user
  int element;
  printf("Enter the element to search for: ");
  scanf("%d", &element);

  // Search for the element using binary search
  int index = binary_search(arr, size, element);

  // Print the result
  if (index == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", index);
  }

  return 0;
}