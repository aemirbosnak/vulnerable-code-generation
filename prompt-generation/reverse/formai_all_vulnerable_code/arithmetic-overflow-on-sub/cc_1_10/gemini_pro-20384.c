//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to partition an array using the last element as the pivot
int partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return i + 1;
}

// Function to sort an array using quicksort
void quicksort(int *arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

int main() {
  // Get the size of the array
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Get the elements of the array
  int arr[size];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array
  quicksort(arr, 0, size - 1);

  // Print the sorted array
  printf("The sorted array is: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}