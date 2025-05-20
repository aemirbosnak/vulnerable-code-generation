//FormAI DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
int decentralizedSearch(int *, int, int);

// main function
int main() {
   int size, *arr, num, found;
   
   printf("Enter the size of array: ");
   scanf("%d", &size);
   arr = (int*)malloc(sizeof(int)*size);
   
   // fill array with random numbers
   srand(time(0)); // seed the rand function
   for(int i=0; i<size; i++) {
      arr[i] = rand() % 100;
   }
   
   printf("\nArray elements:\n");
   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   }
   
   printf("\nEnter the number you want to search: ");
   scanf("%d", &num);
   
   found = decentralizedSearch(arr, size, num);
   
   if(found == -1) {
      printf("\n%d is not present in the array.", num);
   }
   else {
      printf("\n%d is present in the array at index %d.", num, found);
   }
   
   free(arr);
   return 0;
}

// decentralized search function
int decentralizedSearch(int *arr, int size, int num) {
   int p = rand() % size;
   int q = rand() % size;
   
   if(arr[p] == num) {
      return p;
   }
   
   if(arr[q] == num) {
      return q;
   }
   
   if(p == q) { // to avoid infinite loop
      return -1;
   }
   
   int left = (p < q) ? p : q;
   int right = (p > q) ? p : q;
   
   for(int i=left+1; i<right; i++) {
      if(arr[i] == num) {
         return i;
      }
   }
   
   return -1;
}