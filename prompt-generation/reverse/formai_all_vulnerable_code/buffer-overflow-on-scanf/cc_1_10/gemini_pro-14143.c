//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the sorting function
void sort(int *array, int size) {
  // Loop through the array
  for (int i = 0; i < size; i++) {
    // Find the smallest element in the unsorted portion of the array
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }

    // Swap the smallest element with the first element in the unsorted portion of the array
    int temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
  }
}

// Print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Get the input array from the user
int main() {
  // Get the size of the array
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Check if the size is valid
  if (size <= 0 || size > MAX_SIZE) {
    printf("Invalid size. Please enter a value between 1 and %d.\n", MAX_SIZE);
    return 1;
  }

  // Allocate memory for the array
  int *array = malloc(sizeof(int) * size);

  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  // Sort the array
  sort(array, size);

  // Print the sorted array
  printf("Sorted array: ");
  print_array(array, size);

  // Free the memory allocated for the array
  free(array);

  return 0;
}