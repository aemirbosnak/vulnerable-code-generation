//FormAI DATASET v1.0 Category: Sorting ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 1000

void merge(int arr[], int low, int mid, int high);
void merge_sort(int arr[], int low, int high);
void print_array(int arr[], int len);

int main() {
  int arr[MAX_LEN], i, n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter %d elements of the array:\n", n);
  for(i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Given array is:\n");
  print_array(arr, n);

  merge_sort(arr, 0, n-1);

  printf("\nSorted array is:\n");
  print_array(arr, n);

  return 0;
}

void merge(int arr[], int low, int mid, int high) {
  int i, j, k;
  int n1 = mid - low + 1;
  int n2 = high - mid;

  int left[n1], right[n2];

  for (i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }
  for (j = 0; j < n2; j++) {
    right[j] = arr[mid + 1 + j];
  }

  i = 0; 
  j = 0; 
  k = low;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    }
    else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int low, int high) {
  if(low < high) {
    int mid = low + (high - low)/2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);

    merge(arr, low, mid, high);
  }
}

void print_array(int arr[], int len) {
  for(int i=0; i<len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}