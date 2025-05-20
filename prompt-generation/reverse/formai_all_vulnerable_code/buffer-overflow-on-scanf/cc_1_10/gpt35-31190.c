//FormAI DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int binarySearch(int arr[], int l, int r, int target) {
  if(r >= l) {
    int mid = l + (r - l) / 2;

    if(arr[mid] == target) {
      return mid;
    }

    if(arr[mid] > target) {
      return binarySearch(arr, l, mid - 1, target);
    }

    return binarySearch(arr, mid + 1, r, target);
  }

  return -1;
}

int main() {
  int arr[MAX_SIZE];
  srand(time(0));
  
  printf("Randomly generated array: ");
  for(int i = 0; i < MAX_SIZE; i++) {
    arr[i] = rand() % 100;
  }
  printArray(arr, MAX_SIZE);

  printf("Array in ascending order: ");
  for(int i = 0; i < MAX_SIZE; i++) {
    for(int j = i + 1; j < MAX_SIZE; j++) {
      if(arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  printArray(arr, MAX_SIZE);

  int target;
  printf("Enter a target value to search: ");
  scanf("%d", &target);

  int result = binarySearch(arr, 0, MAX_SIZE - 1, target);
  if(result == -1) {
    printf("%d not found in the array.\n", target);
  } else {
    printf("%d found at index %d in the array.\n", target, result);
  }

  return 0;
}