//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>

#define MAX_SIZE 10

void bubbleSort(int arr[], int n) {
  int i, j;
  for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void insertionSort(int arr[], int n) {
  int i, key, j;
  for(i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}

void selectionSort(int arr[], int n) {
  int i, j, min_index;
  for(i = 0; i < n-1; i++) {
    min_index = i;
    for(j = i+1; j < n; j++) {
      if(arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

int main() {
  int arr[MAX_SIZE];
  int i, n;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements in the array:\n");
  for(i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nOriginal Array: ");
  for(i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  bubbleSort(arr, n);
  printf("\n\nArray after Bubble Sort: ");
  for(i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  insertionSort(arr, n);
  printf("\n\nArray after Insertion Sort: ");
  for(i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  selectionSort(arr, n);
  printf("\n\nArray after Selection Sort: ");
  for(i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}