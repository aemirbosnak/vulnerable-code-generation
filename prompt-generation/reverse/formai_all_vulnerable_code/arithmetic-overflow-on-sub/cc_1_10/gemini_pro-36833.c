//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the number of elements in the array
#define N 10

// Define the maximum value of an element in the array
#define MAX_VALUE 100

// Define the number of bins to use in the counting sort
#define NUM_BINS 10

// Function to print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Function to sort the array using counting sort
void counting_sort(int *array, int size) {
  // Create an array of bins to store the count of each element
  int bins[NUM_BINS];

  // Initialize the bins to 0
  for (int i = 0; i < NUM_BINS; i++) {
    bins[i] = 0;
  }

  // Count the number of occurrences of each element in the array
  for (int i = 0; i < size; i++) {
    bins[array[i]]++;
  }

  // Calculate the cumulative sum of the bins
  for (int i = 1; i < NUM_BINS; i++) {
    bins[i] += bins[i - 1];
  }

  // Create an array to store the sorted elements
  int sorted_array[size];

  // Iterate over the bins in reverse order to place the elements in the sorted array
  for (int i = size - 1; i >= 0; i--) {
    sorted_array[--bins[array[i]]] = array[i];
  }

  // Copy the sorted array back to the original array
  for (int i = 0; i < size; i++) {
    array[i] = sorted_array[i];
  }
}

// Function to main
int main() {
  // Create an array of random numbers
  int array[N];
  for (int i = 0; i < N; i++) {
    array[i] = rand() % MAX_VALUE;
  }

  // Print the unsorted array
  printf("Unsorted array:\n");
  print_array(array, N);

  // Sort the array using counting sort
  counting_sort(array, N);

  // Print the sorted array
  printf("Sorted array:\n");
  print_array(array, N);

  return 0;
}