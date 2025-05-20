//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Preamble for the Puzzle Sort
void swap(int *xp, int *yp);
void puzzleSort(int arr[], int low, int high);

int main(void) {
  int n, i;
  
  printf("Welcome to the Puzzle Sort program!\n");

  printf("How many numbers would you like to sort? ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter %d numbers separated by spaces: ", n);
  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("\nUnsorted Array: ");
  for (i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

  // Call to the Puzzle Sort function
  puzzleSort(arr, 0, n-1);

  printf("\nSorted Array: ");
  for (i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

// Puzzling function to perform the Puzzle Sort
void puzzleSort(int arr[], int low, int high){
  if (low < high) {
    int i, j, mid = low + (high - low) / 2;

    // Shuffle the puzzle pieces
    for (i = mid-1, j = mid+2; i >= low && j <= high; i--, j++) {
      swap(&arr[i], &arr[j]);
    }

    // Recursively sort the two halves
    puzzleSort(arr, low, mid-1);
    puzzleSort(arr, mid+1, high);
  }
}

// Helper function to swap two numbers
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}