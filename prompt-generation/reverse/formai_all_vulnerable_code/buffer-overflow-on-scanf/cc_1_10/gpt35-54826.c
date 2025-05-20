//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr, *newPtr;
   int size, newSize;
   
   //ask user for initial array size
   printf("Hey there! Let's create our own array. What should be the initial size of the array: ");
   scanf("%d", &size);

   //allocate memory for array
   ptr = (int*) malloc(size * sizeof(int));
   
   if(ptr == NULL) {
      printf("Oops! Memory allocation failed. :(\n");
      return 0;
   }

   //initialize array values
   for(int i=0; i<size; i++){
     ptr[i] = i+1;
   }

   //display array
   printf("\nHere's your array: ");
   for(int i=0; i<size; i++){
     printf("%d ", ptr[i]);
   }

   //ask user for new array size
   printf("\n\nThat looks good! Now, what should be the new size of the array: ");
   scanf("%d", &newSize);

   //reallocate memory for array with new size
   newPtr = (int*) realloc(ptr, newSize * sizeof(int));
   
   if(newPtr == NULL) {
      printf("Oops! Memory reallocation failed. :(\n");
      return 0;
   }

   //initialize new array values
   for(int i=size; i<newSize; i++){
     newPtr[i] = i+1;
   }

   //display new array
   printf("\nHere's the new array: ");
   for(int i=0; i<newSize; i++){
     printf("%d ", newPtr[i]);
   }

   //free memory
   free(newPtr);

   printf("\n\nYay! We successfully created a memory managed array! :)\n");
   return 0;
}