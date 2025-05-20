//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void funkyBubbleSort(int *arr, int size, int order);
void printArray(int *arr, int size);

int main() {
   int arraySize = 10;
   int *weirdArray = (int *)malloc(arraySize * sizeof(int));
   
   if (weirdArray == NULL) {
       printf("Memory allocation failed!\n");
       return 1; // Exit the program on allocation failure
   }

   printf("Enter %d integers:\n", arraySize);
   for (int i = 0; i < arraySize; i++) {
       printf("Element %d: ", i + 1);
       scanf("%d", &weirdArray[i]);
   }

   int sortOrder;
   printf("Enter 1 for Ascending, 2 for Descending sort: ");
   scanf("%d", &sortOrder);
   funkyBubbleSort(weirdArray, arraySize, sortOrder);

   printf("Sorted Array:\n");
   printArray(weirdArray, arraySize);

   free(weirdArray); // Free allocated memory
   return 0;
}

void funkyBubbleSort(int *arr, int size, int order) {
   for (int i = 0; i < size - 1; i++) {
       for (int j = 0; j < size - i - 1; j++) {
           // Check for ascending or descending order
           if ((order == 1 && arr[j] > arr[j + 1]) || (order == 2 && arr[j] < arr[j + 1])) {
               // Swap elements
               int temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
           }
       }
   }
}

void printArray(int *arr, int size) {
   for (int i = 0; i < size; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");
}