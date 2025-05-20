//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Declare the array
int arr[MAX_SIZE];

// Declare the function to search for a number in the array
int search(int num) {
  // Iterate over the array
  for (int i = 0; i < MAX_SIZE; i++) {
    // If the number is found, return its index
    if (arr[i] == num) {
      return i;
    }
  }

  // If the number is not found, return -1
  return -1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the array with random numbers
  for (int i = 0; i < MAX_SIZE; i++) {
    arr[i] = rand() % 100;
  }

  // Print the array
  printf("The array is:\n");
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Get the number to search for from the user
  int num;
  printf("Enter the number to search for: ");
  scanf("%d", &num);

  // Search for the number in the array
  int index = search(num);

  // Print the result
  if (index == -1) {
    printf("The number was not found.\n");
  } else {
    printf("The number was found at index %d.\n", index);
  }

  return 0;
}