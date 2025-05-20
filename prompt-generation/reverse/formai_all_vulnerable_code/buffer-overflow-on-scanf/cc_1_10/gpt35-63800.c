//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to my unique C Memory management program!\n");

  // Allocating memory for an array of integers with the help of malloc() function
  int *ptr;
  ptr = (int*)malloc(5*sizeof(int)); // Allocating memory for 5 integers

  if(ptr == NULL) {
    printf("Memory allocation failed. Exiting the program...\n");
    exit(0);
  }

  printf("Memory allocation for 5 integers successful. Enter the values of the array:\n");

  // Taking user input to fill the array with values
  for(int i=0; i<5; i++) {
    scanf("%d", &ptr[i]);
  }

  // Displaying the elements of the array
  printf("Array elements entered by the user:\n");
  for(int i=0; i<5; i++) {
    printf("%d\n", ptr[i]);
  }

  // Reallocating memory for the array with the help of realloc() function
  int *ptr_new;
  ptr_new = (int*)realloc(ptr, 10*sizeof(int)); // Resizing the array to fit 10 integers

  if(ptr_new == NULL) {
    printf("Memory reallocation failed. Exiting the program...\n");
    free(ptr); // Freeing up the previously allocated memory before exiting
    exit(0);
  }

  printf("Memory reallocation for 5 more integers successful. Enter the values of the expanded array:\n");

  // Taking user input to fill the expanded array with values
  for(int i=5; i<10; i++) {
    scanf("%d", &ptr_new[i]);
  }

  // Displaying the elements of the expanded array
  printf("Expanded array elements entered by the user:\n");
  for(int i=0; i<10; i++) {
    printf("%d\n", ptr_new[i]);
  }

  // Freeing up the allocated memory before exiting the program
  free(ptr_new);
  printf("Memory has been freed up successfully. Exiting the program...\n");

  return 0;
}