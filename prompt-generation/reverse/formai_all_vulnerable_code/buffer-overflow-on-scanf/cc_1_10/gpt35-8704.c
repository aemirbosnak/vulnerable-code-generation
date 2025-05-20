//FormAI DATASET v1.0 Category: Educational ; Style: artistic
#include<stdio.h>

int main() {
  int size;
  printf("Please enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  
  printf("\nEnter the elements of the array:\n");
  
  // Taking the input of elements
  for(int i=0; i<size; i++) {
    printf("Element %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  
  // Displaying the original array
  printf("\nOriginal Array: ");
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  
  // Performing bubble sort operation
  for(int i=0; i<size-1; i++) {
    for(int j=0; j<size-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  // Displaying the sorted array
  printf("\n\nSorted Array using Bubble Sort: ");
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  
  // Finding the largest element of the array
  int max = arr[0];
  for(int i=1; i<size; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }
  
  // Displaying the largest element of the array
  printf("\n\nThe largest element of the array is: %d\n", max);
  
  return 0;
}