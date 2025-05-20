//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size) {
  int temp, i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printArray(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  printf("Enter the number of elements in the array: ");
  int size;
  scanf("%d", &size);

  int *arr = (int *)malloc(size * sizeof(int));

  printf("Enter %d integers:\n", size);
  int i;
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: ");
  printArray(arr, size);

  printf("Sorting array using Bubble Sort...\n");
  bubbleSort(arr, size);

  printf("Sorted array: ");
  printArray(arr, size);

  free(arr);

  return 0;
}