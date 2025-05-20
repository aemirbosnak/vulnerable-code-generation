//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to my Memory Management program!\n");
  
  //We'll be dealing with arrays, so let's define one and set its size.
  int size;
  printf("How big should the array be? ");
  scanf("%d", &size);
  
  //Allocating memory with malloc.
  int* myArray = (int*) malloc(size * sizeof(int));
  
  //Checking if malloc was successful.
  if (myArray == NULL) {
    printf("The allocation failed. Sorry about that!\n");
    return -1;
  }
  
  //Time to fill our array with some numbers.
  printf("What numbers do you want in the array? ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &myArray[i]);
  }
  
  //Let's see those numbers.
  printf("Here's what you entered: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");
  
  //Now we'll resize the array using realloc.
  int newSize;
  printf("What size should the array be now? ");
  scanf("%d", &newSize);
  
  myArray = (int*) realloc(myArray, newSize * sizeof(int));
  
  //Checking if realloc was successful.
  if (myArray == NULL) {
    printf("The reallocation failed. Sorry about that!\n");
    return -1;
  }
  
  //Fill our newly resized array with some more numbers.
  printf("What numbers do you want in the resized array? ");
  for (int i = size; i < newSize; i++) {
    scanf("%d", &myArray[i]);
  }
  
  //Let's see those numbers again.
  printf("Here's what you entered: ");
  for (int i = 0; i < newSize; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");
  
  //Cleaning up after ourselves.
  free(myArray);
  printf("Memory has been freed. Goodbye!\n");
  
  //All done!
  return 0;
}