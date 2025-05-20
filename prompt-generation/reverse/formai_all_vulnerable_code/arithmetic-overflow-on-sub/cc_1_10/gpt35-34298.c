//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a sorter that sorts random integers with hilarious prompts

// Create a function that takes an array of integers and its size,
// and sorts the integers in ascending order using the bubble sort algorithm
void bubble_sort(int arr[], int size) {
  int i, j, temp;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap the integers
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        // Give some hilarious prompts while swapping
        printf("Hold on to your pants! Swapping %d and %d...\n", arr[j], arr[j+1]);
        printf("Is this some kind of magic? %d and %d are swapping...\n", arr[j], arr[j+1]);
        printf("To infinity and beyond! %d is moving ahead of %d...\n", arr[j], arr[j+1]);
      }
    }
  }
}

// Create a main function that initializes an array of random integers and sorts them using bubble sort
int main() {
  int size, i;
  
  // Get the size of the array from the user
  printf("Hey, let's sort some integers!\n");
  printf("How many integers do you want to sort?\n");
  scanf("%d", &size);

  // Initialize the array with random integers
  int arr[size];
  srand(time(NULL));
  for (i = 0; i < size; i++) {
    arr[i] = rand() % 101;
  }

  // Sort the array using bubble sort
  bubble_sort(arr, size);
  
  // Print the sorted array
  printf("\nHere's the sorted array:\n");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}