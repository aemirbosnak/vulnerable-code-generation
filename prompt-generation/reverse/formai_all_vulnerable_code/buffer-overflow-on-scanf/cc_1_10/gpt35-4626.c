//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("Error: Invalid array size\n");
    exit(EXIT_FAILURE);
  }

  int *arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Error: Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < 0) {
      printf("Error: Negative integer entered\n");
      free(arr);
      exit(EXIT_FAILURE);
    }
  }

  printf("Original array: ");
  printArray(arr, n);

  // Sorting the array in ascending order using selection sort algorithm
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    }
  }

  printf("Sorted array in ascending order: ");
  printArray(arr, n);

  free(arr);

  return 0;
}