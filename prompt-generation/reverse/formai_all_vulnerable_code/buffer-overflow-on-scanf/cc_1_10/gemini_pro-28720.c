//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to swap two elements in an array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to sort an array using the bubble sort algorithm
void bubble_sort(int arr[], int size) {
  int i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

// Function to print an array
void print_array(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  int arr[MAX_SIZE], i, size;
  // Get the size of the array from the user
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array using the bubble sort algorithm
  bubble_sort(arr, size);

  // Print the sorted array
  printf("The sorted array is: ");
  print_array(arr, size);

  return 0;
}