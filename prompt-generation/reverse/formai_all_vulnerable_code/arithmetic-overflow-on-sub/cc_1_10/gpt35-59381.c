//FormAI DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

// Function to implement bubble sort
void bubbleSort(int arr[], int n) {
   int i, j;
   for(i = 0; i < n-1; i++) {
      // Last i elements are already sorted
      for(j = 0; j < n-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
         }
      }
   }
}

// Function to implement insertion sort
void insertionSort(int arr[], int n) {
   int i, key, j;
   for(i = 1; i < n; i++) {
      key = arr[i];
      j = i-1;

      // Move the elements that are greater than the key to the one position ahead
      while(j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = key;
   }
}

// Function to implement selection sort
void selectionSort(int arr[], int n) {
   int i, j, min_idx;
   for(i = 0; i < n-1; i++) {
      min_idx = i;
      for(j = i+1; j < n; j++) {
         if(arr[j] < arr[min_idx]) {
            min_idx = j;
         }
      }
      swap(&arr[min_idx], &arr[i]);
   }
}

int main() {
   int i, n;
   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter %d elements:\n", n);
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   // Sort using bubble sort
   printf("\nSorted using Bubble Sort:\n");
   bubbleSort(arr, n);
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   // Sort using insertion sort
   printf("\n\nSorted using Insertion Sort:\n");
   insertionSort(arr, n);
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   // Sort using selection sort
   printf("\n\nSorted using Selection Sort:\n");
   selectionSort(arr, n);
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}