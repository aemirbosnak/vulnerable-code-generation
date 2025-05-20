//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100
#define SORT_ORDER_ASCENDING 1
#define SORT_ORDER_DESCENDING 2

void sortArray(int arr[], int len, int sortOrder) {
  int i, j, temp;

  if (sortOrder == SORT_ORDER_ASCENDING) {
    for (i = 0; i < len - 1; i++) {
      for (j = i + 1; j < len; j++) {
        if (arr[i] > arr[j]) {
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
  } else {
    for (i = 0; i < len - 1; i++) {
      for (j = i + 1; j < len; j++) {
        if (arr[i] < arr[j]) {
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
    arr[len - 1] = arr[0];
  }
}

int main() {
  int arr[MAX_ARRAY_SIZE], len = 0;
  int sortOrder = SORT_ORDER_ASCENDING;

  // Read the array from the user
  printf("Enter the elements of the array (%d elements max):\n", MAX_ARRAY_SIZE);
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    scanf("%d", &arr[i]);
    len++;
  }

  // Display the array before sorting
  printf("Before sorting:\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Ask the user to choose the sort order
  printf("Do you want to sort the array in ascending or descending order? (1 for ascending, 2 for descending)\n");
  scanf("%d", &sortOrder);

  // Sort the array
  sortArray(arr, len, sortOrder);

  // Display the array after sorting
  printf("After sorting:\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}