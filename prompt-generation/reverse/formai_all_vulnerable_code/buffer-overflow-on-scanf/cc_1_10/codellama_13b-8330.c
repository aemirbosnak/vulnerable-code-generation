//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int size) {
  int i, j, temp;
  bool swapped = true;

  for (i = 0; i < size - 1 && swapped; i++) {
    swapped = false;
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
  }
}

int main() {
  int arr[MAX_SIZE];
  int size = 0;

  printf("Enter the number of elements: ");
  scanf("%d", &size);

  printf("Enter the elements: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  bubbleSort(arr, size);

  printf("Sorted array: ");
  printArray(arr, size);

  return 0;
}