//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// A peaceful approach to sorting
void sereneSort(int *arr, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// A harmonious way to print an array
void serenePrint(int *arr, int n) {
  int i;
  printf("[");
  for (i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }
  printf(" ]\n");
}

// The main function, where peace reigns
int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("The unsorted array: ");
  serenePrint(arr, n);

  sereneSort(arr, n);

  printf("The serene array: ");
  serenePrint(arr, n);

  free(arr);
  return 0;
}