//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Defining the bucket sort function
void bucketSort(int array[], int size) {
  int i, j;
  int count[size];

  // Initializing the count array to 0
  for(i = 0; i < size; i++) {
    count[i] = 0;
  }

  // Counting the occurences of elements in the array
  for(i = 0; i < size; i++) {
    (count[array[i]])++;
  }

  // Sorting the array within the buckets
  for(i = 0, j = 0; i < size; i++) {
    for(; count[i] > 0; (count[i])--) {
      array[j++] = i;
    }
  }
}

// Main function to test the bucket sort algorithm
int main() {
  int i, arr_size;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &arr_size);

  int array[arr_size];
  printf("\nEnter the elements of the array:\n");

  for(i = 0; i < arr_size; i++) {
    scanf("%d", &array[i]);
  }

  // Calling the bucket sort function to sort the array
  bucketSort(array, arr_size);

  printf("\nSorted array is: ");
  
  for(i = 0; i < arr_size; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}