//FormAI DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* Function to perform selection sort on an array */
void selectionSort(int arr[], int n) {
  int i, j, minIndex, temp;
  
  for (i = 0; i < n - 1; i++) {
    // Find the minimum element in the unsorted part of the array
    minIndex = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    
    // Swap the minimum element with the first element in the unsorted part of the array
    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

int main() {
  int i, n, *arr;
  
  // Get the size of the array from the user
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  
  // Allocate memory for the array
  arr = (int*)malloc(n * sizeof(int));
  
  // Get the elements of the array from the user
  printf("Enter the elements of the array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  // Sort the array using selection sort
  selectionSort(arr, n);
  
  // Print the sorted array
  printf("The array in sorted order is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  // Free the memory allocated for the array
  free(arr);
  
  return 0;
}