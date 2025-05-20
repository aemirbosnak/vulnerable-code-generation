//FormAI DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr, *ptr_new, i, n;

   // Get the number of integers to be stored in the memory
   printf("Enter number of integers to be stored in memory: ");
   scanf("%d",&n);

   // Allocate the memory block dynamically
   ptr = (int*) malloc(n*sizeof(int));

   // Check if malloc was able to allocate the memory
   if(ptr == NULL) {
      printf("Memory allocation failed!");
      exit(0);
   }

   // Input elements into the array
   printf("Enter elements of the array:\n");
   for(i=0; i<n; i++) {
      scanf("%d", ptr+i);
   }

   // Display the elements of the array using pointer notation
   printf("The elements of the array are:\n");
   for(i=0; i<n; i++) {
      printf("%d ", *(ptr+i));
   }

   // Reallocate the memory block
   printf("\nEnter the new size of the array: ");
   scanf("%d",&n);

   ptr_new = realloc(ptr,n*sizeof(int));

   // Check if realloc was able to allocate the memory
   if(ptr_new == NULL) {
      printf("Memory reallocation failed!\n");
      exit(0);
   }

   // Input elements into the array
   printf("Enter new elements of the array:\n");
   for(i=0; i<n; i++) {
      scanf("%d", ptr_new+i);
   }

   // Display the elements of the array using pointer notation
   printf("The new elements of the array are:\n");
   for(i=0; i<n; i++) {
      printf("%d ", *(ptr_new+i));
   }

   // Free the dynamically allocated memory block
   free(ptr_new);

   return 0;
}