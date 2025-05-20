//FormAI DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;

  while (i < left_size && j < right_size) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }

  while (i < left_size) {
    arr[k++] = left[i++];
  }

  while (j < right_size) {
    arr[k++] = right[j++];
  }
}

void merge_sort(int arr[], int n) {
  if (n < 2) return;

  int mid = n / 2;
  int left[mid], right[n - mid];

  for (int i = 0; i < mid; i++) {
    left[i] = arr[i];
  }

  for (int i = mid; i < n; i++) {
    right[i - mid] = arr[i];
  }

  merge_sort(left, mid);
  merge_sort(right, n - mid);
  merge(arr, left, mid, right, n - mid);
}

int main() {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nUnsorted array:");
  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }

  merge_sort(arr, n);

  printf("\nSorted array:");
  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }

  return 0;
}