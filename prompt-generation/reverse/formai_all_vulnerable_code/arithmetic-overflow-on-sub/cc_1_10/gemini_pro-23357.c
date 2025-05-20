//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to compare two integers
int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

// Function to search for an element in a sorted array using binary search
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

// Function to print an array
void print_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Create an array of integers
  int arr[MAX_SIZE];

  // Get the size of the array from the user
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array in ascending order using the qsort function
  qsort(arr, size, sizeof(int), compare);

  // Print the sorted array
  printf("Sorted array: ");
  print_array(arr, size);

  // Get the element to be searched from the user
  int element;
  printf("Enter the element to be searched: ");
  scanf("%d", &element);

  // Search for the element in the array using the binary_search function
  int index = binary_search(arr, size, element);

  // Print the result
  if (index == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", index);
  }

  return 0;
}