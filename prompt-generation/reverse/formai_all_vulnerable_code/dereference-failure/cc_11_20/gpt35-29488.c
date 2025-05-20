//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr1, *ptr2, *ptr3; // declare pointers
  int size1 = 5, size2 = 10, size3 = 15; // declare sizes of arrays

  // allocate memory for arrays using malloc
  ptr1 = (int*)malloc(size1 * sizeof(int));
  ptr2 = (int*)malloc(size2 * sizeof(int));
  ptr3 = (int*)malloc(size3 * sizeof(int));

  // check if memory allocation was successful
  if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) {
    printf("Memory allocation failed!\n"); // print error message if allocation failed
    exit(0);
  }

  // initialize values of arrays
  for (int i = 0; i < size1; i++) {
    ptr1[i] = i;
  }
  for (int i = 0; i < size2; i++) {
    ptr2[i] = i * i;
  }
  for (int i = 0; i < size3; i++) {
    ptr3[i] = i * i * i;
  }

  // print values of arrays
  printf("Contents of ptr1: ");
  for (int i = 0; i < size1; i++) {
    printf("%d ", ptr1[i]);
  }
  printf("\nContents of ptr2: ");
  for (int i = 0; i < size2; i++) {
    printf("%d ", ptr2[i]);
  }
  printf("\nContents of ptr3: ");
  for (int i = 0; i < size3; i++) {
    printf("%d ", ptr3[i]);
  }
  printf("\n");

  // re-allocate memory for ptr2 using realloc
  ptr2 = (int*)realloc(ptr2, size2 * 2 * sizeof(int));

  // check if memory re-allocation was successful
  if (ptr2 == NULL) {
    printf("Memory re-allocation failed!\n"); // print error message if re-allocation failed
    exit(0);
  }

  // set new values to the additional space allocated by realloc
  for (int i = size2; i < size2*2; i++) {
    ptr2[i] = i * i;
  }

  // print new values of ptr2
  printf("New contents of ptr2: ");
  for (int i = 0; i < size2*2; i++) {
    printf("%d ", ptr2[i]);
  }
  printf("\n");

  // free memory used by pointers
  free(ptr1);
  free(ptr2);
  free(ptr3);

  return 0;
}